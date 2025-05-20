#ifndef CART_HPP
#define CART_HPP
#include "product_game.hpp"
#include <stdexcept>
#include <vector>

const int MAX_ITEMS = 7; //const shopping cart max size

const int MAX_INFORMATION = 8; //max number of product information in each line of text file

enum Type
{
Video, Audio, Paper, Ebook, Game, Other
};

class Customer;

class Cart
{
public:
  Cart(); //constructor


  bool add_item(Product* the_product); //public functions
  bool remove_item(prod_id_t the_product_id);
  void display_cart();
  void set_owner(NameType the_owner);
  NameType get_owner();
  Product* search_product(string product_name);
  bool read_from_file(string file_name, Cart *the_cart);
  NameType split_names(string a_name);
  ConsoleType get_console_enum(string a_console);
  Customer* get_customer();
  void set_customer(Customer *a_customer);
  Cart& operator+(Product& the_product);

  Type get_enum(string product_type); //getter

private:
  prod_id_t item_number; //private member variables
  NameType owner;
  vector<Product*> vect;
  bool full_cart;
  int num_of_purchases;
  float running_total;
  Customer *customer;

  bool is_cart_full(); //private member function
  friend ostream& operator<<(ostream& os, Cart& a_cart);

};

#endif

