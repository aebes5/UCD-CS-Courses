#include "product_video.hpp"
#include <iostream>


string array[] = {"NotRated", "G", "PG", "PG_13", "R", "NC_17"}; //used to convert enum back to string

VideoProduct::VideoProduct(string a_product_name, double a_price, NameType a_director_name, int a_release_year, int a_run_time) : Product(a_product_name, a_price) //constructor, instantiates generic product class
{
  set_director(a_director_name); //set member variables
  set_release_year(a_release_year);
  set_run_time(a_run_time);
}

NameType VideoProduct::get_director() //getters
{
  return director;
}
FilmRating VideoProduct::get_rating()
{
  return rating;
}
int VideoProduct::get_release_year()
{
  return release_year;
}
int VideoProduct::get_run_time()
{
  return run_time;
}
string VideoProduct::get_prod_type()
{
  return "Movie";
}
FilmRating VideoProduct::get_enum(string str_rating)
{
  if(str_rating == "G")
  {
    return FilmRating::G;
  }
  else if(str_rating == "PG")
  {
    return FilmRating::PG;
  }
  else if(str_rating == "PG_13")
  {
    return FilmRating::PG_13;
  }
  else if(str_rating == "R")
  {
    return FilmRating::R;
  }
  else if(str_rating == "NC_17")
  {
    return FilmRating::NC_17;
  }
  else
  {
    return FilmRating::NotRated;
  }
}



void VideoProduct::set_director(NameType a_director) //setters
{
  director = a_director;
}
void VideoProduct::set_rating(FilmRating a_rating)
{
  rating = a_rating;
}
void VideoProduct::set_release_year(int a_release_year)
{
  release_year = a_release_year;
}
void VideoProduct::set_run_time(int a_run_time)
{
  run_time = a_run_time;
}


bool VideoProduct::is_new_release(int the_year) //returns true if product release year is >= current year 
{
  if(the_year > release_year)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void VideoProduct::display_contents_info() //display generic product info as well as product type specific info
{
  Product::display_product_info();
  cout << "Rating: " << array[rating] << endl;
  cout << "Director: " << director.first_name << " " << director.last_name << endl;
  cout << "Release year: " << release_year << endl;
  cout << "Run time: " << run_time << endl;
  cout << "Rating: " << rating << endl << endl;
}

