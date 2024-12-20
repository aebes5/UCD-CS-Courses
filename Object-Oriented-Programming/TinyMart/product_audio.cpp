#include "product_audio.hpp"
#include <iostream>


AudioProduct::AudioProduct(string a_prod_name, double a_price, NameType a_singer) :  Product(a_prod_name, a_price)
{ //constructor, instantiates generic product class
  set_singer(a_singer); //sets private member variables
}

string genre_array[] = {"Blues", "Country", "Classical", "Folk", "Jazz", "Metal", "Pop", "RnB", "Rock"}; //array to convert enum to string

NameType AudioProduct::get_singer() //getters
{
  return singer;
}
GenreType AudioProduct::get_genre()
{
  return genre;
}
string AudioProduct::get_prod_type()
{
  return "Music";
}
GenreType AudioProduct::get_enum(string str_genre)
{
  if(str_genre == "Blues")
  {
    return GenreType::Blues;
  }
  else if(str_genre == "Classical")
  {
    return GenreType::Classical;
  }
  else if(str_genre == "Country")
  {
    return GenreType::Country;
  }
  else if(str_genre == "Folk")
  {
    return GenreType::Folk;
  }
  else if(str_genre == "Jazz")
  {
    return GenreType::Jazz;
  }
  else if(str_genre == "Metal")
  {
    return GenreType::Metal;
  }
  else if(str_genre == "Pop")
  {
    return GenreType::Pop;
  }
  else if(str_genre == "RnB")
  {
    return GenreType::RnB;
  }
  else
  {
    return GenreType::Rock;
  }
}


void AudioProduct::set_singer(NameType a_singer) //setters
{
  singer = a_singer;
}
void AudioProduct::set_genre(GenreType a_genre)
{
  genre = a_genre;
}


void AudioProduct::display_contents_info() //display generic product info as well as product type specific info
{
  display_product_info();
  cout << "Singer: " << singer.first_name << " " << singer.last_name << endl;
  cout << "Genre: " << genre_array[genre] << endl << endl;
}

void AudioProduct::display_product_info() //calls function from parent class
{
  Product::display_product_info();
}

