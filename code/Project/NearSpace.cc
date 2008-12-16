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
	Project * myProject = new Project("Near Space");
	
	myProject->heading(1, "Overview");
	myProject->paragraph("Near Space was both a project and an official class at UAT (SCI388: Special topics in "
			     "science: Near Space). The class consisted of 15 people that were picked by Ryan Clarke, "
			     "and upon passing an entrance exam put into three different groups; engineering, science "
			     "and logistics. The goal of the class was to send a balloon to 90,000 ft and to "
			     "successfully recover the payload once the balloon burst. Our first launch Connery-1 went "
			     "off without any major issues, and we completed our goal. We reached 93,000 ft and "
			     "recovered the payload along with the data it had captured.");
	
	myProject->heading(1, "Teams");
	myProject->heading(2, "Engineering");
	myProject->paragraph("The engineering teams primary focus was to create the payload box, along with the "
			     "structural support to hold all of the equipment in place. The engineering team was also "
			     "in charge of designing and building a way to fill the latex balloon, building the "
			     "flight computer, and radio. The engineering team also had to write the procedures for "
			     "the launch, and test the various parts of the systems to make sure that it would "
			     "survive the return trip from near space.");
	
	myProject->heading(2, "Science");
	myProject->paragraph("The science teams primary focus was science experiments that were to be performed while "
			     "ascending and descending. The science team is also in charge of interpreting any data "
			     "that did come back down, and in general anything related to science.");
	
	myProject->heading(2, "Logistics");
	myProject->paragraph("The logistics teams primary focus was ordering parts, and making sure they arrived on "
			     "time, they were also in charge of making sure we were following all federal regulations "
			     "and following the letter of the law. This team was also in charge of finding the "
			     "appropriate launch sites, and predicting where the near space payload would fall back to "
			     "earth so that we may recover it.");
			
	myProject->heading(1, "Launches");
	myProject->heading(2, "CONNERY-1");
	myProject->paragraph("CONNERY-1 was the first near space balloon we launched, it had onboard a BASIC Stamp 2, "
			    "GPS, Radio, a photo-camera, and a video camera. We launched at 0640 mountain standard "
			    "time, and retrieved the payload a few hours later. We hit an altitude of 92,999 ft. It "
			    "was a huge success, and we were extremely happy. The pictures the payload took were "
			    "absolutely stunning, and awe inspiring. We tracked the balloon using the APRS network.");
	
	myProject->heading(2, "CONNERY-2");
	myProject->paragraph("CONNERY-2 was a huge success, we launched our second balloon with some modifications, "
			     "we decided to take more pictures more often, and we also modified the flight computer "
			     "to log more GPS strings. We also launched right before sunset so we were able to "
			     "capture many more awesome pictures. The balloon was once again tracked using radio "
			     "signals sent to the national APRS frequency.");
			
	myProject->heading(1, "Data logging and parsing");
	myProject->paragraph("The Near Space payload consisted of a data logger that was logging data to an SD card "
			     "a format that we well defined. When the data came back down to earth we needed a way "
			     "to parse the data so that we could graph it using Excel and or other tools. I wrote "
			     "a simple parser that parses the different format versions that we already have by "
			     "automatically detecting in what format the file is. It then parses the data and outputs "
			     "a comma separated file (csv).\n\n"
			     "{View code}[http://nearspace.0x58.com/launches/Tools/ParseFCU.html] / {Download code}[http://nearspace.0x58.com/launches/Tools/ParseFCU.cc]");

	myProject->heading(1, "Documentation");
	myProject->paragraph("For the project we decided from the start that we needed a good place to store "
			     "information that would be accessible by the outside world, as well as to anyone that "
			     "wanted to provide their insight. We also wanted to provide a way for people to track "
			     "our progress and to find out more information about the project. We set up a {near}[http://nearspace.0x58.com/] "
			     "{space wiki}[http://nearspace.0x58.com/], which contains most of the information about the project. Unfortunately "
			     "not everyone that was on the project has wiki knowledge so documentation is "
			     "unfortunately lacking somewhat.");
	
	myProject->heading(1, "Future");
	myProject->paragraph("It is our hope as a team that UAT will continue to do near space balloon launches, "
			     "gathering more pictures in the process, along with various science experiments. "
			     "There is just something to being able to say that you were part of a team that "
			     "helped launch a balloon to 93,000 ft.");

	// Output the project!
	std::cout << *myProject << std::flush;
	
	// Wait on user input before we blindly proceed ahead
	std::cout << "Press any key to return back to the Projects menu ...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// Re-run the Projects application to let the visitor view more projects: 
	execl("./Projects", "{Projects}[../Projects.html]", (char *)0);
	return 0;
}