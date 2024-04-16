/********************************************
* This hpp file contains the Comparator_ID class which contains the function
* is_less_than which given two Student objects will return a bool.
* Author: Andrew Ebert
* Version: 6/16/2023
**********************************************/


#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP
#include "Student.h"

class Comparator_ID
{
public:
    Comparator_ID(){};

    bool is_less_than(Student a_student, Student another_student)
    {
        if (a_student.get_ID() < another_student.get_ID())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif