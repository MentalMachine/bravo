CPPFLAGS = -std=gnu++14
CATCHFLAGS = --durations yes

build:
	g++ fib.cpp main.cpp $(CPPFLAGS)
test:
	g++ -o  test_fib fib.cpp test_fib.cpp tests_main.cpp $(CPPFLAGS)
.PHONY: test_run	
test_run : test
	./test_fib $(CATCHFLAGS)