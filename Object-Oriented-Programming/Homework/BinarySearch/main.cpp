#include <iostream>
#include <string>
#include "binary_search.hpp" //header

using namespace std;

int main()
{
    string file_name;
    cout << "Enter a file name: "; //file for rand nums
    cin >> file_name;

    int number_size;
    cout << "Enter a size: "; //number of rand nums
    cin >> number_size;

    gen_rand_nums(file_name, number_size); //generate rand nums

    int array[number_size]; //array for rand nums
    read_file(file_name, array, number_size); //transfers nums from file to array

    bubble_sort(array, number_size); //sorts the nums in array from least to greatest

    bool continue_guessing = true;  //bool to let user continue/stop guessing

    while (continue_guessing)
    {
        int target;
        cout << "Please enter a number: "; //guess
        cin >> target;

        int left = 0; //left range of array

        binary_search(target, array, left, number_size); //binary searches array for num

        char YN;
        cout << "Would you like to guess another number? [Y/N]" << endl;
        cin >> YN;

        if (YN == 'N' || YN == 'n') //if statement to let user continue/stop guessing
        {
            continue_guessing = false;
        }
        else if(YN == 'Y' || YN == 'y')
        {
            continue_guessing = true;
        }
        else 
        {
            continue_guessing = false;
        }
    }
}