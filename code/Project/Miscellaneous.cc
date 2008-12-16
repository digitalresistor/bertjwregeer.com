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
	Project * myProject = new Project("Miscellaneous Projects and Code");
	
	myProject->paragraph("This page is dedicated to the small pieces of code that I have written over the years "
			     "along with a description of what it is about. Please be aware that some of the projects "
			     "here are still on-going and some of it was just not big enough to have its own project "
			     "page.");
	
	myProject->heading(1, "Completed");
	
	myProject->heading(2, "SX28 Assembly Boe-Bot");
	myProject->paragraph("The Boe-Bot from Parallax is a BASIC Stamp device, it is a robot that can be programmed "
			     "using the PBASIC programming language. For one of our classes we were required to write "
			     "a simple Boe-Bot like program in assembly which used whiskers and light sensors to do "
			     "obstacle avoidance.\n\n"
			     "{Download code}[./code/boebot.src]");
			
	myProject->heading(2, "Intel Assembly");
	myProject->paragraph("UAT was offering a course in Intel assembly, and for the class we had to write our "
			     "programs in a mixture of both C and inline assembly. However the instructor also was "
			     "willing to let us write the programs in pure Intel assembly. At the time I really wanted "
			     "to learn about Intel assembly and thus downloaded and compiled nasm for FreeBSD and "
			     "learned how to interact with the kernel (to write messages to stdout) how the stack was "
			     "created, how function calls interacted with each other.");
	
	myProject->heading(3, "addnumbers.asm");
	myProject->paragraph("Using the knowledge I created a program that is capable of adding two numbers together "
			     "if they are passed as the first and second argument. This code still has the unfortunate "
			     "side effect, that as soon as the numbers add up to anything bigger than the default "
			     "integer size (4 bytes, 32 bits) it will give a wrong answer.\n\n"
			     "{Download code}[./code/addnumbers.asm]");
	
	myProject->heading(3, "hex2binary.asm");
	myProject->paragraph("The class was also required to write a piece of code that converted a two's compliment "
			     "hex value to binary. This was also an interesting challenge, and I found that when I "
			     "allocated memory in the .bss of the program, depending on how the OS laid out the stack "
			     "in memory the input of the program could be much bigger than it was originally intended "
			     "to be.\n\n"
			     "{Download code}[./code/converthextobinary.asm]");
			
	myProject->heading(1, "Still Going");
	myProject->paragraph("These are the smaller projects that are still going on at the moment and that are not yet"
			     "completed. Please be aware of this when taking a look, the code will be rough around the "
			     "edges.");
			
	myProject->heading(2, "bsdPanel");
	myProject->paragraph("bsdPanel is a personal project I started in 2003. The idea was to write a daemon back-end "
			     "with authentication that would allow any frontend that spoke a certain protocol to connect "
			     "and manage the server. For example, creating new user accounts, adding email accounts and "
			     "creating new FTP users. The thought behind it was that since the interface was abstracted "
			     "away the administrator would be able to pick and choose the various pieces of software and "
			     "interchange them without having to re-write the scripts to manage the software as bsdPanel's "
			     "daemon would do this for him.");
			
	myProject->paragraph("The project is not dead, however progress has been very slow. The most active part of the "
			     "project right now is the 0x58-unix part which is going to be a C++ wrapper around the "
			     "various system calls that exist.\n\n"
			     "{Project homepage}[http://trac.svn.0x58.com/bsdpanel/]");

	// Output the project!
	std::cout << *myProject << std::flush;
	
	// Wait on user input before we blindly proceed ahead
	std::cout << "Press any key to return back to the Projects menu ...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// Re-run the Projects application to let the visitor view more projects: 
	execl("./Projects", "{Projects}[../Projects.html]", (char *)0);
	return 0;
}