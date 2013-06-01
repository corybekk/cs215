#ifndef COORDPT_H 
#define COORDPT_H 
 
#include <iostream> 
using namespace std; 
 
class CoordinatePoint { 
public: 
    // ---- CONSTRUCTORS AND DESTRUCTORS -----

    // Default constructor: creates new object with x=y=0
    CoordinatePoint() : x(0), y(0) { }

    // Alternate constructor: initializes x to x_coord and y to y_coord 
    CoordinatePoint(int x_coord, int y_coord) : x(x_coord), y(y_coord)  { }

    // Copy constructor: initalizes x to Other.x and y to Other.y 
    CoordinatePoint(const CoordinatePoint & Other): x(Other.x), y(Other.y) {}

    // Destructor: does nothing since CoordPt does not dynamically allocate memory 
    ~CoordinatePoint() { }

    // ---- OVERLOADED OPERATORS ----

    // Assignment operator: will set x to Other.x and y to Other.y 
    CoordinatePoint & operator = (const CoordinatePoint & Other); 

    // Addition operator: will return an object with
    // x = this->x + Other.x and y = this->y + Other.y
    CoordinatePoint operator + (const CoordinatePoint & Other) const; 
    
    // Input operator: reads (x, y) from the input stream
    // The parentheses and comma are required but will not be stored
    // Sets the fail flag if input format is incorrect
    friend istream & operator >>  (istream & input, CoordinatePoint & p); 

    // Output operator: prints (x, y) to the output stream 
    friend ostream & operator <<  (ostream & output, const CoordinatePoint & p); 

    // ---- CALCULATION FUNCTIONS ----
    // Returns the point's distance from the origin (0, 0)
    float Magnitude () const; 

    // Returns the point's distance from the other point 
    float Distance (const CoordinatePoint & Other) const; 

private: 
    float x, y; 
}; 
#endif 
