all: application.o dynarr.o
	g++ -g -o lab08.out application.o dynarr.o

application.o: application.cpp dynarr.h
	g++ -g -c application.cpp

dynarr.o: dynarr.cpp dynarr.h
	g++ -g -c dynarr.cpp

clean:
	rm -f core.* *.o lab08.out

