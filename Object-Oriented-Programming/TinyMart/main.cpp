#include <iostream>
#include <string>
#include "product_video.hpp"
#include "product.hpp"
#include "product_book.hpp"
#include "product_book_ebook.hpp"
#include "product_audio.hpp"
#include "product_book_paper.hpp"
#include "cart.hpp"
#include "product_game.hpp"
#include "customer.hpp"

int main()
{
  NameType aName = {"User", "Name"}; //Instantiate Cart
  Cart myCart;
  
  Customer me(aName, myCart); //Instantiate customer
  me.set_email("me@gmail.com");
  
  AudioProduct*  an_audio= new AudioProduct("Yesterday", 16.5, aName); //Dynamically created objects
  an_audio->set_genre(GenreType::Pop);
  an_audio->set_review_rate(9.8);

  PaperProduct* a_paper = new PaperProduct("Lord of the Flies", 7.03,  {"William", "Golding"}, 100);
  a_paper->set_review_rate(8.1);



  VideoProduct a_video = VideoProduct("Jaws", 23.23, {"Not", "Sure"}, 1975, 120); //Create more objects
  a_video.set_review_rate(7.4);
  a_video.set_rating(FilmRating::PG_13);

  EbookProduct an_ebook = EbookProduct("Green Eggs and Ham", 6.07,  {"Dr", "Seuss"}, 300);
  an_ebook.set_review_rate(8.9);

  GameProduct a_game= GameProduct("Call of Duty", 59.99, ConsoleType::XBOX);
  a_game.set_review_rate(5.0);
  a_game.set_version("One");

  PaperProduct a_paper2 = PaperProduct("Percy Jackson", 20.75,  {"Rick", "Riordan"}, 400);
  a_paper2.set_review_rate(9.1);

  VideoProduct a_video2 = VideoProduct("Cars", 13.02, {"Disney", "Channel"}, 2008, 110);
  a_video2.set_review_rate(7.2);
  a_video2.set_rating(FilmRating::G);

  EbookProduct an_ebook2 = EbookProduct("Book Name", 0.01, {"Author", "Name"}, 1);
  an_ebook2.set_review_rate(0.1);

  //myCart.remove_item(1); //Exception handling test
  
  myCart = myCart + *an_audio + *a_paper + a_video + an_ebook + a_game + a_paper2 + a_video2; // + an_ebook2; //Exception handling test

  myCart.remove_item(4); //remove 2 items
  myCart.remove_item(2);


  
  me.display_customer_report();

  
}