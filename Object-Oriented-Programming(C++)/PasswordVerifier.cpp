#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int pswd_getch();
//this function takes in no arguments, but sets terminal into non-cononical mode, thus disaling line buffering, the function
//then returns the character that was hidden from user input

void adding_password_to_file(char *password);
//precondition: if all the conditions of a valid password are true, this function is called with the password as
//an argument
//postcondition: password is added to text file, no return type

bool password_checker(char *password);
//precondition: if the normal conditions of a valid password are true, this function is called to see if the 
//password has already been used
//postcondition: if the password has been used as one of the last 5 passwords, the function returns true

int main() {
    int count = 0;  //variable to track the number of password attempts the user has used
    bool invalid_attempt = true; //invalid attempt set to true

    while (count < 6 && invalid_attempt) //while loop repeats until attempts is < 6 or valid password is used
    {
        char password[20]; //cstring for entered password
        int i=0;         

        cout << "Enter a password: ";

        while((password[i] = pswd_getch())!='\n') //read in characters until you hit '\n'
        {
            i++;
        }

        password[i] = '\0'; //end of cstring

        count ++; //password attempts ++

        cout << endl;
        
        bool correct_size = false;  //bools for password requirements 
        bool unique = true;
        bool upper_case = false;
        bool lower_case = false;
        bool number = false; 
        bool special_character = false; 

        int length = strlen(password); //length of string

        if (length > 7 && length < 13) //if valid password length
        {
        correct_size = true;
        }
        
        for (int ch = 0; ch < length; ch++) //for each character in password
        {    
            if (isupper(password[ch])) //if char is upper
            {
                upper_case = true;
            }
            if (islower(password[ch])) //if char is lower
            {
                lower_case = true;
            }
            if (isdigit(password[ch]) && (password[ch] != 0 || password[ch] != 1 || password[ch] != 7)) //if digit and != 0, 1, 7
            {
                number = true;
            }
            if (ispunct(password[ch])) //if char is punctuation
            {                                 
                special_character = true;
            }
        }
        
        if (correct_size && upper_case && lower_case && number && special_character) //all types of characters exist and correct size of password
        {
            bool passwords_in_file = password_checker(password); //checks if password has been already used

            if (passwords_in_file == true) //if password is in text file, password isn't unique, else it is unique
            {
                unique = false;
            }
            else
            {
                unique = true;
            }
        }
        if (!correct_size) //wrong length
        {
            cout << "Make sure your password is between 8 and 12 characters." << endl;
        }
        if (!upper_case) //doesn't include upper case
        {
            cout << "Make sure to include an upper case letter." << endl;
        }
        if (!lower_case) //doesn't include lower case
        {
            cout << "Make sure to include a lower case letter" << endl;
        }
        if (!number) //doesn't include number
        {
            cout << "Make sure to include a number(not including 0, 1, 7)" << endl;
        }
        if (!special_character) //doesn't include special character
        {
            cout << "Make sure to include a special character" << endl;
        }
        if (!unique) //not unique
        {
            cout << "This password has been one of your last 5 passwords." << endl;
        }
        if (correct_size && upper_case && lower_case && number && special_character && unique) //if all requirements for valid password are true
        {                                 
            cout << "Valid password.";

            invalid_attempt = false; //valid attempt(exits while loop)

            adding_password_to_file(password); //adds password to text file
        }
        if (invalid_attempt && count != 6) //if last attempt was invalid and user hasn't used more than 5 attempts
        {
            cout << "Try again you have " << 6 - count << " attempt(s) remaining." << endl;
        }
    }
}

int pswd_getch() 
{

    struct termios savedTermIO, newTermIO;  //storing termio flags information
    int ch;

    //retrieving the current termio (terminal I/O) attributes of stdin (cin)
    tcgetattr(STDIN_FILENO, &savedTermIO );
    newTermIO = savedTermIO;

    // setting termio flags:
    // turn off input buffering (ICANON) and echoing to cout  (ECHO)
    newTermIO.c_lflag &= ~( ICANON | ECHO );  

    //settting the new termio (terminal I/O) attributes before reading a char
    tcsetattr( STDIN_FILENO, TCSANOW, &newTermIO );
    ch = getchar();

    // read in a char, now reverting to the previously saved termio
    tcsetattr( STDIN_FILENO, TCSANOW, &savedTermIO );
    return ch;
}

bool password_checker(char *password)
{
    ifstream myfile;
    myfile.open("PastPasswords.txt"); //read "PastPasswords.txt"

    string line; //string of line in file
    bool existing_password = false; //existing password in file(bool)

    while (std::getline(myfile, line)) //reads each line of file
    {
        if (line == password) //if (line == password) existing password exists
        {
            existing_password = true;
        }
    }
    myfile.close(); //close text file

    return existing_password; //return bool
}

void adding_password_to_file(char *password)
{
    ifstream myfile;
    myfile.open("PastPasswords.txt"); //read "PastPasswords.txt"

    string line; //line in file as string
    int count = 0; //tracks number of passwords in file

    string past_passwords[5]; //array to store past passwords

    int i = 0; //used to index array

     while (std::getline(myfile, line))
     {
        count++; 
        past_passwords[i] = line; //stores all passwords in file in array
        i++;
     }
     if(count < 5) //if number of attempts < 5, append password to file
     {
        ofstream textfile;
        textfile.open("PastPasswords.txt", std::ios_base::app);
        textfile << password << endl;
        textfile.close();
     }
     else
     {
        ofstream textfile;
        textfile.open("PastPasswords.txt"); //clears contents in file
        textfile.close(); //close text file

        textfile.open("PastPasswords.txt", std::ios_base::app);
        for (int i = 1; i < 5; i++) //appends 4 most recent password to file
        {
            textfile << past_passwords[i] << endl;
        }
        textfile << password << endl; //appends password input by user
        textfile.close(); //close text file
     }
}

/* Source: https://cboard.cprogramming.com/faq-board/27714-faq-there-getch-conio-equivalent-linux-unix.html
*/