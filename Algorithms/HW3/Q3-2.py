import time
import matplotlib.pyplot as plt

def getArray(file_path): # create array from file

  arr = []
  
  with open(file_path, 'r') as file: # open file
   
    lines = file.readlines()
   
  
    for line in lines: # append ints
  
        values = line.split()
  
        for val in values:
  
          arr.append(int(val))


  return arr

def quickSort(arr): 
  
    if len(arr) <= 1: # base case
        return arr
      
    pivot = arr[len(arr) // 2]
  
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
  
    return quickSort(left) + middle + quickSort(right) # recursively call

def optimizedBubbleSort(arr):
  
  n = len(arr)
  
  while n > 1:
    
      newn = 0
    
      for i in range(1, n): # for each i
        
          if arr[i - 1] > arr[i]:
              arr[i - 1], arr[i] = arr[i], arr[i - 1] # swap elements
              newn = i
            
      n = newn
    
  return arr


def combinedSort(arr, k):
  
    n = len(arr)
  
    for i in range(n):
        swapped = False
      
        for j in range(0, n-i-1): # bubble
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
              
        if not swapped:
            break
          
    return arr[:k] + quickSort(arr[k:]) # merge bubble and quick

def timeEfficiency(funcName, *args, **kwargs): # reused time efficiency

  start_time = time.time()
  
  funcName(*args, **kwargs)
  
  end_time = time.time()
  total_time = end_time - start_time

  return total_time
  
k_values = [-7, -5, -3, 0, 3, 5, 7] # k values from hw

def findK(): # find time from k values
    data = getArray("rand1000000.txt")

    results = {}

    for k in k_values:
      
        def modified(arr): # alg does quicksort > k, combined otherwise
          combinedSort(arr, k)
          
        def combined(arr):
          if len(arr) > k:
            quickSort(arr)    
          else: 
            modified(arr)

        time_taken = timeEfficiency(combined, data) # time taken mapped to k value
        results[f'k{k}'] = time_taken

    return results


results = []

optimal_k = findK()

for k, time_taken in optimal_k.items(): # iterate through optimal_k
  
    print(f"{k}: {time_taken} seconds")
    results.append(time_taken)


plt.xlabel('k-values') # plot
plt.ylabel('time(sec)')
plt.title('k-values vs time')
plt.plot(k_values, results)
plt.show()