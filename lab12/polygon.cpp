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
//===============================================================
Regular::Regular() {
  num_sides = 0;
}

Regular::Regular(const Regular& p) {
  num_sides = p.num_sides;
}
Regular::Regular(int N, double S){

  num_sides=N;
  side=S;
}
Regular::~Regular() { }

Regular& Regular::operator = (const Regular& p) {
   return *this;
}

int Regular::Sides() const {
   return num_sides;
}

double Regular::Area() const {
 
  float radius;
  float area;
  float pi = 3.14159265; 

  /*  SIDE=  side * side; 
  SIDE1= .25 * num_sides;
  SIDE2= SIDE * SIDE2;
  SIDE3= 3.14159265 / num_sides;
  SIDE4= 1/tan(SIDE3);
  SIDE5= SIDE4 * SIDE2;
  */
  radius = ((side)/(2*sin(pi/num_sides)));
  area = (.5 * num_sides * (radius*radius) *sin((2*pi)/num_sides));

  return area;
}

double Regular::Perimeter() const {
  
  return side * num_sides;
}
//==================================================================
Square::Square(){

  side=0;
}
Square::Square(double S1){

  side =S1;
}
Square::Square(const Square& p){

  side=p.side;
}
Square::~Square(){}

Square& Square::operator =(const Square& p){
  return *this;
}

double Square::Area()const{

  return side * side;
}
double Square::Perimeter()const{

  return side * 4;
}
//===================================================================
Rectangle::Rectangle(){

  side = side2 =0;
}
Rectangle::Rectangle(double S1, double S2){
  side= S1;
  side2=S2;
}
Rectangle::Rectangle(const Rectangle& p){
  side= p.side;
  side2= p.side2;
}
Rectangle::~Rectangle(){}

Rectangle& Rectangle::operator =(const Rectangle& p){

  return *this;
}
double Rectangle::Area()const{

  return side * side2;
}
double Rectangle::Perimeter()const{

  int length;
  int width;

  length = side + side;
  width = side2 + side2;

  return length + width;
}
//=====================================================================
