#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class fraction {

public:
   fraction();

   // Constructor: make a fraction out of a whole number
   fraction(int w);

   // Constructor: make a fraction out of a numerator and denominator
   fraction(int n, unsigned int d);

   // Constructor: make a fraction out of a whole #, numerator, and denominator
   fraction(int w, unsigned int n, unsigned int d);

   ~fraction();

   fraction& operator = (const fraction& other);
   fraction  operator + (const fraction& other) const;

   friend istream& operator >> (istream& ins, fraction&f);
   friend ostream& operator << (ostream& outs, const fraction&f);

private:
   void reduce();

   int whole;
   int numerator;
   int denominator;
};

#endif

















