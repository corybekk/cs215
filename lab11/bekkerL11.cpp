#include <iostream>
#include <cmath>
#include "polygon.h"

using namespace std;

Polygon::Polygon() {
   side = 0;
}

Polygon::Polygon(const Polygon& p) {
   side = p.side;
}

Polygon& Polygon::operator = (const Polygon & p) {
   side = p.side;
   return * this;
}

ostream& operator << (ostream & outs, const Polygon & P) {
   outs << "The area of your " << P.Sides() 
        << " sided polygon is " << P.Area () 
        << "; its perimeter is " << P.Perimeter() << ".\n";
   return outs;
}


Triangle::Triangle () {
   side = 0;
}

Triangle::Triangle (const Triangle & p) {
   side = p.side;
}

Triangle::~Triangle () { }

Triangle & Triangle::operator = (const Triangle & p) {
   side = p.side;
   return * this;
}

int Triangle::Sides () const {
   return 3;
}

Equilateral::Equilateral () {
   side = 0;
}

Equilateral::Equilateral (double S) {
   side = S;
}

Equilateral::~Equilateral () { }

Equilateral::Equilateral (const Equilateral & p) {
   side = p.side;
}

Equilateral & Equilateral::operator = (const Equilateral & p) {
   side = p.side; return * this;
}

double Equilateral::Area () const {

  double num1;
  double num2;
  double num3;

  
  num1=  pow(side,2);
  num2=  sqrt(3);
  num3= num1 * num2;
  return num3 / 4;

   return 0;
}

double Equilateral::Perimeter () const {

  return side * 3;
}

Right::Right () {
   side = side2 = 0;
}

Right::Right (double S1, double S2) {
   side = S1;
   side2 = S2;
}

Right::~Right () { }

Right::Right(const Right& p) {
   side = p.side;
   side2 = p.side2;
}

Right& Right::operator= (const Right& p) {
   side = p.side;
   side2 = p.side2;
   return* this;
}

double Right::Area() const {

  return (side * side2) / 2;
   
}

double Right::Perimeter() const {

  double num1;
  double num2;
  double num3;
  double num4;

  num1=  pow(side,2);
  num2= pow(side2,2);
  num3 = num1+num2;
  num4= sqrt(num3);

  return num4+side+side2;
}

Scalene::Scalene() {
   side = side2 = side3 = 0;
}

Scalene::Scalene(double S1, double S2, double S3) {
   side = S1;
   side2 = S2;
   side3 = S3;
}

Scalene::~Scalene() { }

Scalene::Scalene(const Scalene& p) {
   side = p.side;
   side2 = p.side2;
   side3 = p.side3;
}

Scalene& Scalene::operator= (const Scalene& p) {
   side = p.side;
   side2 = p.side2;
   side3 = p.side3;
   return *this;
}

double Scalene::Area() const {
   // Calculate and return area here
  double num1;
  double num2;
  double num3;

  num1= pow(side,2) + pow(side2,2) + pow(side3,2);
  num2= pow(side,4) + pow(side2,4) + pow(side3,4);
  num1= pow(num1,2);
  num2= 2 * num2;
  num3= num1 - num2;
  num3= sqrt(num3);
  num3 = .25 * num3;

   return num3;
}

double Scalene::Perimeter() const {
   // Calculate and return perimeter here

   return side + side2 + side3;
}

Quadrilateral::Quadrilateral() {
}

Quadrilateral::Quadrilateral(const Quadrilateral& p) {
}

Quadrilateral::~Quadrilateral() { }

Quadrilateral& Quadrilateral::operator = (const Quadrilateral& p) {
   return *this;
}

int Quadrilateral::Sides() const {
   return 4;
}

Regular::Regular() {
}

Regular::Regular(const Regular& p) {
}

Regular::~Regular() { }

Regular& Regular::operator = (const Regular& p) {
   return *this;
}

int Regular::Sides() const {
   return num_sides;
}

double Regular::Area() const {
   // Calculate and return area here
   return 0;
}

double Regular::Perimeter() const {
   // Calculate and return perimeter here
   return 0;
}

