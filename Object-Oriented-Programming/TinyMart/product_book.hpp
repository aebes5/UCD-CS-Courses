#ifndef PRODUCT_BOOK_HPP
#define PRODUCT_BOOK_HPP
#include "product.hpp"

class Book : public Product
{
public:
Book(string a_prod_name, double a_price, NameType an_author, int a_num_pages); //constructor

NameType get_author(); //getters
int get_pages();

void set_author(NameType an_author); //setters
void set_pages(int a_num_pages);

string get_prod_type() = 0; //virtual functions
void display_prod_info(); 
void display_contents_info(); 

private:
NameType author; //private member variables
int pages;

};


#endif