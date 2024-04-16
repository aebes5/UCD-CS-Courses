import time

def timeEfficiency(funcName, *args, **kwargs):

  start_time = time.time()

  iterations = funcName(*args, **kwargs)

  end_time = time.time()
  total_time = end_time - start_time

  print(f"Start Time: {start_time}")
  print(f"End Time: {end_time}")
  print(f"Total Time: {total_time} seconds")

  return iterations


def insertionSort(arr):

  iterations = 0
  
  
  for i in range(1, len(arr)):   
    key = arr[i]
    j = i-1
    
    while j >= 0 and key < arr[j]:
      arr[j + 1] = arr[j]
      j -= 1
      iterations += 1
    arr[j + 1] = key
  
  return iterations

merge_sort_iterations = 0 # globally track iterations through recursive calls

def mergeSort(arr):

  global merge_sort_iterations

  if len(arr) > 1:
      # divide the array
      mid = len(arr) // 2
      left_half = arr[:mid]
      right_half = arr[mid:]

      # sort each half
      mergeSort(left_half)
      mergeSort(right_half)

      # merge halves
      i = j = k = 0

      while i < len(left_half) and j < len(right_half):
          merge_sort_iterations += 1
          if left_half[i] < right_half[j]:
              arr[k] = left_half[i]
              i += 1
          else:
              arr[k] = right_half[j]
              j += 1
          k += 1

      while i < len(left_half):
          merge_sort_iterations += 1
          arr[k] = left_half[i]
          i += 1
          k += 1

      while j < len(right_half):
          merge_sort_iterations += 1
          arr[k] = right_half[j]
          j += 1
          k += 1
  return merge_sort_iterations

def getArray(file_path): # create array from file

  arr = []
  
  with open(file_path, 'r') as file:

      lines = file.readlines()
  

      for line in lines:
        
          values = line.split()
  
          for val in values:
            
            arr.append(int(val))
  

  return arr


fileNames = ["rand1000.txt", "rand10000.txt", "rand100000.txt", "rand250000.txt", "rand500000.txt", "rand1000000.txt" ]

for file in fileNames: # iterate through each file and print results
  
  print("\033[1m{}\033[0m".format(file))
  arr = getArray(file)
  print("\033[4mInsertion sort:\033[0m")
  print(f"Iterations: {timeEfficiency(insertionSort, arr)}")
  print("\033[4mMerge sort:\033[0m")
  print(f"Iterations: {timeEfficiency(mergeSort, arr)}")
