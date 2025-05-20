#include "product_book_paper.hpp"

PaperProduct::PaperProduct(string a_prod_name, double a_price, NameType an_author, int num_pages) : Book(a_prod_name, a_price, an_author, num_pages) //constructor, instantiates generic Book class
{
  //intentionally left empty
}


string PaperProduct::get_prod_type() //getter
{
  return "Paper book";
}