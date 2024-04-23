/*
    Demonstrate the list data structures in `dsl_lists.h` and the sorting algorithms in `dsl_listsort.c`.

    The following list data structures are demonstrated:
    - Singly Linked List
    - Doubly Linked List
    - Circular Linked List
    - Queue
    - Stack

    The following list sorting algorithms are demonstrated:
    - Bubble Sort
    - Selection Sort
    - Insertion Sort

    Benchmarking
    - The time taken to sort a list of 1000 elements is measured for each sorting algorithm.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "dsl_lists.h"
#include "dsl_listsort.h"
#include "dsl_benchmarking_suite.h"

#define LIST_SIZE 1000

//  Printing functions
void PRINT_LINE(){
    fprintf(stdout, "\n------------------------------------------------------\n");
};

void PRINT_TITLE(char* title){
    fprintf(stdout, "\n%s\n", title);
}

void RUN(char* function, char* list_type, int ntests, int list_size){
    PRINT_LINE();
    fprintf(stdout, "%s", RUN_BENCHMARK(function, list_type, 1000, 100));
};






int main(){
    //  Test the `SinglyLinkedList` data structure
    PRINT_TITLE("Testing the Singly Linked List data structure");
    RUN("sll_bubblesort", "sll", 1000, 100);
    RUN("sll_selectionsort", "sll", 1000, 100);
    RUN("sll_insertionsort", "sll", 1000, 100);
    RUN("sll_quicksort", "sll", 1000, 100);
    RUN("sll_mergesort", "sll", 1000, 100);

    PRINT_TITLE("Testing the Singly Linked List data structure");
    RUN("dll_bubblesort", "dll", 1000, 100);
    RUN("dll_selectionsort", "dll", 1000, 100);
    RUN("dll_insertionsort", "dll", 1000, 100);
    RUN("dll_quicksort", "dll", 1000, 100);
    RUN("dll_mergesort", "dll", 1000, 100);




    //  Finish program
    fprintf(stdout, "\n----------------------------------------------\n\n\nEND OF TESTS.\n");

    return 0;
    exit(1);
}