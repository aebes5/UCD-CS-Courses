"""
Andrew Ebert
11/3/2022
This program performs the following tasks:
    -It will ask user for a number, number must be greater than or equal to
    2. If the user enters a number less than 2, it will display an error message.
    It will also display an error if the user doesn't enter a numerical number
    or floating number.
    -It will calculate and display all prime numbers between 2 and the user
    entered number.

"""

def is_prime(num):
    square_root = num ** 0.5
    for n in range(2, int(square_root + 1)):
        if (num % n == 0):
            return False
    return True

def main():
    error = True
    while error:
        try:
            user_input = int(input("Enter a whole number >= 2: "))
            if user_input < 2:
                print("Input must be > 2. Please try again.")
            else:
                error = False
        except ValueError as err:
                print("Input is non-numerical. Please try again.")
    print("Following numbers between 2 and", user_input, "are prime:")

    for num in range(2, int(user_input + 1)):
        result = is_prime(num)
        if result:
            print(num, end = " ")
