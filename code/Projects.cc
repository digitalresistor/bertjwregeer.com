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
#include "includes/Project_desc.h"

int main () {
	Project_list myProjects;
	Project_desc * project;
	
	project = new Project_desc(
			new std::string("{NearSpace}[./Project/NearSpace.html]"),
			new std::string("Professor Ryan Clarke had seen a presentation by L. Paul Verhage at Parallax "
					"about Near Space balloons. Ryan had always wanted to launch a near space "
					"balloon and created a special topics class at UAT to do so. He selected 15 "
					"students to be part of the class, with the goal of getting a payload of 12 "
					"pounds up to at least 90,000 ft. It was a great success, our first balloon "
					"hit 92,999 ft. Our second balloon was successfully launched and retrieved!"));
	myProjects.add_project(project);
	
	project = new Project_desc(
			new std::string("{LEDWall}[./Project/LEDWall.html]"),
			new std::string("The idea was brought up at UAT to have a backlit 'whiteboard' which would "
					"allow students to post their ideas, drawings and other thoughts. The "
					"project was eventually changed so that it would be LED backlit in a grid. "
					"We used blue LED's in a 8 by 26 grid. We then also wrote the code for an "
					"SX28 microprocessor to have the LED wall play the game of life."));
	myProjects.add_project(project);
	
	project = new Project_desc(
			new std::string("{ChristmasTree}[./Project/ChristmasTree.html]"),
			new std::string("During the Christmas season UAT put a Christmas tree in the commons area which "
					"is where all of the computers are located, where it is visible throughout most "
					"of the schools ground floor. A group of students modified the Christmas tree "
					"to be accessible from the internet using a BASIC Stamp and a PINK. After the "
					"modification the Christmas tree was able to be turned on or off from the web."));
	myProjects.add_project(project);
	
	project = new Project_desc(
			new std::string("{Miscellaneous}[./Project/Miscellaneous.html]"),
			new std::string("These are the projects that were done for classes and or are not as big as the "
					"ones above. This includes many pieces of sample code that I have written along "
					"with descriptions of what they do."));
	myProjects.add_project(project);
	
	myProjects.list_projects();

	// Re-run the menu application to give the visitor more selections: 
	execl("./Main", "{Main}[./index.html]", (char *)0);
        return 0;
}