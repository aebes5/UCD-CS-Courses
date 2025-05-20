#include "product_game.hpp"
#include <iostream>

GameProduct::GameProduct(string a_product_name, double a_price, ConsoleType a_console) : Product(a_product_name, a_price) //constructor
{
  set_console(a_console);
}

ConsoleType GameProduct::get_console() //getters
{
  return console;
}
string GameProduct::get_version()
{
  return version;
}

string game_array[] = {"Xbox", "Playstation", "Nintendo"};

void GameProduct::set_console(ConsoleType a_console) //setters
{
  console = a_console;
}

void GameProduct::set_version(string a_version)
{
  version = a_version;
}

string GameProduct::get_prod_type()
{
  return "Game";
}

void GameProduct::display_contents_info()
{
  display_product_info();
  cout << "Console type/Version: " << game_array[console] << " " << version << endl << endl;
}

void GameProduct::display_prod_info()
{
  Product::display_product_info();
}