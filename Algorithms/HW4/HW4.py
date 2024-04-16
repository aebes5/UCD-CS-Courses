import heapq

def getArray(file_path): # stores the ints from file in arr and returns
    arr = []
    with open(file_path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            values = line.split()
            for val in values:
                arr.append(int(val))
    return arr

def countingSort(arr, exp):
    n = len(arr) # initialize arrays
    output = [0] * n
    count = [0] * 10

    for i in range(n): # store occurences
        index = arr[i] // exp
        count[index % 10] += 1

    for i in range(1, 10): # now i is correct digit
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0: # setup output array
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(n): # copies output to arr
        arr[i] = output[i]

def radixSort(arr):
    max_value = max(arr)
    exp = 1
    while max_value // exp > 0: # count sort for every digit
        countingSort(arr, exp)
        exp *= 10

def insertionSort(bucket): # generic insertion sort for each bucket
    for i in range(1, len(bucket)):
        key = bucket[i]
        j = i - 1
        while j >= 0 and key < bucket[j]:
            bucket[j + 1] = bucket[j]
            j -= 1
        bucket[j + 1] = key

def bucketSort(arr):
    n = len(arr)
    buckets = [[] for _ in range(n)] # buckets
    max_value = max(arr)

    for num in arr:
        if max_value == 0: # empty check
            index = 0
        else:
            index = int((num / max_value) * (n - 1))  # adjust index
        buckets[index].append(num)

    for bucket in buckets: # perform insertion sort
        insertionSort(bucket)

    index = 0
    for bucket in buckets: # simplifies buckets to arr
        for num in bucket:
            arr[index] = num
            index += 1

def sortedLists(textfile):
    arr = getArray(textfile) # gets array

    newarr = [] # store sublists

    size = len(arr) // 100 # size of sublist

    for i in range(100):
        j = size * (i + 1)
        newarr.append(arr[size * i: j])  # append sublist

    for sublist in newarr[:50]: # 50 radix
        radixSort(sublist)

    for sublist in newarr[50:]: # 50 bucket
        bucketSort(sublist)
        
    sorted_list = uniqueSortedLists(newarr) # merge lists

    print(len(sorted_list))
    return isSorted(sorted_list)  # verify it's sorted

def uniqueSortedLists(lists):
    initial_heap = []
    for sublist in lists:
        initial_heap.append(sublist[0])  # builds our initial heap of size 100 - sublists

    heapq.heapify(initial_heap)  # heapify

    sorted_list = []  # sorted list

    while initial_heap:  # until empty
        min_value = heapq.heappop(initial_heap)  
        sorted_list.append(min_value)  # pop min element and append to list
        
        # get the sublist with removed element
        sublist_index = next(i for i, sublist in enumerate(lists) if sublist[0] == min_value)
        
        # if !empty, this sublist will insert next element into heap
        if len(lists[sublist_index]) > 1:
            next_element = lists[sublist_index][1]
            heapq.heappush(initial_heap, next_element)
            lists[sublist_index].pop(0)

        else:
            del lists[sublist_index] # remove if no more elements

    return sorted_list # return sorted list


def isSorted(arr): # verify list is sorted
    for i in range(len(arr) - 1):
        if arr[i] > arr[i + 1]:
            return False
    return True

print(sortedLists('rand1000000.txt')) # should return size and True if properly sorted
