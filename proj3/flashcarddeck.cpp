//Cory Bekker
//course: cs215
//project 3
//**************

#include <iostream>
#include <sstream>
#include "flashcard.h"
#include "flashcarddeck.h"
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>

void Make_Played_Before(string Row[],int ArraySize,int CurrentLine);
void UserPercent(int CorrectAnswers,int SIZE);
void PrintToFile();

using namespace std;

FlashCardDeck::FlashCardDeck(){

  vector<FlashCard*> deck(0); // 
  vector<FlashCard*> last_answered_wrong(0); // only the cards answered wrong last time
  string filename =""; // file with deck info
  bool valid = false;  // TRUE if this deck has been initialized properly (read from a valid file)
  bool played_before = false; // TRUE if the user has played this deck before

}
//--------------------------------------------------------------------------------------------------------------------------
FlashCardDeck:: FlashCardDeck(const FlashCardDeck& other){

  deck = other.deck; // make the vector of "other" equal the default vector???
  last_answered_wrong = other.last_answered_wrong;
  filename = other.filename;
  valid = other.valid;
  played_before = other.played_before;

}
//--------------------------------------------------------------------------------------------------------------------------
// Read a flash card deck from the given input file, Should be able to handle new or unplayed decks
FlashCardDeck:: FlashCardDeck(string filename){
  
  ifstream file;//used to open filename 
  int MAX = 0;// the max amount of lines in the file
  int currentSpot =0;// the current line being read from the file
  bool correctLast;// wither the flashcard was answered corretly or wrong
  string front;//the front of the flashcard
  string back;// the back of the flashcard
  string row[1000];// each line of the file
  string sentence;// make a string for the file line to read into     

  file.open(filename.c_str());
  if(file.fail()){
    cout<<"could not open file"<<endl;
    exit(1);
  }
    while(!file.eof()){
    getline(file,sentence);
    row[MAX]=sentence;
    MAX++;
  }
  if(MAX<5){
    cout<<"not enough flashcards in deck"<<endl;
      exit(1);
  }
  while(row[currentSpot]=="\n" or row[currentSpot]=="\t" or row[currentSpot]=="\0"){
    currentSpot++;
  }
  
  Frontcatagory=row[currentSpot];//the catagory printed when the game starts
  currentSpot++;
  Backcatagory=row[currentSpot];
  currentSpot++;

  //////////////////////////////////
  /* if(row[currentSpot]=="Last Score"){
    Make_Played_Before(row,MAX,currentSpot);
    played_before=true;
      }
  */
  
   if(row[currentSpot]=="Last Score"){// I dont know if this is correct
     Make_Played_Before(row,MAX,currentSpot);
   }
       /* played_before = true;
    currentSpot++; // this is supposed to be a empty line
    currentSpot++; // this is supposed to be the beginning of the first flashcard
    while(currentSpot<MAX){
      if(row[currentSpot]=="\n" or row[currentSpot]=="\t" or row[currentSpot]=="\0"){
	cout<<"error: to many spaces in between flashcard decks... line: "<<currentSpot<<endl;
	exit(1);
      }
      front = row[currentSpot];
      currentSpot++;
      if(row[currentSpot]=="\n" or row[currentSpot]=="\t" or row[currentSpot]=="\0"){
        cout<<"error: to many spaces in between flashcard decks... line: "<<currentSpot<<endl;
        exit(1);
      }
      back = row[currentSpot];
      currentSpot++;
      if(row[currentSpot]=="\n" or row[currentSpot]=="\t" or row[currentSpot]=="\0"){
        cout<<"error: this card has not been played before... line: "<<currentSpot<<endl;
        exit(1); 
      }	
      if(row[currentSpot]=="1"){
      correctLast=true;// this updates the card saying wither it was answer correct
      }
      else{
	correctLast=false;// if the card was incorrect it adds it to last_answered_wrong 
	last_answered_wrong.push_back(new FlashCard(front,back,correctLast));// creates a deck of the cards go wrong
      }
      currentSpot++;
      currentSpot++;
      deck.push_back(new FlashCard(front,back,correctLast));//creates the full deck incase the user wants to play the full deck
      if(currentSpot==MAX-1)break;//so it doesnt read last line
    }
  }
       */


  else{
    currentSpot++;

    while(currentSpot<MAX){
      
      front = row[currentSpot];
      currentSpot++;
      if(row[currentSpot]=="\n" or row[currentSpot]=="\t" or row[currentSpot]=="\0"){
	cout<<"error: to many spaces in between flashcard decks... line: "<<currentSpot<<endl;
	exit(1);
      }
      back = row[currentSpot];
      currentSpot++;
      
      if(row[currentSpot]=="\n" or row[currentSpot]=="\t" or row[currentSpot]=="\0"){
	currentSpot++;
      }
      deck.push_back(new FlashCard(front,back));
      if(currentSpot==MAX-1)break;//so it doesnt read last line
    }
    played_before = false;// this deck has not been played before because it does not contain "last score"
  }
   file.close();
}
  
