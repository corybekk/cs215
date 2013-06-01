all: Lab11.o polygon.o
	g++ -g -o lab11.out Lab11.o polygon.o

Lab11.o: Lab11.cpp polygon.h
	g++ -g -c Lab11.cpp

polygon.o: polygon.cpp polygon.h
	g++ -g -c polygon.cpp

clean:
	rm -f *~ *.o lab11.out

