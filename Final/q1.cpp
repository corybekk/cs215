#include <iostream>
#include "q1.h"

using namespace std;

int main(){

  A* myObject;
  cout << myObject->Compute(4);


  return 0;
}
///////////////////////////////////
A::A(){
  my_int =0;
}
A::A(int x){
  my_int = x;
}
A::A(const A& other){
  my_int = other.my_int;
}
int A::Compute(int x){
  cout<<"AAAAA";
  return x;
}
//float A::SquareRoot(){
//}
//////////////////////////////////////
B::B(){
  my_float =0;
}
B::B(int x){
  my_float = x;
}
B::B(int x, int y){
}
B::B(const B& other){
  my_float = other.my_float;
}
void B::PrintMessage(){}
bool B::CanItBeTrue(){}
int B::Compute(int x){
  cout<< "BBBBBBB";
  return x;
}

