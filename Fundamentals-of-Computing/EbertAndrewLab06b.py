#Andrew
#Ebert
#9/29/2022
#Description:Lab 6 demonstrates various functions of the String datatype.

def main():
    txt = input("Please enter the string: ")
    num = int(input("Please enter the key: "))

    enc = ''
    for ch in txt:
        enc+= chr(ord(ch) + num)
    print("The Encoded message is: " + enc)

    dec = ''
    for ch in enc:
        dec+= chr(ord(ch) - num)
    print("The Decoded message is: " + dec)
