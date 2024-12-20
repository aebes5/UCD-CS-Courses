#include "binary_search.hpp"

void read_file(const string file_name, int array[], const int number_size)
{
    ifstream text_file; //opens file in read
    text_file.open(file_name);

    string numbers;

    for (int i = 0; i < number_size; i++) //for all numbers in file
    {
            while(getline(text_file, numbers)) //separates each line by string nums
            {
                stringstream ss(numbers);
                
                while(getline(ss, numbers, ' ')) //separates substrings by ' '
                {
                    array[i] = stoi(numbers); //changes string back to int and stores value in array
                    i++;
                }
            }
    }
}