#include <iostream>
using namespace std;

bool divisibleBy3(int x);
int f(int x1);

int main(){

  int input_num = 0;
  cout << "Input a number: ";
  cin >> input_num;
  cout << f(input_num) << endl;
  return 0;
 
}

bool divisibleBy3(int x){

  if(x % 3 == 0)return true;

  else
    return false;
}

int f(int x1){

  if( divisibleBy3(x1)){
    return x1 * x1;
  }
  else{
    return x1 + 1;
  }
}
