/********************************************
* Main driver program including the findMax template and the main function;
* main function creates a vector of Student objects and uses the Comparator
* classes to compare student information.
* Author: Andrew Ebert
* Version: 6/16/2023
**********************************************/


#include "Student.h"
#include "Comparator_ID.h"
#include "Comparator_name.h"
#include <iostream>
#include <vector>

template<typename Object, typename Comparator>
const Object & findMax(const vector<Object> & list, Comparator cmp)
{
    int MAX = 0;
    for(int i = 1; i < list.size(); i++)
    {
        if(cmp.is_less_than(list[MAX], list[i]))
        {
            MAX=i;
        }
    }
    return list[MAX];
}

int main()
{
    Student Student1("Vincent", "Perry", 1);
    Student Student2("Matt", "Smith", 2);
    Student Student3("Justin", "Chang", 3);

    vector<Student> vector_of_students;
    vector_of_students.push_back(Student1);
    vector_of_students.push_back(Student2);
    vector_of_students.push_back(Student3);

    int i = 0;
    while(i < vector_of_students.size())
    {
        vector_of_students[i].display_student_information();
        i++;
    }

    Comparator_ID compare_id;

    Student result_id = findMax(vector_of_students, compare_id);

    cout << "|Student with max ID|" << endl;
    result_id.display_student_information();

    Comparator_Name compare_name;

    Student result_name = findMax(vector_of_students, compare_name);

    cout << "|Student with max name|" << endl;
    result_name.display_student_information();

}

