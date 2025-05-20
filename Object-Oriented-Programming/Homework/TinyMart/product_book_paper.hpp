#ifndef PRODUCT_BOOK_PAPER_HPP
#define PRODUCT_BOOK_PAPER_HPP
#include "product_book.hpp"

class PaperProduct : public Book
{
public:
  PaperProduct(string a_prod_name, double a_price, NameType an_author, int num_pages); //constructor

  string get_prod_type();

  void display_contents_info(){Book::display_contents_info();}; //uses Book parent class which contains all specific information to book types
};

#endif