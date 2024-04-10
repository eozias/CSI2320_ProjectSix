all: main

main: main.o CityClock.o Clock.o
	g++ main.o CityClock.o Clock.o -o main

main.o: main.cpp Clock.h CityClock.h
	g++ -c main.cpp

CityClock.o: CityClock.cpp CityClock.h Clock.h
	g++ -c CityClock.cpp

Clock.o: Clock.cpp Clock.h
	g++ -c Clock.cpp

clean:
	rm -f *.o main

run: main
	./main