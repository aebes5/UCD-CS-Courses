#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <sstream>

using namespace std;

void gen_rand_nums(const string file_name, const int number_size);
//precondition: takes in file_name and # of nums generated
//postcondition: generates random #s from 0-100000 and stores nums in file_name, no return type

void read_file(const string file_name, int array[], const int number_size);
//precondition: takes in file_name, int array, and # of nums generated
//postcondtion: reads all the nums in file_name and puts them into the array with size number_size, no return type

void bubble_sort(int array[], const int number_size);
//precondition: takes int array with rand nums and the # of nums generated
//postcondition: sorts the values stored in the array from smallest to largest, no return type

void binary_search(int target, int array[], int left, int right);
//precondtion: takes in the target number, array, left bound of array, and right bound of array
//postcondition: binary searches through the array and tells the user if the target they guessed exists in the array; 
//if so, how many guesses it takes and how many times the target exists in the array, no return type

#endif