#include "LList.h" 

// Default constructor for the LNode class
// Create a new node with data=0 and no next node
LList::LNode::LNode () { 
        data = 0; 
        next = NULL; 
} 

// Default constructor for the LList class
// Create an empty list 
LList::LList () { 
        first = NULL; 
        size = 0; 
}

// Copy constructor for the LList class 
// Copy the other list, element by element
LList::LList (const LList & other) { 
        first = NULL; 
        size = 0; 
        for (LNode * n = other.first; n != NULL; n = n->next) {
                InsertLast (n->data); 
	}
} 

// Destructor for the LList class
// Delete from the beginning of the list until the list is empty
LList::~LList () { 
	while (first != NULL) {
		DeleteFirst(); 
	}
} 

// Overloaded assignment operator
LList& LList::operator = (const LList & other) {

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
} 

// Equality operator
// For two lists to be equal, they must have exactly the same elements 
bool LList::operator == (const LList & other) const { 

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
int LList::Size () const { 
        return size; 
} 

// Print the list 
ostream & operator << (ostream & outs, const LList & L) { 
        if (L.first == NULL) {
                return outs;
	}
        outs << L.first->data; 
        for (LList::LNode * n = L.first->next; n != NULL; n = n->next) {
                outs << ' ' << n->data;
	} 
        return outs; 
} 

// Insert "value" at the beginning of the list 
bool LList::InsertFirst (const int & value) {

  LNode * ptr = new LNode;
  if(ptr==NULL)return false;
  ptr->data = value;
  ptr->next = first;
  first = ptr;
  size++;
  return true; 
} 

// Insert "value" at the end of the list 
bool LList::InsertLast (const int & value) {

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
bool LList::DeleteFirst () { 

  if(size==0)return false;
  LNode *tmp = first->next;// make tmp become the first node pointing to the next node
  delete first;// delete the original first node now that tmp is the new first node
  first=tmp;// reset the first node to now equal tmp 
  size--;//reduce the size because the old first node was deleted
  return true;
} 

// Delete the element at the end of the list 
bool LList::DeleteLast () {
  
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

