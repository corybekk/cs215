#include <iostream>
#include "q2.h"
using namespace std;

int main(){
  student *ptr[3];

  ptr[0]= new student("Meg Griffin", 1700);
  ptr[1]= new StudentWorker("Bob Saget", 0, 200);
  ptr[2]= new StudentWorker("John Stamos", 1500, 100);

  cout<<ptr[0]->NewOwedToStudent()<<endl;
  cout<<ptr[1]->NewOwedToStudent()<<endl;
  cout<<ptr[2]->NewOwedToStudent()<<endl;

  return 0;
}
