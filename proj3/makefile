p3.out :flashcardtester.o flashcard.o flashcarddeck.o
	g++ -g p3.out flashcardtester.o flashcard.o flashcarddeck.o

flashcardtester.o : flashcardtester.cpp flashcarddeck.h flashcarddeck.cpp
	g++ -g -c flashcardtester.cpp flashcarddeck.h

flashcard.o : flashcard.cpp flashcard.h
	g++ -g -c flashcard.cpp

flashcarddeck.o : flashcard.h flashcard.cpp flashcarddeck.cpp flashcarddeck.h
	g++ -g -c flashcarddeck.cpp
