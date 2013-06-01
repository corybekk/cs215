#include <iostream>
#include "polygon.h"
#include "LList.tmp.h"

using namespace std;

char menu();
Polygon* create(char choice);

int main() {
   char option;
   float area;
   float perimeter;
   float tota;
   float totp;

   LList<Polygon*> polylist;

   do {
      option = menu();
      Polygon* pp = create(option);
      
      if (pp) {
	polylist.InsertLast(pp);
      }
   } while (option != 'Q');

   for(LList<Polygon*>::Iterator itr =polylist.begin(); itr!= polylist.end(); itr++){

     cout<<*(*itr);

     area=(**itr).Area();
     perimeter=(**itr).Perimeter();
     tota += area;
     totp +=perimeter;
   }
   cout<<"the total area is :"<<tota<<endl;
   cout<<"the total perimeter is :"<<totp<<endl;

   return 0;
}

char menu() {
   char choice;
   cout << "Select one of the following options:\n";
   cout << "\ta. Create an equilateral triangle\n";
   cout << "\tb. Create a right triangle\n";
   cout << "\tc. Create a Scalene triangle\n";
   cout << "\td. Create a square\n";
   cout << "\te. Create a Rectangle\n";
   cout << "\tf. Create a regular polygon\n";
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
     case 'D':
         cout<<"Enter the length of the side of the square: ";
         cin>>side;
         pp = new Square(side);
     case 'E':
         cout<<"Enter the length of the 1st side: ";
         cin>>side;
         cout<<"Enter the length of the 2nd side: ";
         cin>>side1;
         pp = new Rectangle(side,side1);
         break;
      case 'F':
         cout<<"Enter the number of sides of the polygon: ";
         cin>>side;
         cout<<"Enter the length of the polygon sides: ";
         cin>>side1;
         pp = new Regular(side,side1);
         break;
     case 'Q':
         cout << "Bye!\n";
         break;
      default:
         cout << "Invalid option - please try again\n";
   }
   return pp;
}

