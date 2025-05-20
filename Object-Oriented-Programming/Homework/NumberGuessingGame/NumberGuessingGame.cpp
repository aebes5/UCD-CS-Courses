#include <iostream>
#include <cstdlib> //libraries used for generating random number
#include <ctime>

using namespace std;

int main() 
{
   srand(time(NULL)); //generates random number between 0 and 999
   int randomNumber = 0 + rand() % 999;

   bool correctGuess = false; //sets correctGuess boolean variable to false

   int UserGuess; //int variable that stores the value the user guessed

   int tries = 0; //tries variable set to 0, increases as user guesses

   while (correctGuess != true) //while statement that continues until correct # is guessed
   {                            //continues until correctGuess is true
      cout << "Please enter a guess: ";
      cin >> UserGuess; //user guesses number which is stored in variable

      if (UserGuess < randomNumber) //if statement that is performed if guess is less than rand #
      {
         cout << "Your guess is too low." << endl;
         tries += 1; //tries increases by 1
      }
      else if (UserGuess > randomNumber) //else if performed if guess is greater than rand #
      {
         cout << "Your guess is too high." << endl;
         tries += 1; //tries increases by 1
      }
      else if (UserGuess == randomNumber) //else if performed is guess = rand #
      {
         tries += 1; //tries increases by 1
         correctGuess = true; //boolean set to true to break the while statement
         cout << "You guessed it! It took you " << tries << " tries." << endl;
      }
   }
}
