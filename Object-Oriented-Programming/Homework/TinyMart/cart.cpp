#include "cart.hpp"
#include <array>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "product_video.hpp"
#include "product_audio.hpp"
#include "product_book_paper.hpp"
#include "product_book.hpp"
#include "product_book_ebook.hpp"
#include "customer.hpp"



Cart::Cart() : full_cart(true), num_of_purchases(0), running_total(0) //constructor
{
 //sets private member variable
}

void Cart::set_owner(NameType the_owner) //setter
{
  owner = the_owner;
}
void Cart::set_customer(Customer* a_customer)
{
  customer = a_customer;
}

NameType Cart::get_owner() //getter
{
  return owner;
}

Customer* Cart::get_customer()
{
  return customer;
}

bool Cart::add_item(Product *the_product) //adds product to shooping cart
{  
    int i = 0; //variables to traverse array
    bool added = false;
  
    while (!added && i < MAX_ITEMS) //until all indexes have been searched or an item has been added
    {
      if(vect.size() <= MAX_ITEMS-1) //
      {
        vect.push_back(the_product); //index = product
        added = true; //stops while loop
      }
      i++; 
    }
  try //exception handling(cart overflow)
  {
    if(!added)
      {
        throw exception(); //throw
        return false;
      }
      else
      {
      customer->update_balance(the_product->get_price()); //update balance
        return true;
      }
  }
  catch(exception& n) //catch
    {
      cout << "Cart overflow." << endl;
      exit(1);
    }
  

}

void Cart::display_cart()
{
  for(int i = 0; i < vect.size(); i++) //for each element in array
    {
      {
      vect[i]->display_contents_info(); //displays product specific information for each product
      num_of_purchases++; //tracks number of items
      running_total += vect[i]->get_price(); //tracks total among all products
      }
    }
  cout << "===== Summary of Purchase ======" << endl; //print out information
  cout << "Total number of purchases: " << num_of_purchases << endl;
  cout << fixed << setprecision(2) << "Total purchasing amount: $" << running_total << endl;
  cout << fixed << setprecision(2) << "Average cost: $" << (running_total/num_of_purchases) << endl; //sets precision to 2 decimals
}

bool Cart::remove_item(prod_id_t the_product_id)
{
  try 
  {
    if (vect.size() <= 0) //exception handling(cart empty)
    {
      throw exception(); //throw
    }
  }
  catch(exception& n) //catch
  {
    cout << "Cart underflow." << endl;
    exit(1);
  }
  
    for(int i = 0; i < MAX_ITEMS; i++) //for each index
    {
      item_number = vect[i]->get_prod_id(); //item number at index
      
      if(item_number == the_product_id) //if item number at index is the same passed as argument
      {
        customer->update_balance(-(vect[i]->get_price()));
        vect.erase(vect.begin() + i); //data is set to 0
        cout << "Item removed." << endl << endl;

        
        return true; //item is removed
      }
    }
  cout << "Couldn't find item number." << endl << endl;
  return false; //otherwise item wasn't removed
}

bool Cart::is_cart_full()
{
  if(vect.size() >= MAX_ITEMS) //if vect size is greater than max items per cart
  {
    return false; //cart isn't full
  }
    
      return true; //otherwise cart is full
}

Product* Cart::search_product(string product_name)
{
  for(int i = 0; i < MAX_ITEMS; i++) //for each index
    {
      if(vect[i]->get_prod_name() == product_name) //checks each product name
      {
        return vect[i]; 
      }
    }
  cout << "Item not found." << endl;
  exit(1);
}

