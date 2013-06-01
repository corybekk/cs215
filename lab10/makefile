all: Lab10.o CoordPt.o 
	g++ -g -o lab10.out Lab10.o CoordPt.o 
 
Lab10.o : Lab10.cpp LList.tmp.h CoordPt.h 
	g++ -g -c Lab10.cpp
 
CoordPt.o : CoordPt.cpp CoordPt.h 
	g++ -g -c CoordPt.cpp 
 
clean : 
	rm -f *.o *.out