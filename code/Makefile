OPTIMIZE ?=0
CXXFLAGS = -I. -Wall -pipe -O${OPTIMIZE} ${DEBUG}

all: Project Main About_me Resume Projects Contact

About_me: About_me.cc includes/Person.h
Resume: Resume.cc
Projects: Projects.cc includes/Project_desc.h
Contact: Contact.cc
Main: Main.cc
Project::
	@echo "Entering the Project folder: "
	cd ./Project && ${MAKE}
	@echo "Done building Project folder"
	
clean:
	/bin/rm -f About_me Main Resume Projects Contact
	cd ./Project && ${MAKE} clean
