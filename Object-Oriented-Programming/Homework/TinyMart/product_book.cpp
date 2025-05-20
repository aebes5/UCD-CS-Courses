#include "product_book.hpp"
#include <iostream>


Book::Book(string a_prod_name, double a_price, NameType an_author, int a_num_pages) : Product(a_prod_name, a_price)
{ //constructor, instantiates generic product class
  set_author(an_author); //sets private member variables
  set_pages(a_num_pages);
}

NameType Book::get_author() //getters
{
  return author;
}
int Book::get_pages()
{
  return pages;
}


void Book::set_author(NameType an_author) //setters
{
  author = an_author;
}
void Book::set_pages(int a_num_pages)
{
  pages = a_num_pages;
}

void Book::display_contents_info() //display generic product info as well as product type specific info
{
  Product::display_product_info();
  cout << "Author: " <<  author.first_name << " " << author.last_name << endl;
  cout << "Pages: " << pages << endl << endl;
  
}