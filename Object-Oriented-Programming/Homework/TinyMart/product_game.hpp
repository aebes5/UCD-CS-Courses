#ifndef PRODUCT_GAME_HPP
#define PRODUCT_GAME_HPP
#include "product.hpp"
#include <string>

enum ConsoleType
{
XBOX, PLAYSTATION, NINTENDO
};

class GameProduct : public Product
{
public:
  GameProduct(string a_product_name, double a_price, ConsoleType a_console); //constructor

  ConsoleType get_console(); //getters
  string get_version();

  void set_console(ConsoleType a_console); //setters
  void set_version(string a_version);

  string get_prod_type(); //virtual functions
  void display_prod_info();
  void display_contents_info();

private:
  ConsoleType console; //private member variables
  string version;
};

#endif