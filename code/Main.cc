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

int main () {
	std::cout << "Welcome to Berts website" << std::endl;
	std::cout << "\t1. {About_me}[./About_me.html]" << std::endl;
	std::cout << "\t2. {Projects}[./Projects.html]" << std::endl;
	std::cout << "\t3. {Resume}[./Resume.html]" << std::endl;
	std::cout << "\t4. {Contact}[./Contact.html]" << std::endl;

	int input;

	std::cout << "Enter your selection: " << std::flush;
        std::cin >> input;

        // We assume that execl will not fail!
	switch (input) {
	        case 1: execl("./About_me", "{About_me}[./About_me.html]", (char *)0);
	        case 2: execl("./Projects", "{Projects}[./Projects.html]", (char *)0); 
	        case 3: execl("./Resume",   "{Resume}[./Resume.html]", (char *)0);
	        case 4: execl("./Contact",  "{Contact}[./Contact.html]", (char *)0);
	        default:
                        std::cerr << "Bad selection" << std::endl;
                        return 1;
	}

        return 0;
}