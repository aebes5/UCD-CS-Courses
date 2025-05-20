#include "customer.hpp"
#include <iostream>
#include <iomanip>

Customer::Customer(NameType the_name, Cart& the_cart) : cart(the_cart)
{
  name = the_name;
  cart.set_customer(this);
  //add set customer part
}

NameType Customer::get_name() //getters
{
  return name;
}
string Customer::get_email()
{
  return email;
}
double Customer::get_balance()
{
  return balance;
}
Cart Customer::get_cart()
{
  return cart;
}

void Customer::set_cart(Cart a_cart)
{
  cart = a_cart;
}
void Customer::set_email(string an_email)
{
  email = an_email;
}

void Customer::display_customer_report()
{
  cout << "Customer: " << name.first_name << " " << name.last_name << endl;
  cout << "Email: " << email << endl;
  cout << "Balance: $" << fixed << setprecision(2) << balance << endl << endl;
  cout << cart;
}

void Customer::update_balance(double delta)
{
  balance += delta;
}