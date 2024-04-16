#Andrew
#Ebert
#9/29/2022
#Description:Lab 6 demonstrates various functions of the String datatype.

def main():

    #Python translates each character to a number. The ord() function in python
    #accepts a single character string as an argument and returns the numeric
    #code of it. The ord() function returns an integer representing the Unicode
    #character.

    ch = input("Please enter a single character: ")
    value = ord(ch)
    print("The numeric representation of", ch, "is", value)

    #The chr() function does the reverse. chr() function takes an integer as an
    #argument and returns the equivalent character.

    print("The equivalent character of the number", value, "is", chr(value))

    #The following piece of code will take a string as input and it will convert
    #each of the characters as a sequence of numbers(separated by whitespace)

    txt = input("Please enter a text: ")
    for ch in txt:
        print(ord(ch), end = " ")

    #split function splits a string into a list of substrings based on a delimiter.

    txt1 = input("\nPlease enter a string with space: ")
    listSubStrings = txt1.split(" ")
    print(listSubStrings)

    #join function joins the list of strings into one string using a delimiter

    newString = "-".join(listSubStrings);
    print(newString)

