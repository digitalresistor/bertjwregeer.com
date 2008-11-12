OPTIMIZE ?=0
CXXFLAGS = -I. -I.. -Wall -pipe -O${OPTIMIZE} ${DEBUG}

all: Main About_me

About_me: About_me.cc includes/Person.h
Main: Main.cc

.cc.o:
	$(CXX) ${CXXFLAGS} -c $<
	
clean:
	/bin/rm -f About_me Main
