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

#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>

typedef struct education_container
{
        std::string schoolname;
        std::string degree;
        std::string major;
} Education;

class Person  {
        public:
                Person (std::string * name, std::string * biography, Education * education) : _name(name), _biography(biography), _education(education) { };
                ~Person () {
                        delete _name;
                        delete _biography;
                        delete _education;
                };
        
                friend std::ostream& operator<< (std::ostream& o, const Person& person);

        private:
                std::string * _name;
                std::string * _biography;
                Education   * _education;
};

std::ostream& operator<< (std::ostream& o, const Person& person) {
        o << "Name: " << *(person._name) << std::endl;
        o << "Biography: " << std::endl << *(person._biography) << std::endl;
        o << "Education: " << std::endl;
        o << "\tSchool: "  << (*(person._education)).schoolname << std::endl;
        o << "\tDegree: "  << (*(person._education)).degree << std::endl;
        o << "\tMajor: "   << (*(person._education)).major << std::endl;
        
        return o;
}

#endif /* _PERSON_H_ */
