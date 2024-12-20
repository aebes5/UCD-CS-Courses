#ifndef PRODUCT_VIDEO_HPP
#define PRODUCT_VIDEO_HPP
#include "product.hpp"
#include <string>

enum FilmRating
{
NotRated, G, PG, PG_13, R, NC_17
};

class VideoProduct : public Product
{
public:
  VideoProduct(string a_product_name, double a_price, NameType a_director_name, int a_release_year, int a_run_time); //constructor

  NameType get_director(); //getters
  FilmRating get_rating();
  int get_release_year();
  int get_run_time();
  FilmRating get_enum(string str_rating);

  void set_director(NameType a_director); //setters
  void set_rating(FilmRating a_rating);
  void set_release_year(int a_release_year);
  void set_run_time(int a_run_time);

  bool is_new_release(int the_year); //returns if movie is older than year in argument(bool)

  string get_prod_type(); //virtual functions
  void display_prod_info();
  void display_contents_info();

private:
  NameType director; //private member variables
  FilmRating rating;
  int release_year;
  int run_time;
};

#endif