bool Cart::read_from_file(string file_name, Cart *the_cart)
{
  
  ifstream file; //open file
  file.open(file_name);

  if (!file.is_open()) //checks if file failed to open
  {
    cout << "File failed to open." << endl;
    exit(1);
  }

  string line; //variables for searching through file
  string product_type;

  while(getline(file, line)) //for each line
    {
      string product_information[MAX_INFORMATION]; //creates array
      
      stringstream ss(line);

      int i = 0; //indexes array
      
      while(getline(ss, line, ',')) //for each string separated by ','
        {
        product_information[i] = line; //add substring to according index in array
        i++;
        }

      product_type = product_information[0]; //product type is first element in array

      switch(get_enum(product_type)) //switch(Type)
        {
          case 0: //Video
            {
              VideoProduct* ptr = new VideoProduct(product_information[1], stod(product_information[2]), split_names(product_information[3]), stoi(product_information[4]), stoi(product_information[5])); //dynamic initialization based on where in the array information is stored
//VideoProduct(string a_product_name, double a_price, NameType a_director_name, int a_release_year, int a_run_time);
              
              ptr->set_rating(ptr->get_enum(product_information[6])); //get enum from string, set rating of enum
              
              ptr->set_review_rate(stod(product_information[7])); //set review rate of double
              
              the_cart->add_item(ptr); //add product to cart
              
              break;
            }
          case 1: //Audio
            {
              AudioProduct* ptr = new AudioProduct(product_information[1], stod(product_information[2]), split_names(product_information[3])); //dynamic initialization based on where in the array information is stored
//AudioProduct(string a_prod_name, double a_price, NameType a_singer);
              
              ptr->set_genre(ptr->get_enum(product_information[4])); //get enum from string, set genre of enum
              
              ptr->set_review_rate(stod(product_information[5])); //set review rate of double
              
              the_cart->add_item(ptr); //add product to cart
              
              break;
            }
          case 2: //Paper
            {
              PaperProduct* ptr = new PaperProduct(product_information[1], stod(product_information[2]), split_names(product_information[3]), stoi(product_information[4])); //dynamic initialization based on where in the array information is stored
//PaperProduct(string a_prod_name, double a_price, NameType an_author, int num_pages);
              
              ptr->set_review_rate(stod(product_information[5])); //set review rate of double
              
              the_cart->add_item(ptr); //add product to cart
              
              break;
            }
          case 3: //Ebook
            {
              EbookProduct* ptr = new EbookProduct(product_information[1], stod(product_information[2]), split_names(product_information[3]), stoi(product_information[4])); //dynamic initialization based on where in the array information is stored
//EbookProduct(string a_prod_name, double a_price, NameType an_author, int num_pages);
              
              ptr->set_review_rate(stod(product_information[5])); //set review rate of double
              
              the_cart->add_item(ptr); //add product to cart
              
              break;
            }
          case 4: //Game
            {
              GameProduct* ptr = new GameProduct(product_information[1], stod(product_information[2]), get_console_enum(product_information[3]));

              ptr->set_review_rate(stod(product_information[4]));

              the_cart->add_item(ptr);

              break;
            }
          case 5: //Other
            {
              cout << "Invalid product type." << endl << endl; //stops function, returns false
              return false;
            }
        }
    }
  return true;
}

Type Cart::get_enum(string product_type)
{
  if(product_type == "Video") //returns enum Type
  {
    return Type::Video;
  }
  else if(product_type == "Audio")
  {
    return Type::Audio;
  }
  else if(product_type == "Paper")
  {
    return Type::Paper;
  }
  else if(product_type == "Ebook")
  {
    return Type::Ebook;
  }
  else if(product_type == "Game")
  {
    return Type::Game;
  }
  else
  {
    return Type::Other;
  }
}

NameType Cart::split_names(string a_name)
{
  string first_name; //unique to function
  string last_name;

  int space = a_name.find(" "); //location of space
  
  first_name = a_name.substr(0, space); //substring first name
  
  last_name = a_name.substr(space+1, sizeof(a_name)); //substring last name

  return {first_name, last_name}; //return NameType {string first, string last}
}

ConsoleType Cart::get_console_enum(string a_console) //returns enum game type
{
  if(a_console == "XBOX")
  {
    return ConsoleType::XBOX;
  }
  else if(a_console == "PLAYSTATION")
  {
    return ConsoleType::PLAYSTATION;
  }
  else if(a_console == "NINTENDO")
  {
    return ConsoleType::NINTENDO;
  }
  else
  {
    exit(1);
  }
}

Cart& Cart::operator +(Product& the_product) //operator overloading +
{
  add_item(&the_product);
  return *this;
}

ostream& operator<< (ostream& os, Cart& a_cart) //operator overloading <<
{
  a_cart.display_cart();
  return os;
}