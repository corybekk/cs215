/* Implementation of the DynArr class.
   This class implements a dynamic, resizable array of ints. */

#include "dynarr.h" 

/* Default constructor:
 * Initialize object to an empty array with the minimum capacity.
 */ 
DynArr::DynArr() { 
        data = new int [MIN_SIZE]; // allocate array
        capacity = MIN_SIZE; 	// amount of storage
        used = 0; 		// current number of elements
} 

/* Copy constructor:
 * Initialize object as a copy of other object
 * Dynamically allocate array and then copy
 */ 
DynArr::DynArr (const DynArr & other) { 
        data = new int [other.capacity]; 
        for (int i = 0; i < other.used; i++) 
                data[i] = other.data[i]; 
        capacity = other.capacity; 
        used = other.used; 
} 

/* Destructor:
 * Delete dynamically allocated array
 */ 
DynArr::~DynArr () { 
        delete [] data; 
} 

/* Assignment operator:
 * 1. Check to be sure this is not an auto-assignment (e.g. d=d;)
 * 2. Delete the current array
 * 3. Reallocate to match other's size
 * 4. Copy array elements
 * 5. Copy other member data
 */ 
DynArr & DynArr::operator = (const DynArr & other) { 
	// If this is an auto-assignment, we don't want to delete
	// our only copy of the data!  Return immediately.
        if (this == &other) {
                return * this; 
	}

	// Deallocate and reallocate
        delete [] data; 

        data = new int [other.capacity]; 

	// Copy data elements one by one
        for (int i = 0; i < other.used; i++) {
                data[i] = other.data[i]; 
	}

	// Copy other member variables
        capacity = other.capacity; 
        used = other.used; 
        return * this; 
} 

/* Define the equality operator for this class
 * 2 arrays are considered equal if they have the same number of elements
 * and the elements match
 * (regardless of their capacity -- the user of this class doesn't care
 * about that implemenation detail)
 */ 
bool DynArr::operator == (const DynArr & other) const { 
        if (used != other.used) {
                return false; 
	}

	// Check element by element
	// If there is a single pair of mismatched elements, exit immediately
        for (int i = 0; i < used; i++) {
                if (data[i] != other.data[i]) {
                        return false; 
		}
	}
        return true; 
} 

// Accessor function for capacity 
int DynArr::Capacity () const { return capacity; } 

// Accessor function for number used 
int DynArr::Used () const { return used; } 

// Overloaded output stream operator
// Print all elements of arr
// Friend function, so can access arr's private data
ostream & operator << (ostream & outs, const DynArr & arr) { 
        for (int i = 0; i < arr.used; i++) {
                outs << arr.data[i]; 
	}
        return outs; 
} 

// Insert value into the dynamic array
// STUB - you will complete this 
bool DynArr::Insert (const int value) { 
  
  // if(used >= capacity){// checks if the array is completely full of values
    
    //    DynArr *n = new DynArr; //allocate new space
    //    if(n=NULL)return false;
    //    n->capacity= capacity+GROWTH_FACTOR;// create a new array size
    //    capacity=n->capacity;    
    //    data[used+1]=value;    
    //    used++;
    //    return true;
  
  int size;
  
  if(used >= capacity){// checks if the array is completely full of values
    
    size = capacity * GROWTH_FACTOR; // creates a new size for array
    
    int *n=new int[size]; // allocates the new size
    if(size=NULL)return false;
    for(int i = 0; i < used; i++){
      n[i]=data[i];
    }
    
    data=n;
    delete[]n;
    capacity++;
  }

  data[used+1]=value;
  used++;
  return true;
}



  
// data[used+1]=value;
// used++;
//return true;
//}

// Delete value from the dynamic array
// STUB - you will complete this 
bool DynArr::Delete (const int value) {
        return false;  // change this
} 
 

