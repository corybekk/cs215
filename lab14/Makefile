all: lab14

lab14: lab14.o fraction.o
	g++ -g -o lab14.out lab14.o fraction.o

lab14.o: Lab14.cpp LList.tmp.h
	g++ -g -c Lab14.cpp -o lab14.o

fraction.o: fraction.cpp
	g++ -g -c fraction.cpp
 
clean:
	 rm -f core.* *.o *.out


