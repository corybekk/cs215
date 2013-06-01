// Description: This program is designed to test the LList class. 
#include <cstdlib> 
#include <iostream> 
#include <fstream> 

#ifdef LAB09B
#include "LList.h" 
#else
#include "LList2.h"
#endif 

using namespace std; 
 
int main (int argc, char * argv[]) { 
        LList LL; // linked list
        char action; // action (insert, delete, etc.)
        int value; // value to insert
	
        if (argc < 2) { 
                cerr << "Usage: " << argv[0] << " <file-name>\n"; 
                exit (1); 
        } 
        ifstream ins (argv[1]); 
        if (ins.fail ()) { 
                cerr << "No file " << argv[1] << " found\n"; 
                exit (2); 
        } 
 
        while (ins >> action) {
	   switch (action) { 
                case 'D' : if (LL.DeleteFirst ()) 
                                cout << "First value deleted from list\n"; 
                           else 
                                cout << "First value not deleted from list\n"; 
                           break; 
                case 'E' : if (LL.DeleteLast ()) 
                                cout << "Last value deleted from list\n"; 
                           else 
                                cout << "Last value not deleted from list\n"; 
                           break; 
                case 'I' : ins >> value; 
                           if (LL.InsertFirst (value)) 
                                cout << value << " inserted at front of list\n"; 
                           else 
                                cout << value << " not inserted at front of list\n"; 
                           break; 
                case 'J' : ins >> value; 
                           if (LL.InsertLast (value)) 
                                cout << value << " inserted at end of list\n"; 
                           else 
                                cout << value << " not inserted at end of list\n"; 
                           break; 
                case 'S' : cout << LL.Size() << endl; 
                           break; 
                case 'W' : cout << LL << endl; 
                           break; 
                default :  cout << action << " is not a valid option\n"; 
            }
	} 
        return 0; 
} 
