#include <iostream>
#include "drawing_shapes.hpp"

using namespace std;


void move_right(int num_horiz_spaces)
{
  for (int i = 0; i < num_horiz_spaces; i++) //sets position
    {
      cout << " ";
    }
  
  extern int global_horiz_spaces; 
  
  global_horiz_spaces = num_horiz_spaces; //sets global variable accessible by other files
}