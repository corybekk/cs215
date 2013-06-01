// YOUR NAME GOES HERE: Cory Bekker
// CS 215, Spring 2011, Lab 3
// Problem: 
// See Project Euler, #14

#include <cmath>
#include <iostream>
using namespace std;

const long MAX = 5;
//const int MAX = 50;

// ------ PROTOTYPES
int get_longest_start(int (*chain_length_function)(long));
int iterative_chain_length(long startnum);
int recursive_chain_length(long startnum);
int recursive_tail(long startnum);
int recursive_tail_helper(long startnum, int curr_length);

// ------ MAIN
int main() {

	// Function pointers - will pass to get_longest_start to allow us
	// to compute the chain length in different ways
	int (*iter)(long) = iterative_chain_length;
	int (*rec)(long) = recursive_chain_length;
	int (*tail)(long) = recursive_tail;

	cout << "MAX = " << MAX << endl;
	cout << "Iterative solution: " << get_longest_start(iter) << endl;
	cout << "Recursive solution: " << get_longest_start(rec) << endl;
	cout << "Tail-recursive solution: " << get_longest_start(tail) << endl;
	
	// Uncomment the line of code below if working in DevC++
	// cin.get();
	return 0;
}

// ------ FUNCTION DEFINITIONS

// Computes the maximum chain length over the Collatz sequences
// starting with MAX, MAX-1, ... , 1
// Returns the starting number of the longest sequence
int get_longest_start(int (*chain_length_function)(long)) {
	
	int max_length = 0;	// length of longest chain so far
	int chain_length;	// length of current chain
	int longest_start = MAX; // starting # of longest chain
	
	// Compute all the chains starting at MAX...1
	for (int i=MAX; i >= 1; i--) {
	    chain_length = (*chain_length_function)(i); // use the passed function to compute length
	    if (chain_length > max_length) {
		max_length = chain_length;
		longest_start = i;
	    }

	}
	return longest_start;
}

// Compute the length of the Collatz chain beginning at startnum
// using a loop 
int iterative_chain_length(long startnum) {

  int length_of_sequence = 0;
 
  while(startnum != 1){
    
        if(startnum % 2 == 0){
	  
	  startnum = startnum/2;
	}
	else{
	  startnum = startnum * 3 + 1;
	}
	length_of_sequence++;

  }
  return length_of_sequence;
}
// Compute the length of the Collatz chain beginning at startnum
// using recursion
int recursive_chain_length(long startnum) {

  if(startnum==1)return 1;

  if(startnum % 2 == 0){

    startnum = startnum/2;
  }
  else{
    startnum = startnum * 3 + 1;
  }

  return 1+ recursive_chain_length(startnum);

  
}

// Compute the length of the Collatz chain beginning at startup using tail recursion
int recursive_tail(long startnum) {
	return recursive_tail_helper(startnum, 0);
}


int recursive_tail_helper(long startnum, int curr_length) {
	return 0;
}
/*(startnum = 1)return length_of_sequence;


length_of_sequence++;

        return recursive_chain_length
*/
