// preprocessor directives -- keep us from including this file twice
#ifndef WORDDATA
#define WORDDATA 
 
#include <cstring> 
#include <string> 
#include <iostream> 
#include <iomanip> 
 
using namespace std; 
 
class Word { 
 public: 
  Word(); 
  Word(const Word& other_word); 
  ~Word() { }
  void SetWord (const string & input_word); 
  string GetWord () const; 
  void WriteData (ostream & output) const; 

 private: 
  string text;  // the word itself
  int vowels;  // vowel counter 
  int consonants;  // consonant counter 
  int digits;  // digit counter 
  int specialchars; // special character counter 
}; 
 
#endif  
