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
#include "includes/Person.h"

int main () {
        std::string * name, * biography;
        Education * education;
        Person * Bert;
        
        name = new std::string("Bert JW Regeer");
        // TODO: Actually write something about yourself!
        biography = new std::string("Here comes the entire biography for "
                    "Bert JW Regeer, as of right now it is not much but "
                    "it will do for now. More to come later, keep "
                    "watching!");
                    
        education = new Education;
        education->schoolname = "University of Advancing Technology";
        education->degree     = "Bachelor of Science: Software Engineering";
        education->major      = "Programming";
        
        Bert = new Person(name, biography, education);

        // Print the results to the screen
        
        std::cout << (*Bert) << std::endl << std::flush;
        
        delete Bert;

	// Re-run the menu application to give the visitor more selections: 
	execl("./Main", "{Main}[./index.html]", (char *)0);
        return 0;
}