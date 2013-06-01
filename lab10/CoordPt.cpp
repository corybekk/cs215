#include "CoordPt.h" 
#include <cmath> 
using namespace std; 

// Overloaded assignment operator 
// For the existing object, x will be set to Other.x 
// and y will be set to Other.y. 
CoordinatePoint & CoordinatePoint::operator = (const CoordinatePoint & Other) { 
        x = Other.x; 
        y = Other.y; 
        return *this; 
} 

// Overloaded addition operator
// Postcondition: the sum of *this and Other will be 
// calculated and returned. 
CoordinatePoint CoordinatePoint::operator + (const CoordinatePoint & Other) const { 
        int xvalue = x + Other.x; 
        int yvalue = y + Other.y; 
        return CoordinatePoint (xvalue, yvalue); 
} 

// Overloaded input operator 
// The contents of p will be read from the input stream - 
// input will be in the format (x,y) - where x and y are integer values. 
// The parenthesis and comma will are required but will not be stored - 
// the fail flag will be set if the input format is incorrect. 
istream & operator >>  (istream & input, CoordinatePoint & p) { 
        char left_par, comma, right_par;

	// Read in left paren
        input >> left_par;

	// Set fail bit if unsuccessful
	if (left_par != '(') {
		input.setstate(input.rdstate() | ios_base::failbit);
	}

	// Read x coordinate
	input >> p.x;

	// Read comma
        input >> comma;
	if (comma != ',') {
		input.setstate(input.rdstate() | ios_base::failbit);
	}

	// Read y coordinate
	input >> p.y;

	// Read right parenthesis
	input >> right_par;
	if (right_par != ')') {
		input.setstate(input.rdstate() | ios_base::failbit);
	}

        return input; 
} 

// Overloaded output operator 
// The contents of p will be sent to the output stream 
// using the format (x,y) where x and y are the x and y coordinates 
// of p. 
ostream & operator <<  (ostream & output, const CoordinatePoint & p) { 
        output << '(' << p.x << ',' << p.y << ')'; 
        return output; 
} 

// Magnitude function
// Returns the distance from *this to the origin (0, 0)
// using the Pythagorean Theorem
float CoordinatePoint::Magnitude () const { 
        return sqrt (x * x + y * y); 
} 

// Distance function
// Calculates and returns the distance from *this to Other using the
// Pythagorean Theorem 
float CoordinatePoint::Distance (const CoordinatePoint & Other) const { 
        float deltax = x - Other.x; 
        float deltay = y - Other.y; 
        return sqrt (float (deltax * deltax + deltay * deltay)); 
} 
