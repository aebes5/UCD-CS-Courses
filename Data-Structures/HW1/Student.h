/********************************************
* This file contains the Student class with three getter functions and three
* member variables: first_name, last_name, and ID. The Student class also contains
* a function display_student_information which displays the student's name and ID.
* Author: Andrew Ebert
* Version: 6/16/2023
**********************************************/


#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <iostream>

using namespace std;

class Student
{
public:

    Student(string a_first_name, string a_last_name, int an_ID);

    string get_first_name()
    {
        return first_name;
    }


    string get_last_name()
    {
        return last_name;
    }

    int get_ID()
    {
        return ID;
    }

    void display_student_information()
    {
        cout << "Name: " << first_name << " " << last_name << endl;
        cout << "ID: " << ID << endl << endl;
    }

private:
    string first_name;
    string last_name;
    int ID;
};

#endif
