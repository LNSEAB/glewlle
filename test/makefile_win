CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -O2 -g
LDFLAGS=

BOOST_INCLUDE=
BOOST_LIBPATH=
BOOST_LIBS=
NCLR_INCLUDE=

INCLUDE=$(BOOST_INCLUDE) $(NCLR_INCLUDE)
LIBPATH=$(BOOST_LIBPATH)
LIBS=$(BOOST_LIBS) -lopengl32 -lkernel32 -lgdi32 -luser32 -lcomctl32

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) $^ -o $@

all: test

test: test.o
	$(CXX) $(LDFLAGS) $(LIBPATH) $^ $(LIBS) -o $@

.PHONY: clean

clean:
	-rm *.exe
	-rm *.o
