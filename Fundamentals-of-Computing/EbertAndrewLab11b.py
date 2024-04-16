def main():
    file_name = input("What is the name of the file you want to open: ")
    word = input("What is the word you want counted: ")
    times = 0

    try:
        infile = open(file_name, "r")
        for line in infile:
            for words in line.split(" "):
                if words == word:
                    times += 1
        print(times)

    except FileNotFoundError:
        print("File" , file_name, "not found. Please try again.")
       
