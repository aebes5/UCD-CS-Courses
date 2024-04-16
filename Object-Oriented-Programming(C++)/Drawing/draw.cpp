#include <iostream>
#include "drawing_shapes.hpp"

using namespace std;

void draw_rectangle(double base, double height, char line_type);
//Precondition: takes in a base, height, and line_type; draws a rectangle based on arguments given
//Postconditin: none, void type

void draw_square(double base, char line_type);
//Precondition: takes in a base(no height since base and height are same) and line_type; draws a square based on arguments given
//Postconditin: none, void type

void draw_triangle(double base, char line_type);
//Precondition: takes in a base(no height since isosceles triangle only) and line_type; draws a triangle based on arguments given
//Postconditin: none, void type

void draw_circle(double base, char line_type);
//Precondition: takes in a base(radius) and line_type; draws a circle based on arguments given
//Postconditin: none, void type

extern int global_horiz_spaces; //get the value of global_horiz_spaces from move_right.cpp



void draw(ShapeType shape, double base, double height, char line_type)
{
  switch(shape) //switch statement calling proper draw function based on ShapeType shape passed
    {
      case RECTANGLE:
        draw_rectangle(base, height, line_type);
        break;

      case SQUARE:
        draw_square(base, line_type);
        break;

      case TRIANGLE:
        draw_triangle(base, line_type);
        break;

      case CIRCLE:
        draw_circle(base, line_type);
        break;
    }
}

void draw_rectangle(double base, double height, char line_type)
{
  for (int i = 0; i < base; i++) //draws top line
    {
      cout << line_type;
    }
  
  cout << endl; //end line
  
  for (int j = 0; j < (height - 2); j++) //for each row(excluding top and bottom)
    {
      for (int k = 0; k < global_horiz_spaces; k++) //sets position
        {
          cout << " ";
        }
      
      cout << line_type; //prints left char
      
      for (int l = 0; l < (base - 2); l++) //sets position
        {
          cout << " ";
        }
      
      cout << line_type << endl; //prints right char, end line
    }
  for (int m = 0; m < global_horiz_spaces; m++) //set position
    {
      cout << " ";
    }
  for (int n = 0; n < base; n++) //draws bottom line
    {
      cout << line_type;
    }

    cout << endl; //end line
}

void draw_square(double base, char line_type)
{
  
    for (int i = 0; i < base; i++) //draws top line
    {
      cout << line_type;
    }
  
  cout << endl; //end line
  
  for (int j = 0; j < (base - 2) / 2; j++) //for each row(creates 2:1 for base to row)
    {
      for (int k = 0; k < global_horiz_spaces; k++) //set position
        {
          cout << " ";
        }
      
      cout << line_type; //prints left char
      
      for (int l = 0; l < (base - 2); l++) //sets position
        {
          cout << " ";
        }
      
      cout << line_type << endl; //prints right char
    }
  for (int m = 0; m < global_horiz_spaces; m++) //sets position
    {
      cout << " ";
    }
  for (int n = 0; n < base; n++) //draws bottom line
    {
      cout << line_type;
    }

    cout << endl; //end line
}

void draw_triangle(double base, char line_type)
{
  base = base / 2; //sets base to half original value, 2:1 ratio for base to height
  
  int row = 1; //tracks which row is being printed

  int right_tracker = global_horiz_spaces + base - 1; //right tracker tracks where char starts to print for line

  for (int i = 0; i < base - 1; i++) //sets position of first line
    {
      cout << " ";
    }
  
  cout << line_type << endl; //prints char
  
  for (int j = 0; j < (base - 2); j++) //for each row(excluding first and last)
    {
      for (int k = 0; k < (right_tracker - row); k++) //set position
        {
          cout << " ";
        }
      
      cout << line_type; //print left char
      
      for (int l = 0; l < (row * 2); l++) //set position
        {
          cout << " ";
        }
      
      cout << line_type << endl; //prints right char, end line
      
      row++; //row incremented
    }
  for (int m = 0; m < global_horiz_spaces; m++) //set position
    {
      cout << " ";
    } 
  for (int n = 0; n < (base * 2); n++) //prints final row
    {
      cout << line_type;
    }
  
  cout << endl; //end line
}

void draw_circle(double base, char line_type)
{
  if (base <= 2) //if radius is <= 2
  {
    cout << "O" << endl; //draw char 'O'
  }
  else
  {
    cout << "("; //left edge
    for (int i = 0; i < (base - 2); i++) //inside chars
      {
        cout << line_type;
      }
    cout << ")" << endl; //right edge
  }
}