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

#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <iostream>
#include <string>
#include <vector>

class Project_desc  {
	public:
		Project_desc (std::string * name, std::string * description) 
			: _name(name), _description(description) { };
			
		~Project_desc () {
			delete _name;
			delete _description;
		};
		
		// Function to execute the binary when the user selects it
		void viewFull() {
			char **argv = 0;
			argv = new char*[3];
			
			// We first set the correct execute path
			std::string execute = "./Projects/" + (*_name);
			argv[0] = new char[execute.length() + 1];
			strcpy(argv[0], execute.c_str());
			
			// We copy just the name of the program to argv[1], 
			// so that it is accessible to the program as arg0
			argv[1] = new char[_name->length() + 1];
			strcpy(argv[1], _name->c_str());
			
			// It has to end with a null pointer
			argv[2] = static_cast<char *> (0);
			
			// Execute the program. We assume it won't fail
			execv(argv[0], argv + 1);
		}
	
		friend std::ostream& operator<< (std::ostream& o, const Project_desc& project);
		
	private:
		std::string * _name;
		std::string * _description;
		
};

class Project_list  {
	public:
		Project_list () {};
		~Project_list () {
			
		};
		
		void add_project(Project_desc * project) {
			// We assume that this will not fail, for the sake of simplicity
			_Projects.push_back(project);
		}
		
		void list_projects() {
			// TODO: Write code to actually list the projects, and then give
			// the user a way to select which one they want to view.
			for(std::vector<Project_desc *>::iterator a = _Projects.begin(), b = _Projects.end(); 
			    a!=b; a++) {
				std::cout << *(*a) << std::endl;
			}
		}

	private:
		std::vector<Project_desc *> _Projects;
};

std::ostream& operator<< (std::ostream& o, const Project_desc& project) {
	o << "Name: " << *project._name << std::endl;
	o << "Description: " << std::endl << "\t" << *project._description << std::endl;
	return o;
}

#endif /* _PROJECT_H_ */
