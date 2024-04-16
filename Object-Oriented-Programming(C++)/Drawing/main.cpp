#include <iostream>
#include <iomanip>
#include "drawing_shapes.hpp"

using namespace std;

int global_horiz_spaces;

int main() 
{

/*
The following lines of code are simply calling the functions contained within the following soure code files.
The following lines of code are used to test the functionality of the different components within the program;
including: move_right, draw(for several shapes), compute_area, and compute_perimeter. Precision is 5 digits for each of the outputs.
*/
  
move_right(24);
draw(CIRCLE, 2);
move_right(20);
draw(TRIANGLE, 10, 5);
move_right(20);
draw(SQUARE, 10, 0);
move_right(17);
draw(CIRCLE, 16, 0, '.');
move_right(10);
draw(RECTANGLE, 30, 6, '-'); 

cout << "Circle" << endl;
cout << "Area: " << setprecision(5) << compute_area(CIRCLE, 2) << endl;
cout << "Perimeter: " << setprecision(5) << compute_perimeter(CIRCLE, 2) << endl;
cout << endl;

cout << "Triangle" << endl;
cout << "Area: " << setprecision(5) << compute_area(TRIANGLE, 10, 5) << endl;
cout << "Perimeter: " << setprecision(5) << compute_perimeter(TRIANGLE, 10, 5) << endl;
cout << endl;

cout << "Square" << endl;
cout << "Area: " << setprecision(5) << compute_area(SQUARE, 10, 0) << endl;
cout << "Perimeter: " << setprecision(5) << compute_perimeter(SQUARE, 10, 0) << endl;
cout << endl;

cout << "Circle" << endl;
cout << "Area: " << setprecision(5) << compute_area(CIRCLE, 16, 0) << endl;
cout << "Perimeter: " << setprecision(5) << compute_perimeter(CIRCLE, 16, 0) << endl;
cout << endl;

cout << "Rectangle" << endl;
cout << "Area: " << setprecision(5) << compute_area(RECTANGLE, 30, 6) << endl;
cout << "Perimeter: " << setprecision(5) << compute_perimeter(RECTANGLE, 30, 6) << endl;
cout << endl;

}
