// Author: Cory Bekker
// Class: cs215
// Lab2 
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool isVowel(char input);
bool isConsonant(char input1); 
bool isSpecial(char input2);

const int num = 1024;

int main (){

  char arrV[num];
  char arrC[num];
  char arrD[num];
  char arrS[num];

  ifstream myfile;
  char file;
  string file1; // string to count words in a file

  myfile.open("words.txt");

  if(myfile.fail()){
    cout << "cannot find file" <<endl;
    exit(1);
}

  int special =0;
  int digits =0;
  int consonants =0; 
  int vowels =0;
  int words =0;
  int size = 0;
  int v=0; // each array must have its own index
  int c=0;
  int s=0;
  int d=0;

  ///////////////////////////////////////////////////////
  while(myfile>>file1){
    words++;
  }
  myfile.close();
  // must reopen file

  myfile.open("words.txt");

  while(myfile>>file){ 

      if(isVowel(file)){
      arrV[v]=file; //reads each char in the file and..
      v++;         // puts it into the correct index.
      vowels++;
  }
 
  if(isConsonant(file)){
       arrC[c]=file;
       c++;
       consonants++;
  }

  if(isSpecial(file)){ 
       arrS[s]= file;
       s++;
       special++;
  }
  if(isdigit(file)){ 
    arrD[d]=file;
    d++;
    digits++; 
  }  
    
  }

  /////////////////////////////////////////////////////
    cout << "words: " << words << endl;
    cout << "Vowels: " << vowels << endl;//prints out vowels from vowels++
    cout << "Consonants: " << consonants << endl;// 
    cout << "Digits: " << digits << endl;
    cout << "Special Characters: " << special << endl;
    cout<< endl;
  ////////////////////////////////////////////////////////////
  cout<<"The list of vowels: "; // prints out all the vowels  
  for(int i=0; i<v; i++){// i<v; because I dont want it to print out 
    cout<<arrV[i];       //random garbage at higher index(s) 
  }
  cout << endl;// keeps it nice and tidy 

  cout<<"The list of consonants: ";
  for(int i=0; i<c; i++){
    cout<<arrC[i];
  } 
  cout << endl;

  cout<<"The list of digits: ";
  for(int i=0; i<d; i++){
    cout<<arrD[i];
  }
  cout << endl; 

  cout<<"The list of special characters: ";
  for(int i=0; i<s; i++){
    cout<<arrS[i];
  }
  cout<<endl;    

return 0;
}
////////////////////////////FUNCTIONS////////////////////////////////////////
bool isVowel(char input){
     
   char vowel = tolower (input); 
   return(vowel=='a' or vowel=='e' or vowel =='i' or vowel =='o' or vowel == 'u');
}

bool isConsonant(char input1){
   char letter = tolower (input1); 
   if(isVowel(letter)or!isalpha(letter))return false;
   return true;
}

bool isSpecial(char input2){
   char special = tolower (input2);
   if(isalpha(special) or isdigit(special) or isspace(special)) return false;
   return true;
}


