#ifndef DRAWING_SHAPES_HPP
#define DRAWING_SHAPES_HPP

enum ShapeType //enum ShapeType defined
{
    RECTANGLE,
    SQUARE, 
    TRIANGLE,
    CIRCLE
};

void draw(ShapeType shape, double base, double height = 0, char line_type = '*');
//Precondition: takes in ShapeType shape, base, height(default = 0), and line_type(default = '*') which prints the shape
//Postcondition: none, void type

double compute_area(ShapeType shape, double base, double height = 0); 
//Precondition: takes in ShapeType shape, base, and height(default = 0) and calculates the area of the shape
//Postcondition: returns area as double

double compute_perimeter(ShapeType shape, double base, double height = 0);
//Precondition: takes in ShapeType shape, base, and height(default = 0) and calculates the perimeter of the shape
//Postcondition: returns perimeter as double

void move_right(int num_horiz_spaces);
//Precondition: takes in num_horiz_spaces and sets the x position using spaces, this function defines global var global_horiz_spaces
//Postcondition: none, void type

void move_up(int num_vertical_spaces);
//Precondition: takes in num_vertical_spaces and sets the y position by skipping lines
//Postcondition: none, void type

#endif