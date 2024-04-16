#include "drawing_shapes.hpp" 

double compute_area(ShapeType shape, double base, double height)
{
double area = 0; //declaring area variable
  
  switch(shape) //switch statement calculating area for ShapeType shape passed
    {
      case RECTANGLE:
        area = base * height;
        break;

      case SQUARE:
        area = base * base;
        break;

      case TRIANGLE:
        area = base * height / 2;
        break;

      case CIRCLE:
        area = 3.14 * base * base; //3.14 used for pi
        break;
    }
  return area; //returns area to function called from
}
