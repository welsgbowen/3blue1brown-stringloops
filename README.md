# 3blue1brown-stringloops
A naive monte carlo approach to solve 3blue1brown's third "puzzle of the month" about the average number of loops from strings in a box.

The puzzle reads as follows:
Imagine you have a lot of pieces of string, and you drop them into a box. You reach in and
blindly grab two random 'ends', and you tie those two ends together. Then, you do it again. 
Choose two more ends at random, tie them together, and put the result back in. Choose another 
two... and so on and so forth. Every now and then, you grab two ends of the same string, 
meaning when you tie them togehter, you form a loop. In fact, the end condition here, when 
there are no endpoints left, is one where all you have is loops inside that box. 

Here's the question: If we start with 50 total strings, and we go through that process 50 times, 
tying two ends together, how many loops on average do you end up with?

This solution will find the average number of loops for a given number of strings over
a series of simulations.

Compile program using gcc

    gcc stringLoops.c -o loops
    
Run the executable with the required arguments

    ./loops <number of strings> <number of simulations>
