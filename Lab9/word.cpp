#include "word.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <iomanip>

bool isVowel(char input);
bool isConsonant(char input1);
bool isSpecial(char input2);
bool isDigit(char input3);
//////////////////////////////////////////////////////
bool Word::operator < (const Word& other_word) const{

  //  other_word.text=tolower(other_word.text);
  //  this->text=tolower(this->text); 

  if(strcmp(this->text,other_word.text)<0)return true;
  
  return false;

}
///////////////////////////////////////////////////////////////
Word& Word::operator = (const Word& other_word){

  if(this == &other_word)return *this;

  delete this->text;

  text=new char[strlen(other_word.text)+1];
  strcpy(text,other_word.text);

  return *this;

}
/////////////////////////////////////////////////////////////////
bool Word::operator == (const Word& other_word) const{

  if(this==&other_word)return true;
  if(strcmp(this->text, other_word.text) and
     this->vowels == other_word.vowels and   
     this->consonants == other_word.consonants and
     this->digits == other_word.digits and
     this->specialchars==other_word.specialchars)return true;

  return false;

}
//////////////////////////////////////////////////////////////////
Word Word::operator + (const Word& other_word) const{

  Word object;

  object.text= new char[strlen(object.text)+ strlen(other_word.text)+1]; 
  
  strcpy(object.text, strcat (this->text,other_word.text));
  
  object.consonants = this->consonants + other_word.consonants;
  
  object.vowels = this->vowels  + other_word.vowels;
  
  object.digits=this->digits + other_word.digits;
  
  object.specialchars=this->specialchars + other_word.specialchars;
  
 return object;
}
/////////////////////////////////////////////////////////////////
istream& operator >> (istream& ins, Word& w){ 

    string temp;
  if(ins>>temp){
    w.SetWord(temp);
  }
  return ins; // returns ins if "ins>>temporary" fails, or if the while loop was executed
}
/////////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream& outs, const Word& w){ 

  outs << setw (12) << left << w.text;
 outs << setw (8) << right << w.vowels;
 outs << setw (8) << right << w.consonants;// replace cout with outs???
 outs << setw (8) << right << w.digits;
 outs << setw (8) << right << w.specialchars;
 outs<<"\n";

 return outs;
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

/////////////////////////////////////////////////////////////////////
string Word::GetWord () const{

  return text;
}
/////////////////////////////////////////////////////////////////////////////////

Word::~Word(){

  delete[]text;
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
