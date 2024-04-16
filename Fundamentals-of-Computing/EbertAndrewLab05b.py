#Andrew
#Ebert
#9/22/2022
#Lab 5b: This lab will show various operations of String datatype

def main():
    firstName = input("Please enter your first name: ")
    lastName = input("Please enter your last name: ")

    userName = lastName[0:] + firstName[0]
    print("Your username is: ", userName)

    FirstName = firstName.lower()
    LastName = lastName.lower()
    email = FirstName + "." + LastName + "@ucdenver.edu"
    print("Your email is: ", email)
