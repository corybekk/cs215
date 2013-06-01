//Cory Bekker
//course cs215
//Project3
//************************

#include <iostream>
#include <fstream>
#include <sstream>
#include "flashcard.h"

using namespace std;

//============================================================
//Default constructor
//sets the defaults for the member variables in class flashcard
//============================================================
FlashCard::FlashCard(){
  
  string front;// front of the flashcard
  string back;// back of the flashcard
  bool initialized = false; // TRUE if this Q has been initialized
  bool played_before=false; // TRUE if the user has answered this Q before
  bool correct_last_time=false;// TRUE if the user answered this Q correctly last time
                               // This variable only has meaning if played_before is TRUE
}
//============================================================
//copy constructor
// Parameters: passes a class object called "other".
// copies all the fields of other over to the class 
// fields. 
//============================================================
FlashCard::FlashCard(const FlashCard& other){
  
  front = other.front;//copies other.front field to front
  back = other.back;
  initialized = other.initialized;
  played_before = other.played_before;
  correct_last_time = other.correct_last_time;
  
}
//============================================================
//constructor for a flashcard that has been played before.
//Parameters: String question - the question on the flashcard
//Parameters: string answer - the answer on the flashcard
//Parameters: bool Last_correct- true if the flashcard was answered right, false otherwise
//============================================================
FlashCard::FlashCard(string question, string answer, bool last_correct){

  correct_last_time=last_correct;// if the user got it correct or wrong it will update correctlast
  played_before=true;//becomes true because the user has initialized and started to play the card
  initialized = true;// since this constructor was called, the card became intialized, therefore initialized = true
  front = question;// sets the question as the front of the flashcard  
  back = answer;// sets the answer as teh back of the flashcard

}
//============================================================
//constructor for a flashcard that has not been played before
//Parameter: question- front of flashcard
//parameter: answer - back of flashcard
//============================================================
FlashCard::FlashCard(string question, string answer){
  
  front = question; // sets the question to the correct side of the card
  back = answer; 
  initialized=true; // since this function was executed it has also been initialized.. therefore it becomes true
  played_before=false;//Since this card does not pass a parameter "last_correct" it has not been played before
  correct_last_time=false;// the card has not been played before, therefore the card was not answered correctly before
}
//============================================================
//Destructor
//============================================================
FlashCard::~FlashCard(){
  
}
//============================================================
//Quiz funtion quizes the user on the specific flashcard.
//Parameters: istream ins, ostream outs. "ins" is the users input "cin"
//and "outs" is "cout" used to print the question of card
//============================================================
bool FlashCard::Quiz(istream& ins, ostream& outs){
  
  if(back=="")return false; //if the answer of the question is empty then it is false.
  
  string user_answer;// this used to store the users answer
  
  outs<<front<<endl;// asks the question
  ins>>user_answer;// takes the users answer
  
  if(user_answer==back){ // check if users answers is the same as the cards answer
    cout<<"Correct!"<<endl<<endl;// if correct, congradulate the user
    correct_last_time = true;// the user got answer correct, update correct_last_time appropriatly
    played_before = true;// user played the card, update played_before appropriatly
    return true;// return true because the user answered correctly
  }
  cout<<"Wrong! It's "<<back<<'.'<<endl<<endl;
  correct_last_time=false;//they did not get the card write, set to false
  played_before=true;// user played the card, must update played_before
  return false;// if user answered wrong, return false

}
//============================================================
//Accessor function to see if the user answered the card correct last time
//============================================================
bool FlashCard:: CorrectLastTime(){

  if(played_before == true){// the card cannot be correct last time if it was never played, so played_before must be true
    if(correct_last_time==true)return true;// if the user answered correctly, it will return true
  }
  return false;// user answered wrong, return false
}
//============================================================
//accessor fucntion to see if the card was played before
//============================================================
bool FlashCard::PlayedBefore(){

  if(played_before == true)return true;// checks if the card was played, if it was, return true
  
  return false;// if the card was not played, return false
}
//============================================================
//paramter: "ostream outs" this is used to
//write the flashcard back to a newly created file. 
//The format that is written back is in "played_before"
//format, which includes the answer write or wrong. 
//============================================================
void FlashCard::WriteCard(ostream& outs){
  
  outs<<front<<endl;// the question of the flashcard printed to the file
  outs<<back<<endl;// the ansewer printed to the file
  outs<<correct_last_time<<endl;// use accessor function to print the users write or wrong ansewer
  outs<<endl;
}