/********************************************

This file implements the double_linked class methods inclyding size, empty,
clear, find, add, remove, and delete

Author: Andrew Ebert
Version: 7/3/2023
*********************************************/
#include "double_linked.hpp"

double_linked::double_linked(): head(nullptr), tail(nullptr), size(0)
{
  //intentionally left empty
}

int double_linked::size_of_dll()
{
  cout << size << " elements in list" << endl;
  return size;
}

bool double_linked::is_empty()
{
  if(size == 0)
  {
    cout << "List is empty" << endl;
    return true;
  }
  cout << "List isn't empty" << endl;
  return false;
}

void double_linked::clear_dll()
{ 
  for(int i = 0; i < size; i++) //for each element
    {
      node* itr = head;
      head = head->next;
      delete itr; //delete node
    }
  size = 0; //set size to 0
}

int double_linked::find(int a_number)
{
  if(size == 0) //makes sure list isn't empty
  {
    cout << "List is empty, no numbers to be found" << endl;
    return -1;
  }
  node* itr = head; //beginning of list
  
  for(int i = 0; i < size; i++) //iterates through each node
    {
      if(itr->data == a_number)
      {
        cout << a_number << " is at index " << i << endl;;
        return i;
      }
      itr = itr->next;
    }
  cout << a_number << " is not in the list" << endl;
  return -1;
}

void double_linked::add(int a_number)
{
  if(size == 0) //adds first node
  {
    node *new_node = new node;

    new_node->previous = nullptr;
    new_node->next = nullptr;
    new_node->data = a_number;

    head = new_node;
    tail = new_node;

    size++;

  }
  else
  {
    if(a_number < head->data) //adds to beginning of list
    {
      node *new_node = new node;

      head->previous = new_node;
      new_node->next = head;
      new_node->previous = nullptr;
      head = new_node;
      new_node->data = a_number;

      size++;
    }
    else if(a_number > tail->data) //adds to end of list
    {
      node *new_node = new node;

      (tail)->next = new_node;
      new_node->previous = tail;
      tail = new_node;
      new_node->data = a_number;
      new_node->next = nullptr;

      size++;
      
    }
    else //adds between nodes
    {
      node* itr = head;
          
      while(itr->next != nullptr)
        {
          node* previous = itr;
          node* next = itr->next;

          if((previous->data < a_number) && (next->data >= a_number)) //number falls in between two nodes
          {
            node *new_node = new node;
            
            new_node->previous = previous;
            new_node->next = next;
            new_node->data = a_number;
            previous->next = new_node;
            next->previous = new_node;

            size++;
            return;
          }
          itr = itr->next;
        }
      cout << "Node couldn't be added" << endl; //else case
    }
  }
}

void double_linked::print()
{

  node* itr = head;
  
  for(int i = 0; i < size; i++) //for each element print data
    {
      cout << itr->data << " ";
      itr = itr->next;
    }
  cout << endl;
}

void double_linked::remove(int a_number)
{
    node* itr = head;
  
  for(int i = 0; i < size; i++) //for each element
    {
      if(itr->data == a_number)
      {
        node* previous = itr->previous; //store pointers
        node* next = itr->next;

        previous->next = itr->next; //switch pointers
        next->previous = itr->previous;

        delete itr;
        
        size--;
        
        return;
        
      }
      itr = itr->next;
    }
  cout << "Item couldn't be removed" << endl; //else case
}