#include <iostream>
#include <cstdlib> //libraries for generating random number and string type
#include <ctime>
#include <string>

using namespace std;

int main()
{
   int initial_balance; //user asked for initial balance which is stored in variable
   cout << "Please enter the initial balance: ";
   cin >> initial_balance;

   double interest_rate; //user asked for interest rate(%), converted into monthly interest rate
   cout << "Please enter the interest rate(%): ";
   cin >> interest_rate;
   interest_rate = (1 + (interest_rate/12/100));

   int times = 1; //times variable which keeps track of the month

   string month[] = 
   {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
   "November", "December"}; //array with month of each transaction

    int year = 2021; //starting year that will increase by 1, making starting year 2022

    int count = 0; //variable set to 0 to index the month array 

   cout << "#\tMonth/Year\t\tInitial Balance\tWithdrawal\tInterest\tNew Balance" << endl;
   cout << "=\t==========\t\t===============\t=========\t========\t===========" << endl;

    while (initial_balance != 0) //while statement repeated until balance = 0
    {  if (count % 12 == 0) //if statement that sets count back to 0 if count == 12
        {
          year ++; //year increases by 1
          count = 0; //count set back to 0(to index array of months)
        }

      if (initial_balance > 620) //if statement that stops generating random #s if balance < 620
      {
         srand(times); //generates random number between 480 and 620 stored in variable
         int random_withdrawal = rand() % 140 + 480;
         
         //declaration of variables that will be outputted
         int balance_before_interest = initial_balance - random_withdrawal; 
      
         int balance_after_interest = balance_before_interest * interest_rate;

         int interest_amount = balance_after_interest - balance_before_interest;



         //statement printed including values stored in variables, month_year is indexed depending
         //on value of int times
         cout << times << "\t" << month[count] << ", "<< year << "\t\t" << initial_balance << "\t\t" << 
         random_withdrawal << "\t\t" << interest_amount << "\t\t" << balance_after_interest << endl;
   
         //change value of initial balance to updated initial balance, increment times by 1 so
         //the same index of the array isn't called
         initial_balance = (initial_balance + interest_amount) - random_withdrawal ;
         times++;
         count++;
      }
      else //else statement that takes the initial balance which is < 620, and generates a 
           //final withdrawal that takes the balance down to 0(while loop stops)
      {
         int final_withdrawal = initial_balance;
      
         cout << times << "\t" << month[count] << ", " << year << "\t\t" << initial_balance << "\t\t" << 
         final_withdrawal << "\t\t" << "0" << "\t\t" << "0" << endl;

         initial_balance = 0; 
      }
   }
}


