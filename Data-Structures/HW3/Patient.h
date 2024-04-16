#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include <queue>

using namespace std;


//Class Patient with patient number,id, condition, priority
class Patient
{
public:
    //constructor
    Patient(string i = "", string cond = "", int pr = 0)
    {
        total++; //static variable to keep track of patients numbers as they come in.
        number = total;
        id = i;
        condition = cond;
        priority = pr;
    }

    //variables are made public for simplicity, but you can make them private.
    static int total; //static variable
    int number;
    string id;
    string condition;
    int priority;


};
int Patient::total = 0;


//Overload < operator for priority_queue to be able to compare patients objects based on priority
bool operator<(const Patient& p1, const Patient& p2)
{
    return (p1.priority < p2.priority);
}

//Overload > operator for priority_queue to be able to compare patients objects based on priority
bool operator>(const Patient& p1, const Patient& p2)
{
    return (p1.priority > p2.priority);
}

#endif
