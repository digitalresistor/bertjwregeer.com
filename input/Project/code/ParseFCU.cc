/**
 * Copyright (c) 2008 Bert JW Regeer <xistence@0x58.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
**/

/*
   CONNERY-1 Data looks as follows:

	<4 bytes> == last valid packet written
	![adc]<2 bytes>x8+1[/adc]($GPRMC)?#
	
	start byte: !
	stop byte: #
	
	GPS strings may be absent and still be valid data!
	
	version: 1

   CONNERY-2 Data looks as follows:
	<4 bytes> == last valid packet written
	!<0x82>[adc]<2 bytes>x8[/adc]($GPGGA ... $PGRMV)?#<0x83>

	start bytes: !<0x82>
	stop bytes: #<0x83>
	
	GPS strings may be absent and still be valid data!
	
	version: 2
	
    CONNERY-x Data looks as follows
	<4 bytes> == last valid packet written
	<1 byte>  == log file version number
	
	!<0x82>[adc]<2 bytes>x8[/adc](GPS string)?#<0x83>
	
	version: x
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string>

enum State { Snone, Sstart, Sadc, Sgps_search, Sgps, Send };

void read_adc(std::ifstream &input, std::ofstream &output, unsigned short count) {
	unsigned int   character = 0;
	unsigned short adct = 0;
	
	while (count > adct) {
		// Clear the character
		character = 0;
		
		input.read(reinterpret_cast<char *>(&character), 1);
		character = character << 8;
		input.read(reinterpret_cast<char *>(&character), 1);
		
		output << character << ",";
		adct++;
	}
}

void parse_version_1(std::ifstream &input, std::ofstream &output, long long lastgood) {
	std::cerr << "\tParsing version: 1" << std::endl;
	
	unsigned int character = 0;
	State state = Snone;
	
	while ((lastgood > input.tellg())) {
		character = 0;
		input.read(reinterpret_cast<char *>(&character), 1);
		
		if (state == Snone) {
			// Check if the character is the start bytes
			if (character == '!') {
				state = Sadc;
			}
			else {
				continue;
			}
		}
		if (state == Sadc) {
			// Okay, so we now need to read ADC values (8 ADC channels total)
			read_adc(input, output, 8);
			
			// In the CONNERY-1 data structure there is one extra byte accidently written, we skip over it.
			input.seekg(1, std::ifstream::cur);
			// Next we want to look for GPS data
			state = Sgps_search;
		}
		if (state == Sgps_search) {
			if (character == '#') {
				input.seekg(-1, std::ifstream::cur);
				state = Send;
				continue;
			}
			if (character == '$') {
				state = Sgps;
			} else {
				continue;
			}
		}
		if (state == Sgps) {
			if (character == '\n' || character == '\r') {
				continue;
			}
			
			if (character == '#') {
				state = Send;
			} else {
				if (character == '*') {
					output << ",";
				}
				
				output << static_cast<char>(character);
				continue;
			}
		}
		if (state == Send ) {
			output << std::endl;
			state = Snone;
			continue;
		}
	}
}

void parse_version_2(std::ifstream &input, std::ofstream &output, long long lastgood) {
	std::cerr << "\tParsing version: 2" << std::endl;
	
	unsigned int character = 0;
	State state = Snone;
	bool secondGPS = false;
	
	while ((lastgood > input.tellg())) {
		character = 0;
		input.read(reinterpret_cast<char *>(&character), 1);
		
		if (state == Snone) {
			// Check if the character is the start bytes
			if (character == '!') {
				state = Sstart;
				continue;
			}
			else {
				continue;
			}
		}
		
		if (state == Sstart) {
			if (character == 0x82) {
				state = Sadc;
			} else {
				continue;
			}
		}
		
		if (state == Sadc) {
			// Okay, so we now need to read ADC values (8 ADC channels total)
			read_adc(input, output, 8);
			
			// Next we want to look for GPS data
			state = Sgps_search;
		}
		if (state == Sgps_search) {
			if (character == '#') {
				state = Send;
				continue;
			}
			if (character == '$') {
				state = Sgps;
			} else {
				continue;
			}
		}
		if (state == Sgps) {
			if (character == '\n' || character == '\r') {
				continue;
			}
			
			if (character == '#') {
				state = Send;
				continue;
			} else {
				if (character == '$' || secondGPS == true) {
					if (secondGPS && character == '$') {
						output << ",";
					} else {
						secondGPS = true;
					}
				}
				
				if (character == '*') {
					output << ",";
				}
					
				output << static_cast<char>(character);
				continue;
			}
		}
		if (state == Send ) {
			if (character == 0x83) {
				output << std::endl;
				state = Snone;
				secondGPS = false;
				continue;
			} else {
				continue;
			}
		}
	}
}

// To add more version parsers create the function above, then add another entry to the version_parser array. 0 offset.
// so version 1 is actually at array offset 0. Beware.
struct versions { 
	void (* parse)(std::ifstream &input, std::ofstream &output, long long lastgood); 
} version_parser[] = { 
	{ parse_version_1 }, 
	{ parse_version_2 }
};


int check_version(std::ifstream &input) {
	// Scan for version
	unsigned int version = 0;
	unsigned char character = 0;
	
	input.read(reinterpret_cast<char *>(&character), 1);
	
	if (character == '!') {
		version = 1;
		input.read(reinterpret_cast<char *>(&character), 1);
		if (character == 0x82) {
			version = 2;
		}
		
		// We want to seek backwards to make sure that the parser starts parsing at the right location
		input.seekg(-2, std::ifstream::cur);
		
	} else {
		version = character;
	}
	
	return version;
}

int main(int argc, char* argv[]) {

	// Check if we have at least three arguments
	if (argc < 3) {
		std::cerr << "Usage: " << std::endl << "\t" << argv[0] << " <input file> <output file>" << std::endl;
		return -1;
	}
	
	std::cerr << "Near Space Flight Computer parser" << std::endl;
	
	std::ifstream input;
	std::ofstream output;
	
	// Open the input file as a binary stream
	input.open(argv[1], std::ifstream::binary);
	
	// Open the output file as a standard text file, and truncate it
	output.open(argv[2], std::ofstream::out | std::ofstream::trunc);
	
	long long filelength = 0;
	
	input.seekg(0, std::ifstream::end);
	filelength = input.tellg();
	input.seekg(0, std::ifstream::beg);
	
	long long lastgood = 0;
	
	for (int i = 4; i > 0; i--) {
		lastgood = lastgood << 8;
		input.read(reinterpret_cast<char *>(&lastgood), 1);
	}
	
	std::cerr << "\tFile total length: 0x" << std::hex << filelength << std::endl;
	std::cerr << "\tLast good write at: 0x" << std::hex << lastgood << std::endl;
	
	// Check the file structure
	int fileversion = check_version(input);
	
	std::cerr << "\tFile version: " << fileversion << std::endl;
	
	version_parser[fileversion - 1].parse(input, output, lastgood);
	
	std::cerr << "\tProcessed 0x" << std::hex << input.tellg() << " bytes" << std::endl;
	std::cerr << "\tUn-processed: 0x" << std::hex << filelength - input.tellg() << " bytes" << std::endl;
}
