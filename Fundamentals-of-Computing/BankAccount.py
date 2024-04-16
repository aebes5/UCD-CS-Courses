"""
BankAccount.py
Andrew Ebert
11/17/2022
"""

class BankAccount:

    def __init__(self):
        self.balance = 0
    def deposit(self, amount):
        if amount > 0:
            self.balance += amount

        else:
            print("Deposit amount ", "$", str(amount), "is less than 0. Transaction rejected")
            
    def withdraw(self, amount):
        if amount < self.balance:
             self.balance -= amount
        if amount < 0:
            print("Withdraw amount ", "$", str(amount), "is less than 0. Transaction rejected")
        if amount > self.balance:
            print("You don't have sufficient funds! ")
            
    def getBalance(self):
        return (self.balance)