//--------------------------------------------------------------------------------------------------------------------------
FlashCardDeck::~FlashCardDeck(){
    int i =0;
    delete deck[i];
}
//--------------------------------------------------------------------------------------------------------------------------
bool FlashCardDeck::Quiz(istream& ins, ostream& outs, bool wrong,string file){
  
  int right=0;
  int i=0;
  int size;
  string Input1or2;// this is the user input so they can choose wither they want to play last_answered_wrong deck

  if(played_before == true){
    cout<<endl;
    cout<<"Would you like to play..."<<endl;
    cout<<endl;
    cout<<"1. The entire deck?"<<endl;
    cout<<"2. just the ones you got wrong last time?"<<endl<<endl;;
    cout<<"Please enter (playfull or playwrong): ";

    while(Input1or2!="playfull" or Input1or2!="playwrong"){

      cin>>Input1or2;

      if(Input1or2=="playfull"){
	wrong=false;
	break;
      }
      if(Input1or2=="playwrong"){
	wrong=true;
	break;
      }
      cout<<"incorrect input, please try again :";
    }
  }
  
  size=deck.size();//a variable that is the size of the deck. I use to pass to function
  cout<<endl;
  outs<<"Front of flash card: "<<Frontcatagory<<endl;
  outs<<"Back of flash card: "<<Backcatagory<<endl<<endl;

  random_shuffle(deck.begin(),deck.end());
  
  if(wrong == true){
    for(int i = 0; i<last_answered_wrong.size();i++){
      last_answered_wrong[i]->Quiz(ins,cout);
      if(last_answered_wrong[i]->CorrectLastTime()==true){
        right++;
      }
    }
  }
  else{
    for(int i = 0; i<deck.size();i++){
      deck[i]->Quiz(ins,cout);
      if(deck[i]->CorrectLastTime()==true){
	right++;
      }
    }
  }  
  UserPercent(right,size);// prints out how many answers the user got write
  
  //------------------------------

  //void PrintToFile

    PrintToFile;

  ofstream outsfile;
  
  outsfile.open(file.c_str());
  if(outsfile.fail()){
    cout<<"could not create new file"<<endl;
  }
   outsfile<<Frontcatagory<<endl;
   outsfile<<Backcatagory<<endl;
   outsfile<<"Last Score"<<endl;
   outsfile<<endl;


   for(int i =0; i<deck.size();i++){//write info to new file
     deck[i]->WriteCard(outsfile);
   }
     outsfile.close();
   return 0;
}
//==========================================================
void UserPercent(int CorrectAnswers,int SIZE){

  float correctanswers = 0.0;
  float size =0.0;
  float percent =0.0;

  correctanswers=CorrectAnswers;
  size = SIZE;
  percent = correctanswers / size;
  percent = percent * 100;

  if(CorrectAnswers==SIZE){//so it prints 100 and not 1%
    percent=100;
  }
  if(CorrectAnswers== 0){// so it doesn't print a garbage number
    percent=0;
  }

  cout<<"ROUND SUMMARY:"<<endl;
  cout<<"You got "<<CorrectAnswers<<" of "<<SIZE<<" right ";
  cout<<"("<<percent<<"%)."<<endl;

}
//==========================================================

