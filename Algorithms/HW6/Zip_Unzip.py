from heapq import heappush, heappop, heapify
from bitarray import bitarray
import os

# set terminal encoding to UTF-8
os.environ["LC_ALL"] = "en_US.UTF-8"


def main():
  
  file = input("Enter a file name to encode: ") # build the table
  huffman_dict, huffman_table = huffman()

  huffman_cost = 0
  huffman_size = 0

  print("character      Weight            Huffman Code")
  for item in huffman_table: # cleanly formatted
    huffman_cost += item[2] * len(item[1]) # calculate freq * len(01000)
    huffman_size += item[2]
    
    if item[0] != "\n":
      print(f"{item[0]:<13}", f" {item[2]:<18}", f" {item[1]}")
    else:
      item[0] = "\\n"
      print(f"{item[0]:<13}", f" {item[2]:<18}", f" {item[1]}")

  zipped_file = zip(file, "King.zip", huffman_dict) # zip
  unzipped_file = unzip("King.zip", huffman_dict) # unzip

  LCS = 1 # find bits for LCS
  powers = 2
  while len(huffman_table) > powers:
    powers *= 2
    LCS += 1

  print(f"Expected cost of Huffman code: {huffman_cost}") # outputs
  print(f"Expected cost of ASCII: {huffman_size * 8}")
  print(f"Huffman efficiency improvement over ASCII code: {round((huffman_size * 8 / huffman_cost - 1) * 100)}%")
  print(f"Expected cost of optimal FCL cost: {LCS * huffman_size}")
  print(f"Huffman efficiency improvement over FCL: {round(((LCS * huffman_size) / huffman_cost - 1) * 100)}%")
  print(f"The size of King.txt: {huffman_size}")
  print(f"The size of King.zip: {os.path.getsize('/home/runner/HW6/King.zip')}")
  print(f"The size of King.unzipped.txt: {os.path.getsize('/home/runner/HW6/King.unzipped.txt')}")
  

def huffman():
    aDict = {}

    table_file = input("Enter the name of the file you want to use for the Huffman table: ")

    # Read the input file and build the dictionary with character frequencies
    with open(table_file, "r", encoding="utf-8") as file:
        for line in file:
            # Iterate over each character in the line, including newline characters
            for char in line:
                #print(char)
                if char in aDict:
                    aDict[char] += 1
                else:
                    aDict[char] = 1

    # Build the Huffman tree
    heap = [[freq, [aChar, "", freq]] for aChar, freq in aDict.items()] # build a minheap
    heapify(heap)

    # Check if heap is empty
    if not heap:
        print("Error: No valid characters found in the file.")
        return []

    while len(heap) > 1:
        lo = heappop(heap) # pop least frequent
        hi = heappop(heap) # next least frequent

        # Assign Huffman code to each character
        for pair in lo[1:]:
            pair[1] = '0' + pair[1] # pair[1] is the current codeword for pair[0] char
        for pair in hi[1:]:
            pair[1] = '1' + pair[1]

        # Combine subtrees and update frequencies
        heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:]) # push then heapify

    huffman_dict = {} # dict of characters and their huffman codes
    sorted_list = sorted(heappop(heap)[1:], key=lambda p: (len(p[1]), p[0])) # shows everything sorted by freq
  
    for item in sorted_list:
        huffman_dict[item[0]] = item[1]
  
    return huffman_dict, sorted_list

  

def zip(text, file_name, huffman_table):
  with open(text, "r", encoding="utf-8") as file:
    text = file.read()

    with open(file_name, "wb") as file_name: # write binary
      bit_array = bitarray()
      for char in text:
        bit_array.extend(huffman_table[char]) # append huffman code

      bit_array.tofile(file_name) # write to zip file

  return file_name 
    

def unzip(zip_file_name, huffman):
  with open(zip_file_name, "rb") as file:
    bit_str_stream = "" # store binary
    
    for byte in file:  # read byte by byte
      bit_str_stream += format(int.from_bytes(byte, byteorder='big'), '08b') # type error initially, fixed by adding 'big'
  
    sub_str = "00" # left off the first two bits initially
    final_str = ""
    
    for bit in bit_str_stream: # add bytes until substr is in dict
      sub_str += bit
      for key, value in huffman.items():
        if value == sub_str:
          final_str += key
          sub_str = ""
          break
          
    with open("King.unzipped.txt", "w", encoding="utf-8") as file: # write string to file
      file.write(final_str)
        

if __name__ == "__main__": # run
  main()