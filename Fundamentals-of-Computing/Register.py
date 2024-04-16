"""
Register.py
Andrew Ebert
11/17/2022
"""

from BankAccount import *

def main():
    account = BankAccount()
    count = int(input("Enter number of transactions: "))

    for i in range(count):
        transaction = (input("Enter transaction type: ")).lower()
        amount = float(input("Enter transaction amount: "))

        if transaction == str('withdraw'):
            account.withdraw(amount)

        if transaction == str('deposit'):
            account.deposit(amount)

        print("Account balance: ${0:.2f}".format(account.getBalance()))

    print("After", count, "transactions, your account balance is: ${0:.2f}".format(account.getBalance())) 

 
    
