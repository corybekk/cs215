/* Name: Cory Bekker
 * CS 215 Lab 5
 * Describe the program here:
 */
#include <iostream>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <string>
#include "lab7.h"
#include <sstream>
using namespace std;

bool isVowel(char input);
bool isConsonant(char input1);
bool isSpecial(char input2);
bool isDigit(char input3);

const int MAX = 100;    // upper bound on the number of words
const string filename="words.txt"; // name of input file

int main () {
  // Open file for input
  ifstream input(filename.c_str());

  //string inword;  // tmp for reading a word from the file
  Word words[MAX]; // our list of words (as an array of Word objects)
  int num_words = 0; // counter of words read

  // Read until array is filled or end of file is found
  // Insert word into array
  //  words[num_words].SetWord(inword);
  while (num_words < MAX && input >> words[num_words]) {
    // Increment counter
    num_words++;
  }

  // Close inout file
  input.close();
  //  cout << num_words << endl;  
  // Print header row of report
  cout << setw (12) << left << "Word";
  cout << setw (8) << right << "Vowels";
  cout << setw (8) << right << "Cons.";
  cout << setw (8) << right << "Digits";
  cout << setw (8) << right << "Special";
  cout << endl;
  
  // Loop through all words in array
  for (int i = 0; i < num_words; i++) {
    // Print data for word
    // Each word is one row of the report
    //   words[i].WriteData(cout);
    cout<<words[i];
  }
  return 0;
}
////////////////////////don't know if it is correct///////////////////////////////////////
Word& Word::operator = (const Word& other_word){
  
  if(this == &other_word)return *this;
  
  delete this;
  
  text=new char[strlen(other_word.text)+1];
  strcpy(text,other_word.text);
  
  return *this;
  
}
/////////////////////////////////////////////////////////////////
bool Word::operator == (const Word& other_word) const{

  if(this==&other_word)return true;
  if(strcmp(this->text, other_word.text) and
     this->vowels == other_word.vowels and   // have to use "->" with this to access members of the class object it is pointing to??
     this->consonants == other_word.consonants and
     this->digits == other_word.digits and
     this->specialchars==other_word.specialchars)return true;
  
  return false;
  
}
//////////////////////////////////////////////////////////////////
Word Word::operator + (const Word& other_word) const{
  
  Word object;
  
  object.text= new char[strlen(object.text)+ strlen(other_word.text)+1]; // using object.text to point to a heap of space works??
  
  strcpy(object.text, strcat (this->text,other_word.text)); // cocatinates the two string members into a new string member
  
  object.consonants = this->consonants + other_word.consonants;
  object.vowels = this->vowels  + other_word.vowels;// this updates the new objects members, I add the original object and the
  object.digits=this->digits + other_word.digits;             // other_word object and put it into the new object "word object"
  object.specialchars=this->specialchars + other_word.specialchars;
  
  return object;
}
/////////////////////////////////////////////////////////////////
istream& operator >> (istream& ins, Word& w){ // I do not know how to write this deffinition call?? thing
  
  string temp;
  if(ins>>temp){
    w.SetWord(temp);
  }
  return ins; // returns ins if "ins>>temporary" fails, or if the while loop was executed
}
////////////////////////////////////////////////////////////////
ostream& operator << (ostream& outs, const Word& w){ // I do not know how to write this deffinition call?? thing
  
  outs << setw (12) << left << w.text;
  outs << setw (8) << right << w.vowels;
  outs << setw (8) << right << w.consonants;// replace cout with outs???
  outs << setw (8) << right << w.digits;
  outs << setw (8) << right << w.specialchars;
  outs<<"\n";
  
  return outs;
}
//////////////////////////////////////////////////////////////
bool isVowel(char input){
  char vowel = tolower (input);// makes everything lowercase
  //checks if any of the chars in the word are vowels
  return(vowel=='a' or vowel=='e' or vowel =='i' or vowel =='o' or vowel == 'u');
}
bool isConsonant(char input1){
  char letter = tolower (input1);
  //checks if any of the letters are consonants... ect
  if(isVowel(letter)or!isalpha(letter))return false;
  return true;
}
bool isSpecial(char input2){
  char special = tolower (input2);
  if(isalpha(special) or isdigit(special) or isspace(special)) return false;
  return true;
}
bool isDigit(char input3){
  char number=tolower(input3);
  if(isdigit(number))return true;
  return false;
}
/////////////////////////////////////////////////////////////////
//the default constructor has no parameters.This function sets each
//private variable to 0 or ''''' so that way there is not garbage in them
Word::Word(){

  text= new char[1];
  text[0]=0;
  vowels =0;
  consonants =0;
  digits =0;
  specialchars =0;
}
//The copy constructors parameter is called other_word which is a string.
//it also has to be a const so it doesnt get changed
//it is called whenever a new variable is created from an object.
Word::Word(const Word& other_word){
  
  // text=[other_word.length()];
  text=new char[strlen(other_word.text)+1];
  strcpy(text,other_word.text);

  vowels = other_word.vowels;
  consonants = other_word.consonants;
  digits = other_word.digits;
  specialchars = other_word.specialchars;

}
//the function setword takes each char of the array and checks if it is a
//number, vowel, consonant, or special character.
// the parameters are a const so it doesnt get changed.
//it is passes by reference so it makes a copy
void Word::SetWord(const string& input_word){

  text=new char[input_word.length()+1];
  strcpy(text,input_word.c_str());
  
  for(int i=0; i<strlen(text); i++){// creates an array
    
    if(isVowel(text[i])==true){
      vowels++;// if there is a vowel then it increases the number of vowels counted
    }
    if(isConsonant(text[i])==true){
      consonants++;
    }
    if(isSpecial(text[i])==true){
      specialchars++;
    }
    if(isDigit(text[i])==true){
      digits++;
    }
  }
}

/*void Word:: WriteData(ostream& outs) const{

  cout << setw (12) << left << text;
  cout << setw (8) << right << vowels;
  cout << setw (8) << right << consonants;
  cout << setw (8) << right << digits;
  cout << setw (8) << right << specialchars;
  cout<<"\n";
}
*/
string Word::GetWord () const{

  return text;
}
/////////////////////////////////////////////////////////////////////////////////

Word::~Word(){
  
  delete[]text;
}
