//Cory Bekker
//Cs215
//Project3

#ifndef FLASHCARDDECK_H 
#define FLASHCARDDECK_H

#include <iostream>
#include <vector>
#include "flashcard.h"

using namespace std;

/* -----------------------------------------
 * FLASHCARDDECK CLASS
 *
 * Contains information about a deck of flash cards
 * -----------------------------------------
 */
class FlashCardDeck {
  private:
     vector<FlashCard*> deck; // the cards
     vector<FlashCard*> last_answered_wrong; // only the cards answered wrong last time
     string filename;  // file with deck info

     // Bools:
     bool valid; // TRUE if this deck has been initialized properly (read from a valid file)
     bool played_before; // TRUE if the user has played this deck before
     string Backcatagory;// the catagory of the back of card
     string Frontcatagory;// the catagory of front of card

     //Make_Played_before function
     //description: makes a flashcard deck that has been played before
     //parameters: "row" is the row/line in the file being read, used
     //to make flashcard. "ArraySize" is the size of the array made from
     //the file. "CurrentLine" is the current line being read.
     //no return value
     void Make_Played_Before(string Row[],int ArraySize, int CurrentLine);

     //Make_Unplayed_deck
     //Makes a deck of cards that has not ben played before.
     //Parameters:"row" is the row/line in the file being read, used
     //to make flashcard. "ArraySize" is the size of the array made from
     //the file. "CurrentLine" is the current line being read.
     //no return value
     void Make_unplayed_deck(string Row[],int ArraySize, int CurrentLine);

     //PrintToFile function
     //Description: This function prints the answers the user got
     //to a new file in "played before" format.
     //Parameters: "filename" is the file that is written to.
     //returns nothing.
     void PrintToFile(string filename);

  public:
     // Create an uninitialized flash card deck
     FlashCardDeck();

     // Copy the other flash card deck
     FlashCardDeck(const FlashCardDeck& other);

     // Read a flash card deck from the given input file
     // Should be able to handle new or unplayed decks
     FlashCardDeck(string filename);

     // Deallocate all of the flash cards in the deck
     ~FlashCardDeck();

     // If deck is uninitialized, don't do anything
     // and return false.
     //
     // Otherwise, play through the deck in random order
     // and track the user's answers
     //
     // If the bool "wrong" is true, only ask the ones
     // that the user got wrong last time. If the user
     // didn't get any wrong last time, return false. 
     // 
     // When quiz is over, print 
     // the percent the user got right and write deck out to file
     bool Quiz(istream& ins, ostream& outs, bool wrong,string file);

};

#endif
