/* 
 * Name: Cory Bekker
 * CS 215 Lab 5
 * Describe the program here:
 */
#include <iostream> 
#include <cctype>
#include <iomanip> 
#include <fstream> 
#include <string> 
#include "lab05.h" 
#include <sstream> 
using namespace std; 
 

bool isVowel(char input);
bool isConsonant(char input1);
bool isSpecial(char input2);
bool isDigit(char input3);

const int MAX = 100; 	// upper bound on the number of words
const string filename="words.txt"; // name of input file
 
int main () { 
        // Open file for input 
        ifstream input(filename.c_str());
 
        string inword; 	// tmp for reading a word from the file
        Word words[MAX]; // our list of words (as an array of Word objects)
	int num_words = 0; // counter of words read

        // Read until array is filled or end of file is found 
        while (num_words < MAX && input >> inword) { 
                // Insert word into array 
                words[num_words].SetWord(inword); 
                // Increment counter 
                num_words++;
        } 

        // Close inout file 
        input.close(); 

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
                words[i].WriteData(cout); 
        } 
        return 0; 
}
/////////////////////////////////////////////////////////////////
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

  text = "''''";
  vowels =0;
  consonants =0;
  digits =0;
  specialchars =0;
}
//The copy constructors parameter is called other_word which is a string.
//it also has to be a const so it doesnt get changed
//it is called whenever a new variable is created from an object. 
Word::Word(const Word& other_word){
  
  text = other_word.text;
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

  text=input_word;
  
  for(int i=0; i<text.length(); i++){// creates an array
    
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
//this function prints out the number of vowels, constonants...ect to the
//screen. the paramerters are ostream outs because it is going to be sent
//to the screen. 
void Word:: WriteData(ostream& outs) const{

  cout << setw (12) << left << text;
  cout << setw (8) << right << vowels;
  cout << setw (8) << right << consonants;
  cout << setw (8) << right << digits;
  cout << setw (8) << right << specialchars;
  cout<<"\n";
}

string Word::GetWord () const{

  return text;
}
/////////////////////////////////////////////////////////////////////////////////
