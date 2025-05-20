* Name : Andrew Ebert
* Student ID: 110048682
* Class : CSCI 2312 Section 02
* PA# : 7
* Due Date : May 7, 2023
# Read Me
## Description of the program

This program is an extension of the Programming Assignment 6: Tiny Mart. In this extended version, I have implemented a customer class where a customer has certain information stored, but the customer also has a cart(similar to a cart has a customer). There is another class called GameProduct, which functions similar to the rest of the product inherited classes. I have also done operator overloading where customers can used the + operator to add products to a cart(seen in the main function). There is also exception handling present in this version. I have also changed my static array to a vector because the way my static array was implemented was sloppy.

## Source files

**main.cpp**

The main file creates a cart object and then calls functions within the cart class.

**cart.hpp**

This header file contains the cart class.

**cart.cpp**

This implementation file contains functions that allows the user to add product objects, remove product objects, search product objects, and dynamically initialize objects from a file containing product information.

**product.hpp**

This header file contains the product class which is a base class for the product classes.

**product.cpp**

This implementation file contains functions and member variables that are common to each type of product, displays this information, and also creates a unique product ID each time the constructor is initialized.

**customer.hpp**

This header file contains the customer class which ***has a*** relationship with the cart class.

**customer.cpp**

This implementation file contains unique functions and member variables which can't be found in any of the product base or derived classes.

**product_video.hpp**

This header file contains the VideoProduct class which inherits from the Product class.

**product_video.cpp**

This implementation file contains functions and member variables unique to the information required for a video product, while still displaying the information common to all products through the Product class as a virtual function.

**product_audio.hpp**

This header file contains the AudioProduct class which inherits from the Product class.

**product_audio.cpp**

This implementation file contains functions and member variables unique to the information required for an audio product, while still displaying the information common to all products through the Product class as a virtual function.

**product_book.hpp**

This header file contains the class Book which inherits from the Product class, and is also a parent class to PaperProduct and EbookProduct.

**product_book.cpp**

This implementation file contains functions and member variables unique to the information required for both book products, while still displaying the information common to all products through the Product class as a virtual function.

**product_book_paper.hpp**

This header file contains the PaperProduct class which inherits from the Book class.

**product_book_paper.cpp**

This implementation file only contains one unique function from its inherited Book class which is the get_prod_type which returns "Paper".

**product_book_ebook.hpp**

This header file contains the EbookProduct class which inherits from the Book class.

**product_book_ebook.cpp**

This implementation file only contains one unique function from its inherited Book class which is the get_prod_type which returns "Ebook".

**product_game.hpp**

This header file contains the GameProduct class which inherits from the Product class.

**product_game.cpp**

This implementation file contains functions and member variables unique to the information required for a game product, while still displaying the information common to all products through the Product class as a virtual function.

## Circumstances of programs
The program runs successfully. It was compiled, run, and tested on REPLIT.

## How to build and run the program
Click the **green run** button. To change the product information, you can fork this replit and change the information inside of **test_file.txt**. To change the different functions being used, you can fork this replit and change the **main.cpp** file.

