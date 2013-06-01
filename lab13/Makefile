all: lab13b lab13c

lab13b: lab13b.o LList2.o 
	g++ -g -o lab13b.out lab13b.o LList2.o 

lab13b.o: Lab13b.cpp LList2.h 
	g++ -g -c Lab13b.cpp -o lab13b.o
 
LList2.o: LList2.cpp LList2.h
	g++ -g -c LList2.cpp

lab13c: lab13c.o fraction.o
	g++ -g -o lab13c.out lab13c.o fraction.o

lab13c.o: Lab13c.cpp LList.tmp.h
	g++ -g -c Lab13c.cpp -o lab13c.o

fraction.o: fraction.cpp
	g++ -g -c fraction.cpp
 
clean:
	 rm -f core.* *.o *.out


