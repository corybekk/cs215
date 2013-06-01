/* Lab 9b application program
 * Description: this program creates and sorts a vector
 * of Word objects.
 *
 * It expects one command-line input: the name of a text file
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "word.h"

using namespace std;

void OpenInputFile(int argc, char* argv[], ifstream& input);

int main(int argc, char* argv[]) {
   ifstream input;  // For reading input file
   vector<Word> words; // Stores the words in the file
   Word tmp;        // Temp storage for a single word
   OpenInputFile(argc, argv, input);

   // Read words from the file
   while (input >> tmp) {
      words.push_back(tmp); // insert word into vector
   }
   input.close();

   // Sort the vector into ascending order
   sort(words.begin(), words.end());
   
   // Print the vector of Word objects using an index
   for (int i=0; i < words.size(); i++) {
      cout << words[i]; 
   }
   cout << endl << endl;

   // Sort the Word objects in descending order
   sort(words.rbegin(), words.rend());

   // Print the vector of Word objects using an iterator
   for (vector<Word>::iterator itr  = words.begin();
        itr != words.end();
        itr++) {
      cout << *itr;
   } 
   cout << endl << endl;

   return 0;
}

/* Function: OpenInputFile
 * This function will attempt to open the file
 * whose name was provided as a command-line argument
 * to the program.
 *
 * Parameters: argc and argv (straight from main),
 * an ifstream
 *
 * Function will exit with error if:
 * - the user did not provide exactly one command-line
 *   argument
 * - the user did not provide the name of a valid
 *   file that can be opened for reading
 *
 * Otherwise, the function will use the ifstream
 * variable to open the file.
 */
void OpenInputFile(int argc, char* argv[], ifstream& input) {
   if (argc != 2) {
      cerr << "Error: you should provide exactly one command-line "
           << "argument.\n";
      exit(1);
   }
   input.open(argv[1]);
   if (input.fail()) {
      cerr << "Error: " << argv[1] << " could not be opened for reading.\n";
      exit(1);
   }
}
