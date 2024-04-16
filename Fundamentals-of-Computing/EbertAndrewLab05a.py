#Andrew
#Ebert
#9/22/2022
#Lab 5a: This lab will show various operations of String datatype

def main():
    firstName = input("Please enter your first name: ")
    lastName = input("Please enter your last name: ")

    #You can calculate the size/length of the string using len() function

    length = len(firstName)
    print("length of the first name is: ", length)

    length_2 = len(lastName)
    print("length of your last name is: ", length_2)

    #"+" operator is used to concatenate 2 strings

    fullName = firstName + " " + lastName
    print("Your full name is: ", fullName)

    #"*" operator is used as a repetition operator to make multiple copies
    #of a string

    n = int(input("Enter a number: "))
    print("Repeating your name", n, "times")
    print((firstName + " ") * n)

    #You can iterate through the characters using for loop

    print("Printing the full name using for loop")
    for ch in fullName:
          print(ch, end = "")

    #A string is a sequence of character, each individual character can be
    #accessed by using index. In Python index starts from 0. Here is an example
    #how we can run a loop to access all characters from a string.

    print("\nPrinting the name in reverse order")
    for i in range(-1, -(len(fullName)+1), -1):
          print(fullName[i], end = "")

    #Slicing operator is used to access a contiguous sequence of characters or
    #substring, here is an example of generating a username by using the first 3
    #characters of last name combined with first 3 characters of first name

    userName = lastName[0:3] + firstName[0:3]
    print("\nYour username is: ", userName)
          
