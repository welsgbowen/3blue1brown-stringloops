#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 

    Wels Bowen
    May 22, 2026

    stringLoops , a naive approach to 3blue1brown's third "puzzle of the month".
    
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

*/

// Picks two random unique indexes in array arr of length size. Stores result in indexes.
void pickTwo(int arr[], int size, int indexes[]) {
    int index1 = rand() % size;
    int index2;
    do {
        index2 = rand() % size;
    } while (index1 == index2);
    indexes[0] = arr[index1];
    indexes[1] = arr[index2];
}

// Removes both ends of a target string from the array. Updates the array_size (array_size-2).
void removeString(int arr[], int target, int *array_size) {
    int write_index = 0;
    for (int read_index = 0; read_index < *array_size; read_index++) {
        if (arr[read_index] != target) {
            arr[write_index] = arr[read_index];
            write_index++;
        }
    }
    *array_size = write_index;
}


int main (int argc, char *argv[]) {
    // Seed random time for rand() function.
    srand(time(NULL)); 
    int string_amount;
    int simulations;
    int total_loops = 0;
    int max_loops = 0;
    int max_loops_sim_number = 0;
    if (argc == 3) {
        string_amount = atoi(argv[1]);
        simulations = atoi(argv[2]);
    }

    if (argc != 3) {
        printf("How many strings should the box have?\n");
        scanf("%d", &string_amount);
        printf("%d strings chosen.\n", string_amount);

        printf("How many times do you want to run the simulation?\n");
        scanf("%d", &simulations);
    }

    // Main simulation loop. 
    for (int i = 0; i < simulations; i++) {
        int loops = 0;
        int indexes[2];
        int ends_amount = string_amount*2;
        int ends[ends_amount];

        // Create the initial array of string ends. Looks like [0, 0, 1, 1, 2, 2, ... , n-1, n-1]
        // where n = string_amount and each number represents an end of a string.
        for (int i = 0; i < string_amount; i++) {
            ends[i*2] = i;
            ends[(i*2)+1] = i;
        }

        // Randomly picks all the string ends. Checks if attaching them makes a loop. Repeated i = string_amount times so all ends are chosen.
        for (int i = 0; i < string_amount; i++) {

            // Pick two random indexes in ends and store in array indexes
            pickTwo(ends, ends_amount, indexes);

            // 2 cases: Both ends are on same string, or ends are on different strings.
            // In both cases, one string is removed from the box. 
            // If both ends are on the same string, a loop is created.
            removeString(ends, indexes[1], &ends_amount);
            if (indexes[0] == indexes[1]) loops++;
        }
        total_loops += loops;
        if (loops > max_loops) {
            max_loops = loops;
            max_loops_sim_number = i;
        }
    }
    double loops_per_simulation = (double)total_loops / simulations;
    printf("total loops: %d\n", total_loops);
    printf("maximum loops: %d, Occured in simulation %d\n", max_loops, max_loops_sim_number);
    printf("For %d simulations of %d strings, there was an average of %f loops\n", simulations, string_amount, loops_per_simulation);
    return 0;
}