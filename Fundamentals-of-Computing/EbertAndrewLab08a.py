#Andrew
#Ebert
#10/13/2022
#This program show techniques of defining functions, parameter passing, and
#function invocation.

#fahreToCel function
#parameter: A temperature value in Fahrenheit
#returns equivalent temperature in Celsius
def fahrenToCel(fahren):
    result = (fahren - 32) * (5.0/9.0);
    return result

#fahrenToCelList function
#parameter: a list of temperature values in Fahrenheit
#converts the list to equivalent temperatures in Celsius
#If you pass a list as an argument, this will change the value in calling function
def fahrenToCelList(fahrenList):
    for i in range(len(fahrenList)):
        fahren = fahrenList[i]
        celsius = (fahren - 32) * (5.0/9.0)
        fahrenList[i] = round(celsius, 2)

#main function
def main():
    fval = float(input("Please enter the temperature in Fahrenheite: "))
    #call the function fahrenToCel
    cval = fahrenToCel(fval)
    print("Equivalent temperature in Celcius is {0:0.2f}".format(cval))

    fahrenheiteList = []
    #Take 5 temperatures as inputs and store them in fahrenhiteList
    for i in range(5):
        fahren = float(input("Enter temperature in Fahrenheit: "))
        fahrenheiteList.append(fahren)

    #call the function fahrenToCelList
    fahrenToCelList(fahrenheiteList)
    print("The converted tempertature list")
    print(fahrenheiteList)
