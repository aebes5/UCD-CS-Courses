/********************************************

This driver file contains the main function which tests out 
all of the methods in the double_linked class.

Author: Andrew Ebert
Version: 7/3/2023
*********************************************/

#include <iostream>
#include "double_linked.hpp"

int main() 
{
  double_linked dll; //create object

  dll.add(1); //test class functions
  dll.add(5);
  dll.add(9);
  dll.add(16);
  dll.add(25);
  dll.add(2);
  dll.add(7);
  dll.add(19);
  dll.print();
  dll.add(10);
  dll.print();
  dll.size_of_dll();
  dll.is_empty();
  dll.remove(9);
  dll.print();
  dll.size_of_dll();
  dll.find(16);
  dll.find(9);
  dll.clear_dll();
  dll.is_empty();
}