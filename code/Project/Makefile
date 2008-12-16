OPTIMIZE ?=0
CXXFLAGS = -I. -Wall -pipe -O${OPTIMIZE} ${DEBUG}

all: ChristmasTree Commencement LEDWall NearSpace Op-Server ThisWebsite Miscellaneous

ChristmasTree: ChristmasTree.cc includes/Project.h
Commencement: Commencement.cc includes/Project.h
LEDWall: LEDWall.cc includes/Project.h
NearSpace: NearSpace.cc includes/Project.h
Op-Server: Op-Server.cc includes/Project.h
ThisWebsite: ThisWebsite.cc includes/Project.h
Miscellaneous: Miscellaneous.cc includes/Project.h
	
clean:
	/bin/rm -f ChristmasTree Commencement LEDWall NearSpace Op-Server ThisWebsite Miscellaneous
