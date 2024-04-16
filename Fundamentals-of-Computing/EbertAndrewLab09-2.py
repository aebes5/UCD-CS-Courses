def read_data(file_name):
    infile = open(file_name, 'r')
    list_of_numbers = []
    
    for line in infile:
        val = (int(line))
        list_of_numbers.append(val)
        
    return list_of_numbers
    
def compute_sum(list_of_numbers):
    sum_list = 0
    
    for i in list_of_numbers:
        sum_list+= i
        
    return sum_list 

def compute_mean(list_of_numbers):
    sum_list = compute_sum(list_of_numbers)
    length = len(list_of_numbers)
    mean = sum_list / length
    
    return mean

def compute_sd(list_of_numbers):
    sum = 0
    mean = compute_mean(list_of_numbers)
    
    for num in list_of_numbers:
        dev = num - mean
        sq_dev = dev ** 2
        sum +=sq_dev
        
    length = len(list_of_numbers)
    sum_size = sum / (length-1)
    sd = sum_size ** 0.5
    
    return sd

def write_result(file_name, sum, mean, sd):
    outfile = open(file_name, 'w')
    print("Sum is: " , "%.2f"%sum , file = outfile)
    print("Mean is: " , "%.2f"%mean , file = outfile)
    print("Standard Deviation is: " , "%.2f"%sd , file = outfile)

def main():
    infileName = input("Enter the input file name: ")
    outfileName = input("Enter the output file name: ")
    
    my_list = read_data(infileName)
    sum = compute_sum(my_list)
    mean = compute_mean(my_list)
    sd = compute_sd(my_list)
    
    write_result(outfileName, sum, mean, sd)

