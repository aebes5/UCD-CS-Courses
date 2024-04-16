import random
import time

#Q1 - Number guessing game

def binarySearch(random_num, left, right):
  
  guesses = 0

  while left <= right: #change middle index for each guess
    middle = (left + right) // 2
    if middle == random_num:
      guesses += 1
      return guesses
    elif middle > random_num:
      right = middle - 1
      guesses += 1
    elif middle < random_num:
      left = middle + 1
      guesses += 1

  return -1 #else case

def tenThousandGame():

  running_total = 0

  for _ in range(10000): #10,000 times
    random_num = random.randint(1,1000) #random number(1,1000)
    guesses = binarySearch(random_num, 1, 1000)
    running_total += guesses
    
  return running_total

def millionGame():
  
  running_total = 0

  for _ in range(10000): #10,000 times
    random_num = random.randint(1,1000) #random number(1,1000000)
    guesses = binarySearch(random_num, 1, 1000000)
    running_total += guesses

  return running_total

def numGuessing(): #driver function
  
  running_total_ten = tenThousandGame()
  print(f"1. The random numbers between 1 .. 1K: Total guesses: {running_total_ten} Avg: {running_total_ten / 10000}")

  running_total_million = millionGame()
  print(f"2. The random numbers between 1 .. 1M: Total guesses: {running_total_million} Avg: {running_total_million / 10000}")

#numGuessing()



#Q2 - Simple timer function

def listPrimeNumbers(max_num):
  
  primes = [] #stored in array returned

  for num in range(max(2, 1), max_num + 1): #find primes
      is_prime = True
      for i in range(2, int(num**0.5) + 1):
          if num % i == 0:
              is_prime = False
              break
      if is_prime:
          primes.append(num)

  return primes

def timeEfficiency(funcName, *args, **kwargs):
  
  start_time = time.time()
  
  primes = funcName(*args, **kwargs) #primes function

  end_time = time.time()
  total_time = end_time - start_time

  print(f"Start Time: {start_time}")
  print(f"End Time: {end_time}")
  print(f"Total Time: {total_time} seconds")

  return primes

def testEfficiency():
  
  numbers = int(input("Enter a number for the list of prime numbers: "))
  primes = timeEfficiency(listPrimeNumbers, numbers)
  print(f"List of prime numbers of {numbers} {primes}")

#testEfficiency()



#Q3 - Another Guessing Game

def randomNumbers():
  
  rand1 = random.randint(1, 9)
  rand2 = random.randint(1, 9)
  rand3 = random.randint(1, 9)
  random_num = str(rand1) + str(rand2) + str(rand3) #3 random numbers put into string
  return random_num

def bruteForce(random_num):
  
    guessed = False
    current = '000'
    guesses = 0

    while not guessed:
      
        if current == random_num: #guessed
          guessed = True
        elif current[0] != random_num[0]: #first digit wrong
            current = str((int(current[0])) + 1) + str(current[1]) + str(current[2])
            guesses += 1
        elif current[1] != random_num[1]: #second digit wrong
            current = str(current[0]) + str((int(current[1])) + 1) + str(current[2])
            guesses += 1
        elif current[2] != random_num[2]: #third digit wrong
            current = str(current[0]) + str(current[1]) + str((int(current[2])) + 1)
            guesses += 1
        else:
            return -1
          
    return guesses

def randomGuessing(random_num):
  
    guessed = False
    guesses = 0

    while not guessed:
      
        guesses += 1
        rand1 = random.randint(1, 9)
        rand2 = random.randint(1, 9)
        rand3 = random.randint(1, 9)
        guess = str(rand1) + str(rand2) + str(rand3) #randomly generated guess

        if guess == random_num or guesses == 10000: #10000 - max guesses
            return int(guesses)

def guessingGame(): #driver
  
  brute_force_tot = 0
  random_guess_tot = 0
  stopped = 0
  tries = 10000
  highest_brute = 0
  highest_random = 0
  lowest_brute = 10000
  lowest_random = 10000

  for _ in range(tries): #10,000 times
    
      random_num = randomNumbers()
      brute_force_num = bruteForce(random_num)
      random_guess_num = randomGuessing(random_num)

      if brute_force_num > highest_brute: #tracks highest/lowest amount of guesses
          highest_brute = brute_force_num
      elif brute_force_num < lowest_brute:
          lowest_brute = brute_force_num
      elif random_guess_num > highest_random:
          highest_random = random_guess_num
      elif random_guess_num < lowest_random:
          lowest_random = random_guess_num

      brute_force_tot += brute_force_num
      random_guess_tot += random_guess_num

      if random_guess_num == 10000:
          stopped += 1

  print("Deterministic brute-force guessing algorithm:\n")
  print(f"Number of Tries: {tries}")
  print(f"The highest number of guesses in a try: {highest_brute}")
  print(f"The lowest number of tries: {lowest_brute}")
  print(f"The average number of tries: {brute_force_tot/tries}\n\n")

  print("Pure random guessing algorithm:\n")
  print(f"Number of Tries: {tries}")
  print(f"The highest number of guesses in a try: {highest_random}")
  print(f"The lowest number of tries: {lowest_random}")
  print(f"The average number of tries: {random_guess_tot/tries}")
  print(f"Times stopped: {stopped}")

#guessingGame()



#Q4 - Collatz 3n+1 algorithm

def collatsAlg(start, stop, num_displayed):

  dic_list = [{"steps": 0, "number": 0, "max_number" : 0} for _ in range(num_displayed)] #list of dicts

  while start <= stop: #haven't reached end
    
    original_num = start
    num = start
    steps = 0
    max_num = start

    while num != 1: #alg stops when number converges to 1

      if num % 2 == 0:
        num = num // 2
        steps += 1
      else:
        num = (num * 3) + 1
        steps += 1
        
        if num > max_num: #track max number reached 
          max_num = num

    if steps > dic_list[0]["steps"]: #if steps > first element steps, replace first dict

      dic_list.append({"steps": steps, "number": original_num, "max_number" : max_num})
      dic_list.pop(0)
      dic_list.sort(key=lambda x: x["steps"])


    start += 1

  for i in range(len(dic_list)): #print result
    
    print(f"{10 - i}. Number: {dic_list[i]['number']} Steps: {dic_list[i]['steps']} Max Number: {dic_list[i]['max_number']}")

collatsAlg(1, 10000000, 10)



#Extra Credit - Simple timer function w/ decorator

def timePassedEC(func): #wrapper func
  def wrapper(*args, **kwargs):
    
    start_time = time.time()
    result = func(*args, **kwargs)
    end_time = time.time()
    total_time = end_time - start_time

    print(f"Start Time: {start_time}")
    print(f"End Time: {end_time}")
    print(f"Total Time: {total_time} seconds")

    return result

  return wrapper

@timePassedEC #inclusion
def listPrimeNumbersEC(max_num):
  primes = [] 

  for num in range(max(2, 1), max_num + 1): 
      is_prime = True
      for i in range(2, int(num**0.5) + 1):
          if num % i == 0:
              is_prime = False
              break
      if is_prime:
          primes.append(num)

  return primes

def testEfficiencyEC():
  numbers = int(input("Enter a number for the list of prime numbers: "))
  primes = listPrimeNumbersEC(numbers)
  print(f"List of prime numbers of {numbers} {primes}")

#testEfficiencyEC()
      