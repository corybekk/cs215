all: lab09b lab09c

lab09b: Lab9b.o word.o
	g++ -g -o lab09b.out Lab9b.o word.o 

Lab9b.o: Lab9b.cpp word.h 
	g++ -g -c Lab9b.cpp 

word.o: word.cpp word.h 
	g++ -g -c word.cpp 

lab09c: Lab9c.o LList.o
	g++ -g -o lab09c.out Lab9c.o LList.o
 
Lab9c.o: Lab9c.cpp LList.h 
	g++ -g -c -D LAB09B Lab9c.cpp 
 
LList.o: LList.cpp LList.h
	g++ -g -c LList.cpp 

clean:
	 rm -f *.o lab09*.out


