* Name : Andrew Ebert
* Student ID: 110048682
* Class : CSCI 2312 Section 02
* PA# : 3
* Due Date : Feb 27, 2023
  
# Read Me

## Description of the program
This program asks the user to choose a function they want to execute; (1)Get trip cost, (2)Average distance, (3)Closest city, (4)City with smallest average distance, and (5)Farthest two cities. If the user doesn't enter a valid function(1-5), the program quits. For functions 1-3, the user enters a city, and if the input is not valid according to the enum table of cities, the program quits. Function 1 will ask the user for two cities, the miles per gallon of their vehicle, and the cost of gas; the program will return the cost it would take to drive between the two cities. Additionally, if one of the cities is Denver, and the other city is[Seattle, Los Angeles, or San Francisco], the program exectues a **WEATHER ALERT** which adds 75 miles to the trip. Function 2 asks the user for a city and returns the average distance to the other cities. Function 3 asks the user for a city, and returns the closest city to the one given. Function 4 returns the city with the smallest average distance, as well as the average distance. Function 5 returns the two farthest cities, as well as the distance between the two.

## Circumstances of programs
The program runs successfully. It was compiled, run, and tested on VSCode and REPLIT.

## Problems encountered
I first developed the program on VSCode, but ran into a problem when I copy and pasted the code into Replit. Function #5 in the program would return **Atlanta/Invalid city[5084224]**. I found the problem was in line #356 of the program, and I fixed this problem by setting the **farthest_distance** variable equal to 0. Before, the **farthest_distance** variable was created as dyanamic initialization, but I had to change this to static initialization(set equal to 0). I'm still not sure why the same code in VSCode returned the correct information while Replit didn't.

## How to build and run the program
Click the **green run** button.

