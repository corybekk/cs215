#ifndef LLIST2_HT
#define LLIST2_H 

// Doubly linked list class
 
#include <iostream> 
using namespace std; 
 
class LList { 
    private: 
        class LNode { 
            public: 
                LNode (); 
                int data; 
                LNode * next; 
                LNode * prev; 
        }; 
 
    public: 
        LList (); 
        LList (const LList& other); 
        ~LList (); 
        LList & operator = (const LList & other); 
        bool operator == (const LList & other) const; 
        int Size () const; 
        friend ostream & operator << (ostream & outs, const LList & L); 
        bool InsertFirst (const int & value); 
        bool InsertLast (const int & value); 
        bool DeleteFirst (); 
        bool DeleteLast (); 
    private: 
        LNode * first; 
        LNode * last; 
        int size; 
}; 
#endif
