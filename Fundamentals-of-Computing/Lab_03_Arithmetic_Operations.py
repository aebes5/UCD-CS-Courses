#
#Name: Andrew Ebert
#Class: CSCI 1411-005
#Due Date: 09/15/2022
#Description: The goal of this program is to generate code that can calculate the cost of trim boards needed to cover a
#certain perimeter based on the length and width, while also giving the inches of trim board wasted and the equivalent cost.
#Status: The program runs smoothly and gives the desired output, I struggled with the floats to get 2 decimal points in this lab.

def main():
    l = float(input("Enter the length of the box in inches"))
    w = float(input("Enter the width of the box in inches"))

    float(l)
    float(w)
    
    p = (2 * l) + (2 * w)
    print("Thank you, it appears your box has a perimeter of", p)

    b = (int(p / 12))+1
    print("You will need to buy", b ,"trim boards")
  
    
    c = (int(b)) * 1.88
    print("This will cost $", str(round(c, 2)))

    a = (b * 12) - p
    b = (a * 1.88)/ 12
    print("You will waste", str(round(a, 2)) ,"inches trim, which equates to a waste of $", str(round(b, 2)))
