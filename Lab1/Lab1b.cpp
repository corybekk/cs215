#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;

int main (){

  ifstream myfile;
  string file;

  myfile.open("words.txt");

  if(myfile.fail()){
    cout << "cannot find file" <<endl;
    exit(1);
  }

  int i =0;
  while(myfile >> file){
  i++;

 }

  cout << "there are " << i << " words" <<endl<<endl;  
  cout << "cory bekker" << endl;
  cout << "arturo bravo" << endl;

  return 0;
}
