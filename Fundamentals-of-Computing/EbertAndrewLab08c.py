#Andrew
#Ebert
#10/13/2022
#This program doubles the value of a list

def findDoubles(valList):
    for i in range(len(valList)):
        val = valList[i]
        valList[i] = int(val) * 2
def main():
    
    valList = []
    for i in range(5):
        val = input("Please enter a number: ")
        valList.append(val)
    findDoubles(valList)
    print(valList)
