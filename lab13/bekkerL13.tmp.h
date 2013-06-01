#ifndef LLIST_H 
#define LLIST_H 

/* Class implementing a linked list of integers. */
 
#include <iostream> 
using namespace std; 
 
template <class T> class LList;
 
template <class T> ostream & operator << (ostream & outs, const LList<T> & L);

template<class T, class Funct> void Forward(LList<T>& L, Funct f);

template<class T, class Funct> void Backward(LList<T>& L, Funct f);
 
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
		LNode * prev;// pointer to prev node
        }; 
 
    public: 
        LList (); 
        LList (const LList & other); 
        ~LList (); 
        LList & operator = (const LList & other); 
        bool operator == (const LList & other) const; 
        int Size () const; 
        friend ostream & operator << <> (ostream & outs, const LList<T> & L); 

	template<class T2, class Funct>
	  friend void Forward (LList<T2>& L, Funct f);
	
	template<class T2, class Funct>
	  friend void Backward (LList<T2>& L, Funct f);

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
	    Iterator operator--();
	    Iterator operator--(int);
	     
	  private:
	    LNode* current;
	  };

	  Iterator rbegin() const;
	  Iterator rend() const;
	  Iterator begin() const;
          Iterator end() const;

         private: 
	  LNode * first; // a pointer to the first node in the list
	  LNode * last;
	  int size; // the number of elements in the list
}; 

//////////////////////////////
template<class T, class Funct>
  void Forward(LList<T>& L, Funct f) {
  for (class LList<T>::LNode * n = L.first; n; n = n->next) f(n->data);
}
//////////////////////////////
template<class T, class Funct>
  void Backward(LList<T>& L, Funct f) {
  for (class LList<T>::LNode * n = L.last; n; n = n->prev) f(n->data);
}
///////////////////////////
template <class T>
class LList<T>::Iterator LList<T>::Iterator::operator--() {
  current = current->prev;
  return *this;
}
/////////////////////////////
template <class T>
class LList<T>::Iterator LList<T>::Iterator::operator--(int) {
  Iterator tmp = *this;
  current = current->prev;
  return *this;
}
// Default constructor for the LNode class
// Create a new node with data=0 and no next node
template <class T>
LList<T>::LNode::LNode () { 
  //data = 0; 
  next = NULL; 
  prev=NULL;
} 

// Default constructor for the LList class
// Create an empty list
template <class T> 
LList<T>::LList () { 
  last = NULL;
  first = NULL; 
  size = 0; 
}

// Copy constructor for the LList class 
// Copy the other list, element by element
template <class T>
LList<T>::LList (const LList<T> & other) { 
  last = NULL;
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

  if(ptr==NULL)return false; //checks to see if it can allocate space
  if(size == 0){
    ptr->next = NULL; // next is null because it is the last node and first node
    ptr->prev = NULL; // prev should be null because it is the first node
    ptr->data = value;
    first = ptr; // makes first point at ptr
    last = ptr; // makes last point at ptr because technically it is the last node
    size++;
    return true;
  }

  LNode * tmp = first;// tmp points to the same thing as first
  ptr->data = value;
  ptr->next = tmp;// makes ptr point to the same node tmp is pointing too, which is 1st
  ptr->prev = NULL;// points at null because it is the 1st node in the list
  tmp->prev = ptr;// makes tmp->next prev pointer point at tmp
  first = ptr;
  size++;
  return true;

} 

// Insert "value" at the end of the list 
template <class T>
bool LList<T>::InsertLast (const T& value) {

  if(size == 0){
    InsertFirst(value);
    return true;
  }

  LNode * ptr = new LNode;

  if(ptr == NULL) return false;

  LNode * tmp = last;// tmp points to the last pointer, which becomes the 2nd to last
  ptr->data = value;
  ptr->next = NULL;// set to null because it is the last node
  tmp->next = ptr; // connects the 2nd to last node to the last node "ptr"
  ptr->prev = tmp; //ptr's prev is pointing to the second to last node
  last = ptr;// last points to ptr, which also means tmp is pointing at the 2nd to lastNod
  size++;
  return true;

}

// Delete the element at the beginning of the list 
template <class T>
bool LList<T>::DeleteFirst () { 

  if(size == 0)return false;
  if(size == 1){
    delete first;
    first = NULL;// basically disconnects the next node, which deletes it
    last = NULL;
    size--;
    return true;
  }

  LNode * tmp;
  tmp = first;// saves what first is pointing to into tmp. "this is the 1st node"
  first = first->next;// makes first point to the 3rd node
  first->prev=NULL; // makes the 2rd Node's "prev" point point to NULL
  delete tmp;
  size--;
  return true;

} 

// Delete the element at the end of the list 
template <class T>
bool LList<T>::DeleteLast () {
  
  if(size==0)return false;
  if(size==1){
    DeleteFirst();
    return true;
  }
  LNode * tmp = last;
  last = last->prev;
  last->next = NULL;
  delete tmp;
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
////////////////////////////////////////////////////
template<class T>
class LList<T>::Iterator LList<T>::rbegin() const{
  Iterator tmp(last); 
  return tmp;
}

template <class T>
class LList<T>::Iterator LList<T>::rend() const {
  Iterator tmp(first->prev);
  return tmp;
}

