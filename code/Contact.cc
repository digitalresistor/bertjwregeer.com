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
	std::cout << "Contacting Bert"		<< std::endl;
	std::cout << 				   std::endl;
	std::cout << "Email: "			<< std::endl;
	std::cout << "1. {bertjw@regeer.org}[mailto:bertjw@regeer.org]"	<< std::endl;
	std::cout << "2. {berregee@uat.edu}[mailto:berregee@uat.edu]"	<< std::endl;
	std::cout <<                               std::endl;
	std::cout << "Phone: "			<< std::endl;
	std::cout << "1. +1-973-342-4882"	<< std::endl;
	std::cout << 				   std::endl;
	std::cout << "Google chat/Jabber: "	<< std::endl;
	std::cout << "1. bertjw@regeer.org"	<< std::endl;
	std::cout << 				   std::endl;
	std::cout << "Contact via email is prefered." << std::endl;

	// Re-run the menu application to give the visitor more selections: 
	execl("./Main", "{Main}[./index.html]", (char *)0);
	return 0;
}