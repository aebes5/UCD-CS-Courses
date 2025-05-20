#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include "cart.hpp"

class Customer
{
public:
  Customer(NameType the_name, Cart& the_cart); //constructor

  NameType get_name(); //getters
  string get_email();
  double get_balance();
  Cart get_cart(); 

  void set_cart(Cart a_cart); //setters
  void set_email(string an_email);

  void display_customer_report();

  void update_balance(double delta);

private:
  NameType name;
  string email;
  double balance;
  Cart &cart;
  

};

#endif

