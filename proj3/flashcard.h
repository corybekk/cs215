//Cory Bekker
//Cs215
//Project3

#ifndef FLASHCARD_H 
#define FLASHCARD_H

#include <iostream>
using namespace std;

/* -----------------------------------------
 * FLASHCARD CLASS
 *
 * Contains the front (question) and back
 * (answer) of a flash card plus information 
 * about whether the user answered this
 * question correctly last time
 * -----------------------------------------
 */
class FlashCard {
  private:
     string front; // front of card (question)
     string back;  // back of card (answer)

     // Bools:
     bool initialized; // TRUE if this Q has been initialized
     bool played_before; // TRUE if the user has answered this Q before

     // TRUE if the user answered this Q correctly last time
     // This variable only has meaning if played_before is TRUE
     bool correct_last_time;

     bool correct;
     bool wrong;

  public:
     // Create an uninitialized flash card
     FlashCard();

     // Copy the other flash card
     FlashCard(const FlashCard& other);

     // Create a flash card that has been played before.
     // The parameter last_correct is the result of the last
     // time this flash card was played.
     FlashCard(string question, string answer, bool last_correct);

     // Initialize a flash card that has not been played before.
     FlashCard(string question, string answer);

     ~FlashCard();

     // If card is uninitialized, don't do anything
     // and return false.
     //
     // Otherwise, ask the user the question (using outs)
     // and read the user's answer (using ins)
     //
     // Print a message congratulating or correcting the user
     // Return TRUE if the answer is correct and FALSE otherwise
     // Update member variables as needed
     bool Quiz(istream& ins, ostream& outs);
     void WriteCard(ostream& outs);

     bool CorrectLastTime(); // Accessor for correct_last_time 
     bool PlayedBefore();    // Accessor for played_before
};

#endif