void FlashCardDeck::Make_Played_Before(string Row[],int ArraySize, int CurrentLine){

  string front;
  string back;
  bool correctLast;

  played_before=true;

  CurrentLine++; // this is supposed to be a empty line                                                                              
  CurrentLine++; // this is supposed to be the beginning of the first flashcard                                                      

  while(CurrentLine<ArraySize){
    if(Row[CurrentLine]=="\n" or Row[CurrentLine]=="\t" or Row[CurrentLine]=="\0"){
      cout<<"error: to many spaces in between flashcard decks... line: "<<CurrentLine<<endl;
      exit(1);
    }
    front = Row[CurrentLine];
    CurrentLine++;
    if(Row[CurrentLine]=="\n" or Row[CurrentLine]=="\t" or Row[CurrentLine]=="\0"){
      cout<<"error: to many spaces in between flashcard decks... line: "<<CurrentLine<<endl;
      exit(1);
    }
    back = Row[CurrentLine];
    CurrentLine++;
    if(Row[CurrentLine]=="\n" or Row[CurrentLine]=="\t" or Row[CurrentLine]=="\0"){
      cout<<"error: this card has not been played before... line: "<<CurrentLine<<endl;
      exit(1);
    }
    if(Row[CurrentLine]=="1"){
      correctLast=true;// this updates the card saying wither it was answer correct                                                    
    }
    else{
      correctLast=false;// if the card was incorrect it adds it to last_answered_wrong                                               
      last_answered_wrong.push_back(new FlashCard(front,back,correctLast));// creates a deck of the cards go wrong                   
    }
    CurrentLine++;
    CurrentLine++;
    deck.push_back(new FlashCard(front,back,correctLast));//creates the full deck incase the user wants to play the full deck        
    if(CurrentLine==ArraySize-1)break;//so it doesnt read last line                                                                        
  }
}



//===============================================================
/*void MakeArray(string inputfile,string &Row[], int &ArraySize){

  ifstream file;
  string sentence;

  file.open(inputfile.c_str());
  if(file.fail()){
    cout<<"could not open file"<<endl;
    exit(1);
  }

  while(!file.eof()){
    getline(file,sentence);
    Row[ArraySize]=sentence;
    ArraySize++;
  }

  if(ArraySize<5){
    cout<<"not enough flashcards in deck"<<endl;
    exit(1);
  }
  // return Row;
  }*/
//===========================================================


/*bool YesPlayed(string array,int currentSPOT){

if(array[currentSPOT]=="Last Score"){// I dont know if this is correct
  played_before = true;
  currentSPOT++; // this is supposed to be a empty line
  currentSPOT++; // this is supposed to be the beginning of the first flashcard
  while(currentSPOT<MAX){
    if(array[currentSPOT]=="\n" or array[currentSPOT]=="\t" or array[currentSPOT]=="\0"){
      cout<<"error: to many spaces in between flashcard decks... line: "<<currentSPOT<<endl;
      return false;
    }
    front = array[currentSPOT];
    currentSPOT++;
    if(array[currentSPOT]=="\n" or array[currentSPOT]=="\t" or array[currentSPOT]=="\0"){
      cout<<"error: to many spaces in between flashcard decks... line: "<<currentSPOT<<endl;
      return false;
    }
    back = array[currentSPOT];
    currentSPOT++;
    if(array[currentSPOT]=="\n" or array[currentSPOT]=="\t" or array[currentSPOT]=="\0"){
      cout<<"error: this card has not been played before... line: "<<currentSPOT<<endl;
      return false;
    }
    if(array[currentSPOT]=="1"){
      correctLast=true;// this updates the card saying wither it was answer correct
    }
    else{
      correctLast=false;
    }
    currentSPOT++;
    currentSPOT++;
    deck.push_back(new FlashCard(front,back,correctLast));
  }
  return true; 
 }
 return false;
}
*/
