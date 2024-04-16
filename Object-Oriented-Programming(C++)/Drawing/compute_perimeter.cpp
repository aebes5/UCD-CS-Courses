#include "drawing_shapes.hpp"

double compute_perimeter(ShapeType shape, double base, double height)
{
  double perimeter = 0; //declaring perimeter variable
  
  switch(shape) //switch statement for ShapeType shape passed
    {
      case RECTANGLE:
        perimeter = base * 2 + height * 2;
        break;

      case SQUARE:
        perimeter = base * 4;
        break;

      case TRIANGLE:
        perimeter = base * 3;
        break;

      case CIRCLE:
        perimeter = 2 * 3.14 * base; //3.14 used for pi
        break;
    }
  return perimeter; //return perimeter to function called function was called from
}

