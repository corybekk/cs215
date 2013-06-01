#include <iostream>
#include <sstream>
#include "flashcard.h"

using namespace std;


////////////////Default Constructor///////////i am supposed to concatanate this file to the flashcardtester.cpp"
FlashCard::FlashCard(){

  string front;
  string back;
  bool initialized = false; // TRUE if this Q has been initialized
  bool played_before=false; // TRUE if the user has answered this Q before
  bool correct_last_time=false;   // TRUE if the user answered this Q correctly last time
  // This variable only has meaning if played_before is TRUE
}
///////////////Copy constructor///////////////
FlashCard::FlashCard(const FlashCard& other){

  front = other.front;
  back = other.back;
  initialized = other.initialized;
  played_before = other.played_before;
  correct_last_time = other.correct_last_time;

}
///////////////////////////////////////////////
FlashCard::FlashCard(string question, string answer, bool last_correct){

  correct_last_time=false;
  played_before=false;
  initialized = false;
  last_correct =  true;// I don't know if setting this to true off the bat is correct. I think it is because this is supposed to be
  front = question;    // a flash card that has been played before.. ???
  back = answer;

}
///////////////////////////////////////////////
FlashCard::FlashCard(string question, string answer){

  front = question; // sets the question to the correct side of the card
  back = answer;
  initialized=true; // since this function was executed it has also been initialized.. therefore it becomes true???
  played_before=false;
  correct_last_time=false;
}
////////////////Destructor////////////////////
FlashCard::~FlashCard(){

}
///////////////////////////////////////////////
bool FlashCard::Quiz(istream& ins, ostream& outs){

  if(back=="")return false; //if the answer of the question is empty then it is false.

  string user_answer;

  outs<<front<<endl;// asks the question
  ins>>user_answer;// takes the users answer

  if(user_answer==back){ // got to check if these answers are the same
    cout<<"Correct!"<<endl;
    correct_last_time = true;
    played_before = true;
    return true;
  }
  cout<<"Wrong! It's "<<back<<'.'<<endl;
  correct_last_time=false;
  played_before=true;
  return false;

}
///////////////////////////////////////////////
bool FlashCard:: CorrectLastTime(){

  if(played_before == true){
    if(correct_last_time==true)return true;
  }
  return false;
}
///////////////////////////////////////////////
bool FlashCard::PlayedBefore(){

  if(played_before == true)return true;

  return false;
}
