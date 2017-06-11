CPPFLAGS = -std=gnu++14
CATCHFLAGS = 

BSL: main.o BSL.o
	g++ -o BSL main.o BSL.o $(CPPFLAGS)

main.o: main.cpp BSL.h
	g++ -c main.cpp $(CPPFLAGS)
	
BSL.o: BSL.cpp BSL.h
	g++ -c BSL.cpp $(CPPFLAGS)

tests_main.o: tests_main.cpp catch.hpp
	g++ -c tests_main.cpp $(CPPFLAGS)
	
test_BSL.o: test_BSL.cpp BSL.cpp catch.hpp BSL.h
	g++ -c test_BSL.cpp BSL.cpp $(CPPFLAGS)
	
test: tests_main.o BSL.o test_BSL.o
	g++ -o test tests_main.o test_BSL.o BSL.o $(CPPFLAGS)

.PHONY: test_run	
test_run : test
	./test $(CATCHFLAGS)
	
.PHONY: clean
clean:
	rm -f *.o BSL test