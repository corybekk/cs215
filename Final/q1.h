
#include <iostream>

using namespace std;

class A {
 public:
  A();
  A(int x);
  A(const A& other);
  virtual void PrintMessage()= 0;
  virtual int Compute(int x); // Version A
  //  virtual float SquareRoot();
 private:
  int my_int;
};
    class B : public A {
    public:
      B();
      B(int y);
      B(int x, int y);
      B(const B& other);
      virtual bool CanItBeTrue();
      virtual void PrintMessage();
      virtual int Compute(int x); // Version B
    private:
      float my_float;
};

