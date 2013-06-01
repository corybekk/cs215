//Cory Bekker
//course cs215
//Project3
//************************

#include <iostream>
#include <sstream>
#include <fstream>
#include "flashcarddeck.h"
#include "flashcard.h"

int Set_Up_File(string DeckArray[],int &DeckNumber);
string Check_input(string Input, string DeckArray[]);

using namespace std;

int main( ) {
  
  ifstream DecksFile;//used to open the the decks.txt file
  int decknumber =0;// the amount of decks to chose from
  string deckarray[100];// used to store each sentence from the file.. or "deck"
  bool PlayWrong;//if true then the user wants to play the flash cards they got wrong
  int currentSpot =0;//this is the current spot being read in the file. 
  string input;// the sers input on which deck or file they want to play
  
  while(input!="quit"){//waits until the user inputs "quit"
              //This is the number that will print next to the deck file.
    int i =1;// Declared in the loop so that way it doesn't keep increasing after the deck has been played
    
    currentSpot= Set_Up_File(deckarray,decknumber);//This calls the function Set_Up_File, which opens the file and makes an array of decks to read
    
    while(currentSpot<decknumber){//while the current spot in the file is less than the file size "size in lines"
      if(deckarray[currentSpot]=="\n" or deckarray[currentSpot]=="\t" or deckarray[currentSpot]=="\0"){
	break;// if the last line is empty it wont print it
      }
      cout<<i<<". ";// prints the number of the deck
      cout<<deckarray[currentSpot]<<endl;// the actual deck name
      currentSpot++;// updates the current spot that is being read in the file
      i++;
    }
    cout<<"or"<<endl;
    cout<<i<<". "<<"quit?"<<endl;
    cout<<"Please enter file name or (quit): ";
    cin>>input;// asks the user for their input and saves it in the variable "input"
    
    input= Check_input(input,deckarray);//checks the input of the user and see if it matches the correct file names. 
    if(input == "quit")return 0; //if the user wants to quit from the flashcard games, exit the program.     

    FlashCardDeck play(input);//opens a specific file for a deck of cards and creates flashcards
    
    PlayWrong = false;// set it to false because in the quiz function it checks if the user wants to play the cards they got wrong  
    play.Quiz(cin,cout,PlayWrong,input);// quizes the user on the flashcard deck they chose  
    
    DecksFile.close();//closes file
  }
  return 0;
}
//============================================================
//Set_up_file function.
//Description: opens the file and makes an array of flashcarddecks
//and gets rid of begining white space.
//parameters: DeckArray is an array of lines in the file. Each
//line is a deck of cards. DeckNumber is the number of decks
//in the file. Pass by reference because the function can 
//return only one value. The function returns "currentspot"
//which is the current line being read in the file. 
//============================================================
int Set_Up_File(string DeckArray[],int &DeckNumber){

   ifstream DecksFile;//used to open the the decks.txt file
   string decklist;// list of decks in the decks.txt file
   int currentSpot =0;//this is the current spot being read in the file.
   
   cout<<"*** FLASHCARD GAME ***"<<endl<<endl;
   cout<<"Would you like to play..."<<endl;
   
   DecksFile.open("decks.txt");// opens the file that contains the decks names
   if(DecksFile.fail()){ // if file fails to open, gives error
     cout<<"Could not open flashcard decks file: decks.txt"<<endl;
   }
   
   while(!DecksFile.eof()){// reads until the end of the file
     getline(DecksFile,decklist);// puts each line of the file into the string "deckslist"
     DeckArray[DeckNumber]=decklist;//create an array of decks from decklist
     DeckNumber++;// the amount of decks in the file
   }
   while(DeckArray[currentSpot]=="\n" or DeckArray[currentSpot]=="\t" or DeckArray[currentSpot]=="\0"){
      currentSpot++;//passes blank lines in the begining of decks.txt. just in case
   }
   return currentSpot; 
}
//============================================================
//Check Input function
//Description: this function takes the users input and checks to 
//see if it matches anny of the arrays, which will determine
//what deck the user will want to play.
//Parameter: input is the users input. DeckArray is each deck
//the user can chose from. This function returns the users 
//input and uses it to make a flashcarddeck.
//============================================================
string Check_input(string Input, string DeckArray[]){
  
  while(Input!="quit"){// while the users input is not "quit" it continues with the loop
    if(Input==DeckArray[0])break;// checks the users input to see if it matches up with any of the decks in decklist
    if(Input==DeckArray[1])break;//sadly enough, it only fits 6 decks at the moment.
    if(Input==DeckArray[2])break;
    if(Input==DeckArray[3])break;
    if(Input==DeckArray[4])break;
    if(Input==DeckArray[5])break;
    cout<<"please enter a correct choice: ";// if there is no match, gives specific error
    cin>>Input;
  }
  if(Input=="quit")return "quit";// if input is "quit" it exits
  
  else{
    return Input;
  }
}


