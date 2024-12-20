#include <string>
#ifndef PRODUCT_HPP
#define PRODUCT_HPP

using namespace std;

typedef int prod_id_t; //defines new type

struct NameType //struct includes first and last name
{
  string first_name;
  string last_name;  
};

class Product //parent class of other classes
{
public:
  Product(string a_product_name, double a_price); //constructor

  prod_id_t get_prod_id(); //getters
  string get_prod_name();
  double get_price();
  float get_review_rate();

  void set_prod_id(prod_id_t product_id); //setters
  void set_prod_name(string the_name);
  void set_price(double the_price);
  void set_review_rate(float the_rate);

  virtual string get_prod_type() = 0;  //virtual functinos
  virtual void display_contents_info() = 0; 
  virtual void display_product_info(); 
  


private:
  prod_id_t product_id; //private member variables
  string product_name;
  double price;
  float review_rate;
  static prod_id_t next_id;

  static prod_id_t create_new_id(); //private static member function
  friend ostream& operator<<(ostream& os, Product& a_product);

};

#endif