CPPFLAGS = -std=gnu++14
CATCHFLAGS = 

build: fib.h
	g++ fib.cpp main.cpp $(CPPFLAGS)
	
tests_main.o: tests_main.cpp catch.hpp
	g++ -c tests_main.cpp $(CPPFLAGS)
	
test_fib.o: tests_main.o test_fib.cpp fib.cpp catch.hpp fib.h
	g++ -c test_fib.cpp fib.cpp tests_main.o  $(CPPFLAGS)
	
fib.o: fib.cpp fib.h
	g++ -c fib.cpp $(CPPFLAGS)
	
test: tests_main.o fib.o test_fib.o
	g++ -o test_fib_bin tests_main.o test_fib.o fib.o $(CPPFLAGS)

.PHONY: test_run	
test_run : test
	./test_fib_bin $(CATCHFLAGS)