/********************************************

This header file defines the node struct and the double_linked
class.

Author: Andrew Ebert
Version: 7/3/2023
*********************************************/

#ifndef DOUBLE_LINKED_HPP
#define DOUBLE_LINKED_HPP
#include <iostream>

using namespace std;

struct node //holds pointers and data
{
  node *previous;
  node *next;
  int data;
};

class double_linked
{
public:

  double_linked(); //constructor

  int size_of_dll(); //methods
  bool is_empty();
  void clear_dll();
  int find(int a_number);
  void add(int a_number);
  void print();
  void remove(int a_number);

private:
  node* tail; //private member variables
  node* head;
  int size;
  
};

#endif