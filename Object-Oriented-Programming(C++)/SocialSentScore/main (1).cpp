#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct sss //sss struct with variables word and score
{
  string word;

  double score;
};

sss table[6279]; //array of struct(max entries is 6279)

void build_social_sent_scores_table(string data_file);
//Precondition: takes in a data_file, and then uses the file to set a social sentiment score table using an array of struct type
//Postcondition: none, void type

double compute_ss(string review_file_name);
//Precondition: takes in review_file_name, and reads through the file, matching each word with the sss data table
//Postcondtion: returns a double which is the final score after reading through the file

double get_star_rank(double final_score);
//Precondtion: takes in a final_score and determines the correspondng star rank
//Postcondition: returns double star rank



int main(int argc, char *argv[]) //parameters for command line arguments
{
  cout << "[word, current_score, accumulated_score]" << endl; //formatting for what's being output
  cout << endl;
  
  double total_score = 0; //

  int star_rank = 0;

  string data_file = "socialsent.csv"; //default data_file

  
  build_social_sent_scores_table(data_file); //builds sss table

  char review_file [] = "review.txt"; //default review_file

	if (argc > 1) //if argument is given in command line 
  {
    strcpy(review_file, argv[1]); //copy argument to review_file
	}

  
  total_score = compute_ss(review_file);  //invokes function, total_score = double returned from function

  star_rank = get_star_rank(total_score); //invokes function, star_rank = double returned from function

  cout << endl; //format for output

  cout << review_file << " score: " << total_score << endl;

  cout << review_file << " stars: " << star_rank;  
}

void build_social_sent_scores_table(string data_file)
{

  ifstream my_file;
  my_file.open(data_file); //opens file

  if (!my_file.is_open()) //checks if file failed to open
  {
    cout << "File failed to open." << endl;
    exit(1);
  }
  
  string line; //string variable which holds everything in a line
  
  int i = 0; //used to store values at correct index in struct array
  
  while(getline(my_file, line)) //for each line
    {
      int space = line.find(" "); //index of " "
      
      string word; //word in line
      
      string score; //score in line
      
      int size = sizeof(line); //size of line
      
      word = line.substr(0, space);
      score = line.substr(space + 1, size);

      double updated_score  = stod(score); //converts string to double

      table[i].word = word; //adds struct variables to array at current index
      table[i].score = updated_score; 
     
      i++; //increments the index
    }
  
	my_file.close(); //closes file
}

double compute_ss(string review_file_name)
{
  ifstream my_file; //opens file
  my_file.open(review_file_name);

  if (!my_file.is_open()) //checks if file failed to open
  {
    cout << "File failed to open." << endl;
    exit(1);
  }
  double current_score = 0; //tracks score at current word

  string word; //holds current word

	while (my_file >> word) //separates each word, removing all characters except for alphanumerics from word
  {

		char nonAlphaNum[] = "{}[]()-.,!?\"\'"; //list of invalid char in word
    
		for (int i = 0; i < strlen(nonAlphaNum); i++) //for each char in string
    {
			word.erase(std::remove(word.begin(), word.end(), nonAlphaNum[i]), word.end()); //remove nonalphanumerics
    }
    

    for (int j  = 0; j < 6279; j++) //for each index of struct array
      {
        if (table[j].word == word) //if word at index == word
         {
          current_score += table[j].score; //current_score adds corresponding score to word
           
          cout << word << ": " << table[j].score << ", " << current_score << endl; //format for output
          }
      }
    
    } // end of while

  my_file.close(); //close file
  
	return current_score; //return double
}

double get_star_rank(double final_score) {
  int star;

  if(final_score < -5) //if statements to determine stars
  {
    star = 1;
  }
  else if(final_score >= -5 && final_score < -1)
  {
    star = 2;
  }
  else if(final_score >= -1 && final_score < 1)
  {
    star = 3;
  }
  else if(final_score >= 1 && final_score < 5)
  {
    star = 4;
  }
  else
  {
    star = 5;
  }
  return star; //return double
}
