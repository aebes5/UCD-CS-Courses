#include <iostream>
#include "Patient.h"

int main()
{
    int response = 0; //variables
    string id, condition;
    int priority;

    priority_queue<Patient, vector<Patient>, greater<Patient>> pq; //priority queue using overloading

    while(response != 4) //keeps programming running
    {
        cout << "Please select one of the following:\n" //option menu
                "1. Add a new patient to the priority queue.\n"
                "2. Dispatch a patient to be seen with the highest priority.\n"
                "3. Display the priority queue.\n"
                "4. Exit\n"
                "\n"
                "Choice: ";
        cin >> response;

        switch (response)
        {
            case 1:
            {
                cout << "|Please enter the patient’s information|\n";

                cout << "Enter patient id: ";
                cin >> id;

                cout << "Enter patient condition: ";
                cin >> condition;

                cout << "Enter patient priority: ";
                cin >> priority;
                cout << endl;


                pq.push(Patient(id, condition, priority)); //push patient
                break;
            }

            case 2:
            {
                if(pq.empty()) //else case
                {
                    cout << "Waitlist is empty." << endl << endl;
                }

                else
                {
                    cout << "Now serving patient # " << pq.top().id << ", with condition " <<
                    pq.top().condition << ", priority " << pq.top().priority << endl << endl;

                    pq.pop(); //pop patient

                }
                break;
            }

            case 3:
            {
                priority_queue<Patient, vector<Patient>, greater<Patient>> temp_pq = pq; //copy of priority queue

                if (temp_pq.empty()) //else case
                {
                    cout << "Waitlist is empty." << endl << endl;
                }
                else
                {
                    while (!temp_pq.empty()) //each patient
                    {
                        cout << "Patient # " << temp_pq.top().id << ", with condition " <<
                        temp_pq.top().condition << ", priority " << temp_pq.top().priority << endl;

                        temp_pq.pop(); //pop
                    }
                    cout << endl;
                }
                break;
            }
            
            case 4:
            {
                break;
            }
            default: //else case
            {
                cout << "Enter a valid option." << endl;
            }

        }
    }
}

