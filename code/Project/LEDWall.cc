/**
 * Copyright (c) 2008 {Bert JW Regeer}[http://bertjwregeer.com];
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

#include <iostream>
#include <unistd.h>
#include "includes/Project.h"

int main () {
	Project * myProject = new Project("LED Whiteboard");
	
	myProject->heading(1, "Concept");
	myProject->paragraph("UAT wanted to provide a location for UAT students to show off their art skills, to "
			     "write down project ideas and to provide a board for poetry and various other literary "
			     "works. The idea was to create a backlit whiteboard. The idea was kicked around UAT "
			     "until it reached Professor Clarke, who then suggested that instead of just backlighting "
			     "the board, the board should have LED's that can be individually controlled to be on or "
			     "off. We ended up using an 8 by 26 array of blue LED's spaced 6 inches apart, on a 4 feet "
			     "by 28 feet wall.");

	myProject->heading(1, "Construction");
	myProject->paragraph("The 'wall' is made out of two separate layers. The top most layer is diffused acrylic, "
			     "which helps diffuse the light. The second layer underneath that is thick sheet of "
			     "plastic with holes drilled 6 inches apart. This allowed us to put the LED into the hole "
			     "and glue it down. From there we ran wires between the different LED's to provide one "
			     "common ground per column, and we ran a common anode per row. This allows us to turn on "
			     "a single LED by grounding a column and providing a current to a row.");
	
	myProject->heading(1, "Hardware");
	myProject->paragraph("The LED wall is being run off a standard Parallax SX28, some transistors for the rows "
			     "since they had to provide a massive amount of power, and two MAX6979 to sink the columns. "
			     "Currently the project is still sitting on a breadboard as we have not yet had the time to "
			     "print a custom board, nor has it been necessary.");
	
	myProject->paragraph("Since the MAX6979's are shift registers. Shift registers allows us to clock data into "
			     "the chip at whatever speed we desire. It is an extremely simple serial communication "
			     "protocol. So we only have to provide a CLK signal, a DIN for data in, a LE which is a "
			     "latch enable, and OE which is the output enable. Since it is a shift register and they "
			     "can be daisy chained, we can control all of the columns using just 4 control lines from "
			     "the SX28.");

	myProject->paragraph("For the control of the rows we used a demux, this way we only had to use 4 control lines "
			     "on the SX28. It sends a binary coded decimal to the demux to select which row we would "
			     "like to provide power on.");
			
	myProject->paragraph("In total we used just 8 control lines on the SX28 leaving the rest of them wide open for "
			     "future add-ons.");
			
	myProject->paragraph("The following hardware was used:\n\n"
			     " - Parallax SX28\n"
		 	     " - demux\n"
			     " - Transistors\n"
			     " - MAX6979\n"
			     "Along with plenty of LED's!");
			
	myProject->heading(1, "Future");
	myProject->paragraph("Currently it is running Conway's game of life, and the board provides its function but "
			     "at the same time it does not allow the students to interact with it in a new and novel "
			     "way. The original idea that was presented was a serial port that was on the outside that "
			     "then allowed students to walk up to it and program the LED's to flash various different "
			     "shapes/patterns/pieces of art.");

	// Output the project!
	std::cout << *myProject << std::flush;
	
	// Wait on user input before we blindly proceed ahead
	std::cout << "Press any key to return back to the Projects menu ...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// Re-run the Projects application to let the visitor view more projects: 
	execl("./Projects", "{Projects}[../Projects.html]", (char *)0);
	return 0;
}