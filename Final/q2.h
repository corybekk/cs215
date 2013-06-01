#include <iostream>
using namespace std;

class student { 

 public:
  student();
  student(string NAME, int FEES);
  student(student & other);
  int virtual NewOwedToStudent();
 protected:
  string name;
  int fees;
};
class StudentWorker : public student {
 public:
  StudentWorker();
  StudentWorker(string NAME, int FEES, int WAGE);
  StudentWorker(StudentWorker & other);
  int NetOWedToStudent();
 private:
  int weekly_wage;

};
///////////////////////////////////////////////
student::student(){
  name = "Bob Saget";
  fees = 0;
}
student::student(string NAME, int FEES){
  name = NAME;
  fees = FEES;
}
student::student(student & other){
  name = other.name;
  fees = other.fees;
}
int student::NewOwedToStudent(){
  cout<<name<<endl;
  return fees * -1;
}
//////////////////////////////////////////////
StudentWorker::StudentWorker(){
  weekly_wage =0;
  name = "Bob Saget"; // has to be "protected"
  fees = 0;
}
StudentWorker::StudentWorker(string NAME, int FEES, int WAGE){
  name = NAME;
  fees = FEES;
  weekly_wage=WAGE;
}
StudentWorker::StudentWorker(StudentWorker & other){
  weekly_wage= other.weekly_wage;
}
int StudentWorker::NetOWedToStudent(){
  cout<<name<<endl;
  return fees-(weekly_wage * 16);
}
/////////////////////////////////////////////////
