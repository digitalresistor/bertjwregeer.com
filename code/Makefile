OPTIMIZE ?=0
CXXFLAGS = -I. -Wall -pipe -O${OPTIMIZE} ${DEBUG}

all: Main About_me Resume Projectsm Contact

About_me: About_me.cc includes/Person.h
Resume: Resume.cc
Projectsm: Projects.cc includes/Project.h
Contact: Contact.cc
Main: Main.cc
	
clean:
	/bin/rm -f About_me Main Resume Projectsm Contact
