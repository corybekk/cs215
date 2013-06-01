 // preprocessor directives -- keep us from including this file twice
#ifndef WORD_H
#define WORD_H
 
#include <cstring> 
#include <string> 
#include <iostream> 
#include <iomanip> 
 
using namespace std; 
 
class Word { 
 public: 
  Word(); 
  Word(const Word& other_word); 
  ~Word();
   void SetWord (const string & input_word); 
   string GetWord () const; 
   Word& operator = (const Word& other_word);
   bool operator == (const Word& other_word) const;
   bool operator < (const Word& other_word) const;
   Word operator + (const Word& other_word) const;
   friend istream& operator >> (istream& ins, Word& w);
   friend ostream& operator << (ostream& outs, const Word& w);

private: 
   char* text;  // the word itself
   int vowels;  // vowel counter 
   int consonants;  // consonant counter 
   int digits;  // digit counter 
   int specialchars; // special character counter 
}; 
 
#endif  
