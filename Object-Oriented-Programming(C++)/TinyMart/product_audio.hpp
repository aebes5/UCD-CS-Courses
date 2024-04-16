#ifndef PRODUCT_AUDIO_HPP
#define PRODUCT_AUDIO_HPP
#include "product.hpp"

enum GenreType //enum for categories of genre
{
Blues, Country, Classical, Folk, Jazz, Metal, Pop, RnB, Rock
};

class AudioProduct : public Product
{
public:
  AudioProduct(string a_prod_name, double a_price, NameType a_singer); //constructor
  
  NameType get_singer(); //getters
  GenreType get_genre();
  GenreType get_enum(string str_genre);

  void set_singer(NameType a_singer); //setters
  void set_genre(GenreType a_genre);

  string get_prod_type(); //virtual functions
  void display_contents_info(); 
  void display_product_info();


private:
  NameType singer; //private member variables
  GenreType genre;
  string prod_name;
};
#endif

