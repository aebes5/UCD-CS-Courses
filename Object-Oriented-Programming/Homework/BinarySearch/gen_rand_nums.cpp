#include "binary_search.hpp"

void gen_rand_nums(const string file_name, const int number_size)
{
    ofstream text_file; //output text

    text_file.open(file_name); //clears contents in file
    text_file.close();

    text_file.open(file_name, std::ios_base::app); //append file

    for (int i = 0; i < number_size; i++) 
    {
        random_device random;

        default_random_engine engine{random()};

        uniform_int_distribution<> range(0, 1000000); //random number between 0-100000

        int random_number = range(engine);

        if (i % 5 == 4) //if 4 elements in line, print number and endl
        {
            text_file << random_number << endl;
        }
        else //add number to line separated by space
        {
            text_file << random_number << " ";
        }
    }
}