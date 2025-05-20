#include "binary_search.hpp"

void bubble_sort(int array[], const int number_size)
{
     for (int i = 0; i < number_size - 1; i++) //for each row
    {
        for (int j = 0; j < number_size - i - 1; j++) //for each column
        {
            if (array[j] > array[j + 1]) //if left index is > right index, swap indexes
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}