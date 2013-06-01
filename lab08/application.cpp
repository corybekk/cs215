// Description: This program is designed to test the DynArr class. 
#include <cstdlib> 
#include <iostream> 
#include <fstream> 
#include "dynarr.h" 
 
using namespace std; 
 
int main (int argc, char * argv[]) { 
        DynArr AL; 
        char action; 
        int value; 
	
	// --- Process command-line arguments and open input file
        if (argc < 2) { 
                cerr << "Usage: " << argv[0] << " <file-name>\n"; 
                exit (1); 
        } 
        ifstream ins (argv[1]); // Open file
        if (ins.fail ()) { 
                cerr << "No file " << argv[1] << " found\n"; 
                exit (2); 
        } 
 
 
	// --- Read lines from input file
	// Each line is a command.
        while (ins >> action) {
            switch (action) { 
                case 'C' : cout << AL.Capacity() << endl; 
                           break; 
                case 'D' : ins >> value; 
                           if (AL.Delete (value)) 
                                cout << value << " deleted from list\n"; 
                           else 
                                cout << value << " not deleted from list\n"; 
                           break; 
                case 'I' : ins >> value; 
                           if (AL.Insert (value)) 
                                cout << value << " inserted in list\n"; 
                           else 
                                cout << value << " not inserted in list\n"; 
                           break; 
                case 'U' : cout << AL.Used() << endl; 
                           break; 
                case 'W' : cout << AL << endl; 
                           break; 
                default :  cout << action << " is not a valid option\n"; 
            }
	} 
        return 0; 
} 
