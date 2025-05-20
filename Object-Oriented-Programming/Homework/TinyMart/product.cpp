#include "product.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

prod_id_t Product::next_id = 0;

Product::Product(string a_product_name, double a_price) : review_rate(0) //constructor
{
  set_prod_name(a_product_name); //set member variables, generate unique id
  set_price(a_price);
  product_id = create_new_id();
  set_prod_id(product_id);
}

prod_id_t Product::get_prod_id() //getter functions
{
  return product_id;
}
string Product::get_prod_name()
{
  return product_name;
}
double Product::get_price()
{
  return price;
}
float Product::get_review_rate()
{
  return review_rate;
}


void Product::set_prod_id(prod_id_t the_id) //setter functions
{
  product_id = the_id;
}
void Product::set_prod_name(string the_name)
{
  product_name = the_name;
}
void Product::set_price(double the_price)
{
  price = the_price;
}
void Product::set_review_rate(float the_rate)
{
  review_rate = the_rate;
}


prod_id_t Product::create_new_id() //creates new id, static function
{
  next_id++;
  return next_id;
}

void Product::display_product_info() //displays information contained in all product types
{
  cout << "[" << get_prod_type() << "]" << endl;
  cout << "Product ID: " << product_id << endl;
  cout << "Product name: " << product_name << endl;
  cout << "Price: $" << fixed << setprecision(2) << price << endl;
  cout << "Review rate: " << review_rate << endl;
}

ostream& operator<<(ostream& os, Product& a_product) //operator overloading <<
{
  a_product.display_product_info();
  return os;
}
