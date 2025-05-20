#include <iostream>
#include <string> //library for string type
#include <fstream> //library for file handling
#include <algorithm> //library with function to convert string to lower 
#include <cstdio> //library with function remove

using namespace std;

int remove_subwords_file = remove("subwords_list.txt"); //if "subwords_list.txt" exists from program execution, file is deleted so
                                                        //previous file isn't appended

const char array_alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
                                  //constant array of letters in the alphabet
int main()
{
    string word;
    cout << "Enter your word: ";
    cin >> word; //user asked for word, stored in string variable

    std::transform(word.begin(), word.end(), word.begin(), ::tolower); //word transformed to all lowercase for indexing of alphabet array
    
    int times_of_character_in_word[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //int array stores number of times a character is in word at index of                                                                                    //letter number(ex: if word was aa, index 0 would be 2 and remaining                                                                                     //indexes would be 0)
    
    for(int word_letter_indexed = 0; word_letter_indexed < word.size(); word_letter_indexed++) //for each letter in string, passes each letter in string
    {
        for(int alphabet_letters = 0; alphabet_letters < 26; alphabet_letters++) //checks to see if letter in current index of char array is equal to 
        {                                                                        //the letter in the string
            if (word[word_letter_indexed] == array_alphabet[alphabet_letters])
            {
                int updated_times = times_of_character_in_word[alphabet_letters] + 1; //if current index of char array is equal to the letter in the
                times_of_character_in_word[alphabet_letters] = updated_times;         //string, index in character of 1 is increased by 1 
            }
        }
    }


    ifstream myfile;
    myfile.open("words_CR_LF.txt"); //opens "words_CR_LF.txt" in read format
  
    string subword; //subword string assigned to each line of file
  
    int number_of_subwords = 0; //variable to keep track of subwords
  
    while (std::getline(myfile, subword)) //while the line contains a string
    {
        int number_of_times_in_subword[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  //array of times letters appear in subword, like                                                                                                         //times_of_character_in_word array
                                              
        bool valid_subword = true; //bool variable which stores whether a subword is valid
      
        for (int subword_letter_indexed = 0; subword_letter_indexed < subword.size(); subword_letter_indexed++)
        {                                                                              //nested for loops and if statements that change the int values
            for (int alphabet_letters = 0; alphabet_letters < 26; alphabet_letters++)  //in subword array to appropriate value depending on characters
            {                                                                          //in subword
                if (array_alphabet[alphabet_letters] == subword[subword_letter_indexed])
                {
                    int update = number_of_times_in_subword[alphabet_letters] + 1;
                    number_of_times_in_subword[alphabet_letters] = update;
                }
            } 
        }
        for (int i = 0; i < 26; i++) //for loop that goes through every index in word int array and subword int array
        { 
            if (times_of_character_in_word[i] < number_of_times_in_subword[i]) //if the times in word is < number of times in subword for any character
            {                                                                  //valid subword is false
                valid_subword = false;
            }

        }
        if(word == subword) //conditional if statement used so the number of subwords doesn't include the word entered by user
        {
        }

        else if(valid_subword) //if valid_subword is true
        {
          number_of_subwords++; //number of subwords increases by 1
          
          ofstream textfile;
          textfile.open("subwords_list.txt", std::ios_base::app); //opens new "subwords_list.txt" file and appends
          
          textfile << subword << endl; //appends subword to file
        }
    }//end of while loop
    cout << word << " has " << number_of_subwords << " subwords."<< endl;
}