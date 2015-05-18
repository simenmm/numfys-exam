CXX=g++

CXXFLAGS=-Wall -Wextra -pedantic -g -std=c++0x 


XOBJS= /usr/lib/libboost_thread.so.1.46.1
OBJS=main.o $(XOBJS)
TESTOBJS=single.o $(XOBJS)
BIN=outputfile
LDFLAGS=-lm

all: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(BIN)

test: $(TESTOBJS)
	$(CXX) $(LDFLAGS) $(TESTOBJS) -o testexec

clean:
	rm *.o *~
