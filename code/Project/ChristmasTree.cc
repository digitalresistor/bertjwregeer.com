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
	Project * myProject = new Project("Christmas Tree");
	
	myProject->heading(1, "Overview");
	myProject->paragraph("A team of students that are collectively known as the 244'ers by the room number they "
			     "hang out in came together and modified the Christmas Tree that {UAT}[http://uat.edu/] had placed in the "
			     "commons area at UAT. We provided an online URL where people could go and turn the tree "
			     "on and off or scroll the tree from top to bottom.");
			
	myProject->heading(1, "Hardware");
	myProject->paragraph("The hardware we used was simple. The tree was purchased and put up by UAT. This was a "
			     "classic fake Christmas tree you would find at any major retailer during the Christmas "
			     "season. This mean that it was built in layers, and each layer had it's own ring of "
			     "lights, these were all daisy chained together using standard wall plugs. We went in and "
			     "just put in extension cords for each of the different layers, so that now each layer "
			     "instead of being daisy chained to the previous was now on its own separate extension cord.");
			
	myProject->paragraph("Professor Clarke had a ready built box which contained standard solid state relays. This "
			     "meant that we could safely using a micro controller switch on and off 120 volt AC power. "
			     "This was built into one of the standard blue boxes also used in the construction for "
			     "housing, with the only thing being exposed being six wall plugs on the front face, each "
			     "of which could be individually turned on and off.");
			
	myProject->paragraph("As a micro controller we used the BASIC Stamp, mainly for its ease of programming, and the "
			     "fact that we had assumed it would be adequate for the job. Along with that we used a PINK "
			     "(Parallax Internet Netburner Kit) which gave us a small embedded web server. The PINK is "
			     "able to communicate over a serial connection to report certain form changes.");
			
	myProject->paragraph("In the end the following hardware was used:\n"
			     "- {BASIC Stamp Controller}[http://www.parallax.com/tabid/295/Default.aspx]\n"
			     "- {PINK (Parallax Internet Netburner Kit)}[http://www.parallax.com/Store/Accessories/Communication/tabid/161/ProductID/40/CategoryID/36/List/0/Level/a/Default.aspx?SortField=ProductName,ProductName]\n"
			     "- {6 solid state relays}[http://efx-tek.com/topics/crydom.html]\n"
			     "- Extension cords\n"
			     "- One unsuspecting tree");
	
	myProject->heading(2, "Simple Website");
	myProject->paragraph("The PINK has a minimal amount of storage on-board which allows you to put small web pages "
			     "on it. I ended up creating a quick and dirty small website that allowed the viewer to see "
			     "what state the tree was currently in, and since we had two web cameras on campus, I "
			     "embedded those on the web site as well so that the viewer would be able to see in real "
			     "time what their changes had done to the Christmas tree.");
	
	myProject->heading(1, "Hack was Hacked");
	myProject->paragraph("Since the website was set up with a small form that allowed the browser to POST to the web "
			     "server, it was rather simple to automate the turning on and off of the Christmas tree. We "
			     "had clever people that were sending us messages over the tree by turning it on and off in "
			     "morse code patterns, as well as just trying to turn it on and off as fast as they were able "
			     "to send data to it (which annoyed other users, c'est la vie!). The best hack was when "
			     "someone flashed S.O.S. on the tree. It was a simple hack, but the one that stood out the "
			     "most to me!");
			
	myProject->heading(1, "Aftermath");
	myProject->paragraph("This was my very first project when I joined UAT, and it was done just to drum up interest "
	                     "and to do something interesting for the campus as a whole. I had stuck the Google Analytics "
	                     "code on the web pages, so we had a way to find out how many people visited the tree, the "
	                     "stats are as follows:\n"
			     "- Average: 4.76 Pages/Visitor\n"
			     "- Unique Visits: 4,323\n"
			     "- Pageviews: 20,577");

	// Output the project!
	std::cout << *myProject << std::flush;
	
	// Wait on user input before we blindly proceed ahead
	std::cout << "Press any key to return back to the Projects menu ...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// Re-run the Projects application to let the visitor view more projects: 
	execl("./Projects", "{Projects}[../Projects.html]", (char *)0);
	return 0;
}