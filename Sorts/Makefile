#
#makefile for sorts
#

RM = rm -f
SRCPATH = .
SRC = quicksort.cpp mergesort.cpp ../Standard/Standard.cpp ../String/String.cpp \
../Common/Color.cpp
TESTNAME = test
TESTSRC = main.cpp

all: re $(SRC) $(TESTSRC)
	g++ $(SRC) $(TESTSRC) -pedantic -Wall -Werror -std=c++0x -o $(TESTNAME)

debug: re $(SRC) $(TESTSRC)
	g++ $(SRC) $(TESTSRC) -Wall -Werror -std=c++0x -o $(TESTNAME) -g

retest: re test

clean:
	-$(RM) *.o
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) *.gch

fclean: clean
	-$(RM) $(TESTNAME)

re: fclean

test: fclean $(TESTSRC)
	g++ $(TESTSRC) -Wall -Werror -std=c++0x -o $(TESTNAME)
