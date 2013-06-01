#ifndef LLIST_H 
#define LLIST_H 

/* Class implementing a linked list of integers. */
 
#include <iostream> 
using namespace std; 
 
template <class T> class LList;
 
template <class T> ostream & operator << (ostream & outs, const LList<T> & L);
 
template <class T>


class LList { 
    private: 
	
	/* Class for a single node of the list.
 	 * Private because it's an implementation detail of LList.
 	 */
        class LNode { 
            public: 
                LNode (); 
                T data; // the actual data being stored
                LNode * next; // a pointer to the next node
        }; 
 
    public: 
        LList (); 
        LList (const LList & other); 
        ~LList (); 
        LList & operator = (const LList & other); 
        bool operator == (const LList & other) const; 
        int Size () const; 
        friend ostream & operator << <> (ostream & outs, const LList<T> & L); 

	// Insert a value at the beginning of the list
        bool InsertFirst (const T & value); 

	// Insert a value at the end of the list
        bool InsertLast (const T & value); 

	// Delete the value at the beginning of the list
        bool DeleteFirst (); 

	// Delete the value at the end of the list
        bool DeleteLast (); 

	  class Iterator {
	  public:
	    Iterator();
	    Iterator(LNode* NP);
	    const T operator* () const;
	    Iterator operator++();
	    Iterator operator++(int);
	    bool operator== (const Iterator& other) const;
	    bool operator!= (const Iterator& other) const;
	  private:
	    LNode* current;
	  };

	  Iterator begin() const;
	  Iterator end() const;
	  
         private: 
	  LNode * first; // a pointer to the first node in the list
	  int size; // the number of elements in the list
}; 
 
 
// Default constructor for the LNode class
// Create a new node with data=0 and no next node
template <class T>
LList<T>::LNode::LNode () { 
  //data = 0; 
        next = NULL; 
} 

// Default constructor for the LList class
// Create an empty list
template <class T> 
LList<T>::LList () { 
        first = NULL; 
        size = 0; 
}

// Copy constructor for the LList class 
// Copy the other list, element by element
template <class T>
LList<T>::LList (const LList<T> & other) { 
        first = NULL; 
        size = 0; 
        for (LNode * n = other.first; n != NULL; n = n->next) {
                InsertLast (n->data); 
	}
} 

// Destructor for the LList class
// Delete from the beginning of the list until the list is empty
template <class T>
LList<T>::~LList () { 
	while (first != NULL) {
		DeleteFirst(); 
	}
} 

// Overloaded assignment operator
template <class T>
LList<T>& LList<T>::operator = (const LList<T> & other) {// was before LList& LList

	// Check for auto-assignment 
        if (this == &other) {
                return * this; 
	}
        while (first != NULL) {
                DeleteFirst();
	}
        for (LNode * n = other.first; n != NULL; n = n->next) {
                InsertLast (n->data);
	}
	 return * this; 
	//return LList<T>;
} 

// Equality operator
// For two lists to be equal, they must have exactly the same elements 
template <class T>
bool LList<T>::operator == (const LList<T> & other) const { 

	// If the sizes are not equal, the lists are
	// not equal
        if (size != other.size) {
                return false; 
	}

	// Pointers for traversing the two lists
        LNode * n = first; 
        LNode * m = other.first; 

        while (n != NULL) {
                if (n->data != m->data) {
                        return false;
		}
                n = n->next; 
                m = m->next; 
        } 
        return true; 
} 

// Accessor function for size 
template <class T>
int LList<T>::Size() const {// use to be "int LList" 
        return size; 
} 

// Print the list
//class LList<T>::LNode
template <class T> 
ostream & operator << (ostream & outs, const LList<T> & L) { 
        if (L.first == NULL) {
                return outs;
	}
        outs << L.first->data; 
        for (class LList<T>::LNode * n = L.first->next; n != NULL; n = n->next) {
                outs << ' ' << n->data;
	} 
        return outs; 
} 

// Insert "value" at the beginning of the list 
template <class T>
bool LList<T>::InsertFirst (const T& value) {

  LNode * ptr = new LNode;
  if(ptr==NULL)return false;
  ptr->data = value;
  ptr->next = first;
  first = ptr;
  size++;
  return true; 
} 

// Insert "value" at the end of the list 
template <class T>
bool LList<T>::InsertLast (const T& value) {

  if(size==0)return InsertFirst(value);

  LNode * ptr = new LNode;
  if(ptr==NULL)return false;
  ptr->data = value;
  ptr->next = NULL;// the new node points to null because it is the last pointer

  LNode *tmp = new LNode;// create a new node to travers down the node list 
  tmp = first;
  while(tmp->next!=NULL){
    tmp=tmp->next;// last node in the list
  }
  tmp->next=ptr;// takes the last pointer and has it point to the new node
  size++;// since a node was added, it increases the size 
  
  return true; 
}

// Delete the element at the beginning of the list 
template <class T>
bool LList<T>::DeleteFirst () { 

  if(size==0)return false;
  LNode *tmp = first->next;// make tmp become the first node pointing to the next node
  delete first;// delete the original first node now that tmp is the new first node
  first=tmp;// reset the first node to now equal tmp 
  size--;//reduce the size because the old first node was deleted
  return true;
} 

// Delete the element at the end of the list 
template <class T>
bool LList<T>::DeleteLast () {
  
  if(size==0)return false;
  if(size==1)return DeleteFirst();// if there is only one element, no need to find the
                            //last position.. all you have to do is call "DeleteFirst"/
  LNode *tmp = first;
  
  while(tmp->next->next!=NULL){// must find the 2nd to last element...tmp->next->next
    tmp =tmp->next; // this is the 2nd to last postion
  }
  
  delete tmp->next;// this is the next postion... which is the last node. 
  tmp->next = NULL;// this is the new last node... which should be pointing at null. 
  size--;
  return true;
} 


#endif
/* Iterator function definitions - not a standalone file */

template <class T>
LList<T>::Iterator::Iterator() { current = NULL; }

template <class T>
LList<T>::Iterator::Iterator(LNode* NP) { current = NP; }

template <class T>
const T LList<T>::Iterator::operator * () const { return current->data; }

template <class T>
class LList<T>::Iterator LList<T>::Iterator::operator++() {
	current = current->next;
	return *this;
}

template <class T>
class LList<T>::Iterator LList<T>::Iterator::operator++(int) {
	Iterator tmp = *this;
	current = current->next;
	return tmp;
}

template <class T>
bool LList<T>::Iterator::operator== (const Iterator& other) const {
	return current == other.current;
}

template <class T>
bool LList<T>::Iterator::operator!= (const Iterator& other) const {
	return current != other.current;
}

template <class T>
class LList<T>::Iterator LList<T>::begin() const {
	Iterator tmp(first);
	return tmp;
}

template <class T>
class LList<T>::Iterator LList<T>::end() const {
	Iterator tmp;	// it's NULL
	return tmp;
}

