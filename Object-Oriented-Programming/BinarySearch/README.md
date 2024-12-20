* Name : Andrew Ebert
* Student ID: 110048682
* Class : CSCI 2312 Section 02
* PA# : 4
* Due Date : March 31, 2023
# Read Me
## Description of the program

This program generates x number of random numbers, where x is given by the user; the program then asks the user for a text file name where the random numbers will be stored. The random numbers(between 0 and 100.000) are then transferred into an array. Once in the array, a bubble sorting algorithm then sorts all of the numbers in the array from smallest to greatest. The program then asks the user to guess if a number exists in the array and a binary search then checks to see if the number exists in the array. The program then outputs information regarding the search, and whether or not the number exists in the array. The user can keep guessing until they choose to stop.

## Source files

**main.cpp**

This is the main function that operates all of the other source files.

**binary_search.hpp**

This header file contains the functions for the following implementation files.

**binary_search.cpp**

This implementation file searches the array for the number the user guessed.

**bubble_sort.cpp**

This implementation file sorts the numbers in the array from smallest to greatest.

**gen_rand_nums.cpp**

This implementation file generates random numbers from 0 to 100,000.

**read_file.cpp**

This implementation file reads the numbers from the text file and stores them in an int array.
## Circumstances of programs
The program runs successfully. It was compiled, run, and tested on VSCode and REPLIT.

## How to build and run the program
Click the **green run** button.

