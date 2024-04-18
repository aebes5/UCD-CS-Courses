import re
import sys
from collections import Counter



def buildDictionary(filename):
  with open(filename, 'r') as file:
  # open and read
      text = file.read()
  # split with delimiters
      words = re.split(r'\W+|\B[^\w\s]+\B', text)
  # remove empty strings and single characters from the list of words
      words = [word.lower() for word in words if word and len(word) > 1]

  return Counter(words)



def ledAlg(s1, s2):
  m, n = len(s1), len(s2)

  # create a matrix to store the edit distances
  dp = [[0] * (n + 1) for _ in range(m + 1)]

  # initialize the first row and column
  for i in range(m + 1):
      dp[i][0] = i
  for j in range(n + 1):
      dp[0][j] = j

  # fill in the matrix using dynamic programming
  for i in range(1, m + 1):
      for j in range(1, n + 1):
          if s1[i - 1] == s2[j - 1]:
              dp[i][j] = dp[i - 1][j - 1]
          else:
              dp[i][j] = 1 + min(dp[i - 1][j],      # deletion
                                 dp[i][j - 1],      # insertion
                                 dp[i - 1][j - 1]) # substitution

  # bottom right cell
  return dp[m][n]
  
def main():
  # makes sure argument given
  if len(sys.argv) < 2:
      print("Usage: python script.py [argument]")
      sys.exit(1) 

  # number of recommendations for misspelled words
  num_words = int(sys.argv[1])
  # user input depending on certain factors
  min_word_length = 3
  max_edit_distance = 3

  word_dict = buildDictionary("dictionary.txt")

  miss_spelled = []
  # format into string and find words in text file not in the word_dict
  with open("misspelled.txt", 'r') as file:
    text = file.read()
    words = re.split(r'\W+|\B[^\w\s]+\B', text)
    words = [word.lower() for word in words if word and len(word) > 1]

    for word in words:
      if word not in word_dict:
        miss_spelled.append(word)

  # all misspellings
  for word in miss_spelled:
    word_arr = []
    # separates word and occurences from each word_dict item
    for dict_word, occurences in word_dict.items():
      # satisfies min word length
      if len(dict_word) >= min_word_length:
        # get edit distance
        result = ledAlg(word, dict_word)
        # satisfies max edit distance requirement
        if result <= max_edit_distance:
          word_arr.append((dict_word, result, occurences))
    # sort by edit distance and then by most occurences, store in tuple
    word_arr.sort(key=lambda x: (x[1], -x[2]))
    suggestions = tuple(item for item in word_arr[:num_words])
    print("Suggestions for", word, ":", suggestions)
    

if __name__ == "__main__": # run
  main()