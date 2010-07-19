/**
 * Copyright (c) 2008 {Bert JW Regeer}[http://old.bertjwregeer.com];
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
#include "includes/Person.h"

int main () {
	std::string * name, * biography;
	Education * education;
	Person * Bert;

	name = new std::string("Bert JW Regeer");
	biography = new std::string(
		"I am a current student at the {University of Advancing Technology}[http://uat.edu] studying software engineering. I am "
		"currently nearing completion of my degree with only two more semesters left at UAT.\r\n"
		
		"I am a highly motivated individual, who enjoys working with technology. My strongest points are my "
		"expertise in UNIX/Linux server administration and programming for those platforms. I enjoy working "
		"with open source software and writing my own software. I am currently part of several {projects}[./Projects.html] at "
		"UAT and I am also working on several of my own projects.\r\n"
		
		"I participate in various clubs and groups around school and am active in the Network Security "
		"scene, having gone to both Black Hat and DefCon. I also enjoy going to the lesser known Net sec "
		"groups. HATS is local to UAT, and ToorCon which is held in San Diego.\r\n"
		
		"I am from the Netherlands, and as such bring a unique perspective to any team. Having lived in and "
		"travelled to many countries I am very open to new cultures and ideas. I have resided in the US for "
		"the last 8 years, and  during that time have met many extra-ordinary and awesome people that I have "
		"had the pleasure of working with."
		);

	education = new Education;
	education->schoolname = "{University of Advancing Technology}[http://uat.edu]";
	education->degree     = "Bachelor of Science: Software Engineering";
	education->major      = "Programming";

	Bert = new Person(name, biography, education);

	// Print the results to the screen
	std::cout << (*Bert) << std::endl << std::flush;

	// Re-run the menu application to give the visitor more selections: 
	execl("./Main", "{Main}[./index.html]", (char *)0);
	return 0;
}