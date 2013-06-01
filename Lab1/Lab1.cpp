// YOUR NAME GOES HERE: Cory Bekker
// CS 215, Fall 2010, Lab 1
// Problem: 
// Find the difference between the sum of the squares of the first N natural numbers
// and the square of their sums.
//
// Express this difference as a positive number.

#include <iostream>

using namespace std;

const int N = 10;// This is the N referred to in the problem description above.

// ------ PROTOTYPES
// These two functions will help us avoid converting our integers to floating-point and back
// Fill in their definitions below the main program.
long long square_int(long long num);
long long absolute_value_int(long long num);

long long simple();
long long tricky();

// ------ MAIN
int main() {
  cout << "When N = " << N << "..." << endl;
  cout << "The simple approach gives an answer of " << simple() << "." << endl;
  cout << "The tricky approach gives an answer of " << tricky() << "." << endl;

  /* Add some code that compares the two values you just printed and 
     prints a warning if they are not equal. */


  cin.get();
  return 0;
}

// ------ HELPER FUNCTION DEFINITIONS

// Function that computes the square of an integer
// This function should return the square of the value of its input (num)
long long square_int(long long num) {

  return num * num;

}

// Function that computes the absolute value of an integer
// This function should return the absolute value of its input (num)
long long absolute_value_int(long long num) {

  int x = 0;

  if (num < 0)
    x = num * -1;
 else
    x = num;

  return x;
}

// ------ FUNCTIONS TO SOLVE THE PROBLEM
/* This function should use the simple approach we discussed to solve this problem.
 * It should return the computed answer. */
long long simple() {

  long long y =0;
  long long z =0;
  long long answer;
 
   for(int i=0; i<=N; i++)
    {
      y += square_int(i);
    }
   for(int i=0; i<=N; i++)
    {
      z += i;
    }

   z = square_int(z);

    answer = y - z;

 answer = absolute_value_int(answer);

  return answer;

}

/* This function should use the trickier approach we discussed to solve this problem.
 * It should return the computed answer. */
long long tricky() {

  long long difference;
  long long sum_sq;
  long long sq_sum;

  sum_sq = N *(N + 1) * (2 * N + 1)/6;

  sq_sum = N * (N+1)/2;

  sq_sum = square_int(sq_sum);

  difference = sum_sq - sq_sum;

 difference =  absolute_value_int(difference);

  return difference;
}


