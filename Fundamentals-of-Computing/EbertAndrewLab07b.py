#Andrew
#Ebert
#10/6/2022
#This program reads the names from a file and calculates the average score for each student.

def main():
    
    infileName = input("Enter the input file name: ")
    infile = open(infileName, "r")
    outfileName = input("Enter the output file name: ")
    outfile = open(outfileName,"w")
    read_lines = infile.readlines()
    
    for i in read_lines:
        spl = i.split(" ")
        sum = 0
        for i in range (1 , 6):
            sum = sum + int(spl[i])
            average = sum / 5.0
      
        print(spl[0] + " " + str(average), file = outfile)

    infile.close()
    outfile.close()
        
