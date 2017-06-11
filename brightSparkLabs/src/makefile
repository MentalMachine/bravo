CPPFLAGS = -std=gnu++14
CATCHFLAGS = 

build: BSL.h
	g++ BSL.cpp main.cpp $(CPPFLAGS)
	
tests_main.o: tests_main.cpp catch.hpp
	g++ -c tests_main.cpp $(CPPFLAGS)
	
test_BSL.o: tests_main.o test_BSL.cpp BSL.cpp catch.hpp BSL.h
	g++ -c test_BSL.cpp BSL.cpp tests_main.o  $(CPPFLAGS)
	
BSL.o: BSL.cpp BSL.h
	g++ -c BSL.cpp $(CPPFLAGS)
	
test: tests_main.o BSL.o test_BSL.o
	g++ -o test_BSL_bin tests_main.o test_BSL.o BSL.o $(CPPFLAGS)

.PHONY: test_run	
test_run : test
	./test_BSL_bin $(CATCHFLAGS)