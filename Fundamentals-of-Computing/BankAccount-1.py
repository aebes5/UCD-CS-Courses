# BankAccount.py
# Author: Andrew Ebert
# Date: 12/1/2022

#import Transaction class
from Transaction import *

def main():
    """Display main menu and class functions based on the selected action"""

    print ('Welcome to Bank Account Application')
    print ()

    done = False

    # Create an empty list of transactions
    list_of_transactions = []

    #Loop as long as done is False
    while (not done):
        #Display menu
        print ('===================================')
        print ('A - Read data from the file')
        print ('B - Display list of transactions')
        print ('C - Add a new transaction')
        print ('D - Calculate current balance')
        print ('E - Save data to a file')
        print ('Q - Quit')
        print ('===================================')
        print ('Please select an action by typing A, B, C, D, E, or Q')
        action = input ('? ')

        if (action == 'A' or action == 'a'):
            read_data (list_of_transactions)
        elif (action == 'B' or action == 'b'):
            display_list (list_of_transactions)
        elif (action == 'C' or action == 'c'):
            add_transaction (list_of_transactions)
        elif (action == 'D' or action == 'd'):
            calculate_balance (list_of_transactions)
        elif (action == 'E' or action == 'e'):
            save_data (list_of_transactions)
        elif (action == 'Q' or action == 'q'):
            done = True
        else:
            print ('Incorrect action type. Please try again')

        print ()

    print ('Thank you for using Bank Account Application')

def read_data (list_of_transactions):
    """Read data from the input file, create transaction object and add it to
       the list of transactions"""

       # Ask user for name of the input file, read each line of the data,
       # split line using colon (:) is delimiter, create transaction object
       # and add it to the list of transaction. Display error message if the
       # input file is not found.

    try:
        file_name = input("Please enter the input file: ")
        infile = open(file_name, 'r')
        for line in infile:
            objects = line.split(":" or " ")
            list_of_transactions.append(Transaction(objects[0], objects [1], objects[2]))

    except IOError:
        print("Error")


    print ('Read Data Function')
    


def display_list (list_of_transactions):
   """ Displays list of transactions """

   # Sort the list of transactions by date and display list of transactions
   # in form of a table
   sorted_list = sorted(list_of_transactions, key = lambda x: x.get_date())
   print("List of transactions")
   print("Date     Type         Amount")
   print("===================================")
   for transaction in sorted_list:
       print(transaction.get_date(), transaction.get_transaction_type(), "$", transaction.get_amount())
   print("===================================")
   print("End of the list")
           


def add_transaction (list_of_transactions):
    """Adds a new transaction to list of Transactions"""

    # Ask user for date, type, and amount of transaction, create a transaction
    # object and append it to the list of transactions.
    # Display an error message if the transaction type is not valid or amount
    # is negative. Valid transaction types are deposit, withdraw, bank charge
    # and interest
    date = input("Enter a date using the format yyyymmdd: ")
    type_of_trans = input("Enter the transaction type: ")
    amount = float(input("Enter the transaciton amount: "))
    if type_of_trans == 'deposit':
        new_trans = Transaction(date, type_of_trans, amount)
        list_of_transactions.append(new_trans)
    elif type_of_trans == "withdraw":
        new_trans = Transaction(date, type_of_trans, amount)
        list_of_transactions.append(new_trans)
    elif type_of_trans == "interest":
        new_trans = Transaction(date, type_of_trans, amount)
        list_of_transactions.append(new_trans)
    elif type_of_trans == "bank charge":
        new_trans = Transaction(date, type_of_trans, amount)
        list_of_transactions.append(new_trans)
    else:
        print("Error")

def calculate_balance (list_of_transactions):

    """Calculates the current balance"""

    # Start with initializing balance to zero
    # For each transaction in the list of transactions you will
    # add the amount to balance if the transaction type is deposit or interest
    # subtract the amount if transaction type is withdraw or bank charge
    # Print the balance on the screen
    balance = 0
    for transaction in list_of_transactions:
        if transaction.get_transaction_type() == "withdraw" or transaction.get_transaction_type() == "bank charge":
            trans_amount = transaction.get_amount()
            balance -= trans_amount
        else:
            balance += trans_amount
    print ('Current balance is ', balance)
            
        


def save_data (list_of_transactions):
    """ Saves list of transaction to a file"""

    # Ask user for name of the output file, sort the list of transactions by date
    # and save the data using the following format:
    # date:transaction_type:amount
    # Display a message that data was saved to the output file.
    output_file = input("Enter the output file: ")
    new_file = open(output_file, 'w')
    new_list_of_transactions = sorted(list_of_transactions, key = lambda x: x.get_date())
    for transaction in list_of_transactions:    
        write = transaction.get_date() , ":" , transaction.get_transaction_type() , ":" , str(transaction.get_amount()) , "\n"
        new_file.write(','.join(write))
    new_file.close()
