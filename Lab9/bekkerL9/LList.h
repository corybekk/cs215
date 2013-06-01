#ifndef LLIST_H 
#define LLIST_H 

/* Class implementing a linked list of integers. */
 
#include <iostream> 
using namespace std; 
 
class LList { 
    private: 
	
	/* Class for a single node of the list.
 	 * Private because it's an implementation detail of LList.
 	 */
        class LNode { 
            public: 
                LNode (); 
                int data; // the actual data being stored
                LNode * next; // a pointer to the next node
        }; 
 
    public: 
        LList (); 
        LList (const LList & other); 
        ~LList (); 
        LList & operator = (const LList & other); 
        bool operator == (const LList & other) const; 
        int Size () const; 
        friend ostream & operator << (ostream & outs, const LList & L); 

	// Insert a value at the beginning of the list
        bool InsertFirst (const int & value); 

	// Insert a value at the end of the list
        bool InsertLast (const int & value); 

	// Delete the value at the beginning of the list
        bool DeleteFirst (); 

	// Delete the value at the end of the list
        bool DeleteLast (); 
    private: 
        LNode * first; // a pointer to the first node in the list
        int size; // the number of elements in the list
}; 
 
#endif 
 

