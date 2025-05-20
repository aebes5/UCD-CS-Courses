#include "binary_search.hpp"

void binary_search(int target, int array[], int left, int right)
{
    bool array_searched = false; //breaks while loop when true
    int times = 0; //keeps track of times it takes to find num
    int index = -1;
    int temp = 0; //tracks if index has already been checked


    while(!array_searched)
    {
        int current_index = (right+left) /2; //stores the middle index for each iteration through loop


        if (temp == current_index) //if index was already checked(going back and forth)
        {
            cout << times << ".\t" << "Number is not in the array." << endl;

            array_searched = true;
        }

        else if (array[current_index] > target) //if indexed value is greater than guess
        {
            cout << times << ".\t" << target << " is less than " << array[current_index] << endl;

            right = current_index; //set the right bound to current index

            times++;

        }
        else if (array[current_index] == target) //if indexed value is same as guess
        {
            int target_times = 1;

            cout << times << ".\t" << "You guessed it!" << endl;
            cout << target << " is at index " << current_index << endl;

            index = current_index;
            array_searched = true;
            
            while (array[current_index + 1] == target) //checks if indexes to the right also have the same num
            {
                current_index++;

                cout << target << " is at index " << current_index << endl;

                target_times++;
            }
            while (array[index - 1] == target) //checks if indexes to the left also have the same num
            {
                index--;

                cout << target << " at index " << current_index << endl;

                target_times++;
            }
            cout << target << " exists in the array " << target_times << " time(s)" << endl;
        }
        else if (array[current_index] < target) //if indexed value is less than guess
        {
            cout << times << ".\t" << target << " is greater than " << array[current_index] << endl;

            left = current_index; //set left bound to current index

            times++;
        }

        temp = current_index; 
    }
}