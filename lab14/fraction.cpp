#include "fraction.h"

fraction::fraction() {
   whole = 0;
   numerator = 0;
   denominator = 1;
}

fraction::fraction(int w) {
   whole = w;
   numerator = 0;
   denominator = 1;
}

fraction::fraction(int n, unsigned d) {
   whole = 0;
   numerator = n;
   denominator = d;
   reduce();
}

fraction::fraction(int w, unsigned n, unsigned d) {
   whole = w;
   numerator = n;
   denominator = d;
   reduce();
}

fraction::~fraction() { }

fraction& fraction::operator = (const fraction& other) {
   whole = other.whole;
   numerator = other.numerator;
   denominator = other.denominator;
   reduce();

   return *this;
}

fraction fraction::operator + (const fraction& other) const {
   fraction sum;

   sum.whole = whole + other.whole;
   sum.numerator = numerator*other.denominator + 
	denominator * other.numerator;
   sum.denominator = denominator * other.denominator;
   sum.reduce();
   return sum;
}

istream& operator >> (istream& ins, fraction& f) {
   char temp;

   ins >> f.whole;
   if (ins.fail()) return ins;

   ins >> f.numerator;
   if (ins.fail()) return ins;

   ins >> temp;
   if (temp != '/') {
      ins.setstate(ins.rdstate() | ios_base::failbit);
      return ins;
   }

   ins >> f.denominator;
   f.reduce();
   return ins;
}

ostream& operator << (ostream& outs, const fraction& f) {
   outs << f.whole << ' ' << f.numerator << '/' << f.denominator;
   return outs;
}

void fraction::reduce() {
   int f = 2;
   denominator = denominator == 0 ? 1 : denominator;
   whole += numerator / denominator;
   numerator %= denominator;
   while (f <= numerator) {
      if ((numerator % f == 0) && (denominator % f == 0)) {
         numerator /= f;
         denominator /= f;
      }
      else {
         f++;
      }
   }
}
