all: lab12

lab12: Lab12.o polygon.o
	g++ -g -o lab12.out Lab12.o polygon.o

Lab12.o: Lab12.cpp polygon.h
	g++ -g -c Lab12.cpp

polygon.o: polygon.cpp polygon.h
	g++ -g -c polygon.cpp

clean:
	rm -f *~ *.o *.out

