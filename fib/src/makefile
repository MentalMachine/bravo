CPPFLAGS = -std=gnu++14
CATCHFLAGS = 

fib: fib.o main.o
	g++ -o fib fib.o main.o $(CPPFLAGS) -O3

debug: fib.o main.o
	g++ -o debug fib.o main.o $(CPPFLAGS) -g

fib.o: fib.cpp fib.h
	g++ -c fib.cpp $(CPPFLAGS)

main.o: main.cpp fib.h
	g++ -c main.cpp $(CPPFLAGS)

tests_main.o: tests_main.cpp catch.hpp
	g++ -c tests_main.cpp $(CPPFLAGS)
	
test_fib.o: test_fib.cpp fib.cpp catch.hpp fib.h
	g++ -c test_fib.cpp fib.cpp $(CPPFLAGS)

test: tests_main.o fib.o test_fib.o
	g++ -o test tests_main.o test_fib.o fib.o $(CPPFLAGS)

.PHONY: test_run	
test_run : test
	./test $(CATCHFLAGS)
	
.PHONY: clean
clean:
	rm -f *.o fib test debug