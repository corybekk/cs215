//AUTHOR: CORY BEKKER
//CS215
//PROJECT 1

////////////////////////////////////////////////////////////////////
#include <iostream>      
#include <fstream>
#include <cctype>
#include <ctype.h>

bool checkCaps(char array[]);

const int num = 1000;

using namespace std;

int main(int argc, char* argv[]) {
  
  ////////////checks for argument/////////////////////////////////////////
  if(argc > 2){  
    cout<< "Too man command-line inputs given."<<endl;
    return 0;
  }
  if(argc < 2){
    cout<<"No file name entered."<<endl;
    return 0; 
  }
  
  ifstream file;
  char sentence;
  string sentence1;
  char arr1[num];
  int i =0;
  int max =0;
  //////////CHECKS IF FILE OPENS GOOD///////////////////////////////////////
  file.open(argv[1]);
  
  if(file.fail()){
    cout<<"Could not open file."<<endl;
    file.close();
    return 0;
  }
  /////////////CHECKS SPACES/////////////////////////////////////////////////
  int n =0;
  string arr2[num];
  char next;
  int max1=0;
  int arraysize;
  
  while((next = file.get()) != EOF){

    arr2[n]=next;///// creates array
    n++;
    max1++;//Max size of the array
  }

  int z=0;
  int front_spot = 0;
  int rear_spot = 0;
  
  while(arr2[z] == " " or arr2[z] == "\n" or arr2[z] == "\t" ){
    z++;
    front_spot++;//current spot in the begining of the array

  }


  while(arr2[max1]==" " or arr2[max1] == "\n"){
    max1--;// current spot in the rear of the array

  }
  //////////////PRINTS OUT SENTENCE
  cout<<"Report for sentenec: ";
  for(int n=front_spot; n<max1; n++){
    cout<<arr2[n];
  }
  
  for(int n=front_spot; n<max1; n++){// starts where the first char is in the txt.
    
    if(arr2[n] == " " and arr2[n-1] ==" " or arr2[n]== "\t"){ // checks for...
      cout<<"ERROR: invalid spacing"<<endl;            // extra spaces and tabs.
    }

  }
  ////////close and open file//////////////////////////////////////////////////
  file.close();
  file.open(argv[1]);
  ///////////////creates array of chars////////////////////////////////////////
  while(file >> sentence){
    arr1[i]=sentence;
    max = i++;
  }
  /////////////checks for capital////////////////////////////////////////////
  if(arr1[0] >='a' && arr1[0] <='z'){
    cout<<"ERROR: invalid capitalization"<<endl;   
    
  }
  ////////////checks for period/////////////////////////////////////////////
  if(arr1[max]== '.'){
  }
  
  else {
    cout <<"ERROR: invalid punctuation"<<endl;
  }


  file.close();
  
  return 0;
}






//////////////IGNORE THIS MESS UP/BRAIN STORM CODE PLS/////////////////////

 /*   while(getline(file,sentence1)){
  }
   

      arr2[n]= n;
      cout<<arr2[n]<<endl;
      }*/
   
    //   if(arr2[n]== ' ' and arr2[n-1]== ' '){

    //cout<<"extra space buddy"<<endl;

    //  }


  // }

  /*while(file>>sentence1){
    arr2[n]=sentence1;
    n++;
    }*/
     
  /* for(int n=1; n<=sentence1.length(); n++){

    if(arr2[n]==' ' and arr2[n-1]==' '){
      
    cout<<"extra space buddy"<<endl;
    
    }
  else{ 
    cout<<"didnt work"<<endl;
  }
  }*/

  /*  file.close();
  file.open(argv[1]);    
  
  while(getline(file, sentence1)){

    int i; i++;
    cout<<sentence1<<endl;
    cout<<i<<endl;
  }
  
  file.close();
  */



//checkCaps(argv[], file); // FUNCTION CALL.. Pass file? or infile file?
//while (getline(file, sentence)){
//sentence.length(); // sentence.size(); // ??
//sentence.find('A'); //---> find 'A' in the sentence??
////////////////////function////////////////////
/*bool checkCaps(char array[]){

  char sentence;
  int i=0;

  while(array[i] >> sentence){
    i++;
    cout<<i<<endl;
  }

  if(array[0] >='a' && array[0] <='z'){
    cout<<"ERROR: invalid capitalization";
    return false;
  }

  else{
    return true;
  }
}
*/
