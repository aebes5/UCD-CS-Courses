#ifndef PRODUCT_BOOK_EBOOK_HPP
#define PRODUCT_BOOK_EBOOK_HPP
#include "product_book.hpp"

class EbookProduct : public Book
{
public:
  EbookProduct(string a_prod_name, double a_price, NameType an_author, int num_pages); //constructor

  string get_prod_type(); //returns product type

  void display_contents_info(){Book::display_contents_info();} //uses Book parent class which contains all specific information to book types
};

#endif