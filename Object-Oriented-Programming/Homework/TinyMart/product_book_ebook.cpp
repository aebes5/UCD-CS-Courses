#include "product_book_ebook.hpp"

EbookProduct::EbookProduct(string a_prod_name, double a_price, NameType an_author, int num_pages) : Book(a_prod_name, a_price, an_author, num_pages) //constructor, instantiates generic book class
{
  //intentionally left empty
}

string EbookProduct::get_prod_type() //getter
{
  return "E book";
}