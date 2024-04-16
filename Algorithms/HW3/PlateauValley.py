def main(arr):

  for i in range(0, len(arr) - 2, 2):
    if arr[i] > arr[i + 1]:
      arr[i], arr[i + 1] = arr[i + 1], arr[i]
    if arr[i + 1] < arr[i + 2]:
      arr[i + 1], arr[i + 2] = arr[i + 2], arr[i + 1]

  print(arr)
