#
#Name: Andrew Ebert
#Class: CSCI 1411-005
#Due Date: 09/07/2022
#Description: The goal of this program is to follow the steps of the assignment, fixing errors along the way, while giving the desired output.
#Status: The program runs smoothly and gives the desired output.

def main():
    firstName=input("Enter your first name")
    lastName=input("Enter your last name")
    faren=(int)(input("What is the temperature in Fahreneit?"))
    celcius=(faren-32)*(5/9)
    print (firstName," ", lastName, "the celcius temperature is", celcius, "degrees")
