#include <iostream>
using namespace std;

  bool CheckLetter(string s);

int main(){

  string word;
  cout<<"enter a word pls ";
  cin>>word;
  cout<< CheckLetter(word);
 
  return 0;
}

bool CheckLetter(string s){

  int stringL;
  int i=0;
  int n=0;
  char array[100];

  stringL =  s.length(); 
  while(i<stringL){
    array[i]=i;
    i++;
  }  

  for( int i=0; i<stringL; i++){

    if(array[i]== 'c' or array[i]== 'a' or array [i]== 't') 
      n++;
    if( n == 2)return true;
  }

  return false;
}
