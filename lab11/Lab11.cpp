#include <iostream>
#include "polygon.h"

using namespace std;

char menu();
Polygon* create(char choice);

int main() {
   char option;
   do {
      option = menu();
      Polygon* pp = create(option);
      
      if (pp) {
         cout << *pp;
         delete pp;
      }

   } while (option != 'Q');
   return 0;
}

char menu() {
   char choice;
   cout << "Select one of the following options:\n";
   cout << "\ta. Create an equilateral triangle\n";
   cout << "\tb. Create a right triangle\n";
   cout << "\tc. Create a Scalene triangle\n";
   cout << "\tq. Exit\n";
   cin >> choice;
   return toupper(choice);
}

Polygon* create(char choice) {
   Polygon* pp = NULL;

   switch(choice) {
      case 'A':
         int side;
         cout << "Enter the length of the side of the "
              << "equilateral triangle: ";
         cin >> side;
         pp = new Equilateral (side);
         break;
      case 'B':
         int side1, side2;
         cout << "Enter the length of one leg of the "
              << "right triangle: ";
         cin >> side1;
         cout << "Enter the length of the other leg of the "
              << "right triangle: ";
         cin >> side2;
         pp = new Right(side1, side2);
         break;
     case 'C':
         cout<<"Enter the length of the 1st side: ";
	 cin>>side;
	 cout<<"Enter the length of the 2nd side: ";
	 cin>>side1;
	 cout<<"Enter the length of the 3rd side: ";
	 cin>>side2;
	 pp = new Scalene(side,side1,side2);
	 break;
     case 'Q':
         cout << "Bye!\n";
         break;
      default:
         cout << "Invalid option - please try again\n";
   }
   return pp;
}

