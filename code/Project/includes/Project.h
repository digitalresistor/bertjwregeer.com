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

#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <iostream>
#include <string>
#include <vector>

enum Type { Heading, Paragraph };

typedef struct value_container {
	Type		curType;
	int		level;
	std::string * 	text;
} paper_body;

class Project  {
	public:
		Project (std::string name) : _name(name) {
			// We want the first thing to be the name of the project!
			heading(0, _name);
		}
		~Project () {
		}
		
		void paragraph(std::string text) {
			std::string * _text = new std::string(text);
			paper_body * _paragraph = new paper_body;
			
			_paragraph->curType = Paragraph;
			_paragraph->level   = 0;
			_paragraph->text    = _text;
			
			_project.push_back(_paragraph);
		}
		
		void heading(int level, std::string text) {
			std::string * _text = new std::string(text);
			paper_body * _heading = new paper_body;
			
			_heading->curType   = Heading;
			_heading->level     = level;
			_heading->text      = _text;
			
			_project.push_back(_heading);
		}
		
		friend std::ostream& operator<< (std::ostream& o, Project& project);
		
	private:
		std::string _name;
		std::vector<paper_body *> _project;
};

std::ostream& operator<< (std::ostream& o, Project& project) {
	for(std::vector<paper_body *>::iterator a = project._project.begin(), b = project._project.end(); 
	    a!=b; a++) {
		paper_body * body;
		body = (*a);
		
		if (body->curType == Heading) {
			for (int i = -1; i < body->level; i++) {
				o << "=";
			}
			
			o << " " << *(body->text) << " ";
			
			for (int i = -1; i < body->level; i++) {
				std::cout << "=";
			}
			
			o << std::endl << std::endl;
		}
		else {
			o << *(body->text) << std::endl << std::endl;
		}
	}
	return o;
}

#endif /* _PROJECT_H_ */
