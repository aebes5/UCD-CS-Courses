/********************************************
* This hpp file contains the Comparator_Name class which contains the function
* is_less_than which given two Student objects will return a bool.
* Author: Andrew Ebert
* Version: 6/16/2023
**********************************************/

#ifndef COMPARATOR_NAME_HPP
#define COMPARATOR_NAME_HPP
#include "Student.h"

class Comparator_Name
{
public:
    Comparator_Name(){};

    bool is_less_than(Student a_student, Student another_student)
    {
        if (a_student.get_first_name() < another_student.get_first_name())
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