* Name : Andrew Ebert
* Student ID: 110048682
* Class : CSCI 3412 Section 02
* PA# : 1b
* Due Date : January 31, 2024
# Read Me
## Description of the program

The first part of this assignment was to implement a number guessing game using a Binary Search Algorithm. The game has one function that generates a random number between 1-1,000 and another function that generates a random number between 1-1,000,000. Each game is performed 10,000 times to get an average amount of guesses it takes to reach the random number.

The second part of this assignment was to implement a timer function that calculates the time it takes to run a different function. For this assignment, the timer function is tested with a function that generates prime numbers.

The third part of this assignment was to implement a guessing game for 3 numbers; the first algorithm systematically attempted to guess the number while the second algorithm randomly generated numbers until the randomly generated number equalled the initial number generated.

The fourth part of this assignment performed Collatz algorithm and tracked the steps and max number reached for each number. This program stored the top 10 numbers(by steps) within the given range.

The EC portion of this assignment was using python decorators as an extension of part two.

## Source files

**main.py**

This is the main file which contains all of the functions used for all parts of this assignment.


## Circumstances of programs
The program runs successfully. It was compiled, run, and tested on VSCode and REPLIT.

## How to build and run the program
Unhighlight the driver function call below the part of the assignment you are trying to run (ex: to test Q1 unhighlight the #numGuessing() on line 54). Click the **green run** button.

## Outputs

**Q1**
![image](image.png)

**Q2**
![image](image_2.png)

**Q3**
![image](image_3.png)

**Q4**
![image](image_5.png)

**EC**
![image](image_4.png)


## EC Questions

**1)**
Higher-order functions are built to take in and return functions whereas a functor is more like an object with similar purposes.

**2)**
First class objects are entities in programming languages such as being created dynamically, assigning a function to a variable, or returned from a function. First class objects create a lot more flexibility when using/assigning entities.

**3)**
Inner functions are functions that are created within another function. A major benefit of inner functions are encapsulation as well as reusability when it comes to a functionality that might be reused many times.

**4)**
Some advantages of decorators include encapsulation, code reusability, and efficiency; some disadvantages of decorators include ease of implementation, not always more efficient, and confusion for programmers.

**5)**
The @ symbol makes code easier to read as the @ symbol has a unique function in python; similarly, the @ symbol reduces code redundancy and instead points the programmer back to the decorator implemented.

**6)**
The @Property decorator allows for the implementation of getters, setters, and deleters. One drawback to python is the lack of encapsulation, but this decorator would allow for more of a private variable functionality which can be seen in other programming languages.