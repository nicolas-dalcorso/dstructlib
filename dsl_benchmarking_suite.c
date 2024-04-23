/*
    Implements several benchmarking tests and structs to store the results.

    nrdc
    v1.0 2024-03-27
*/

#include "dsl_benchmarking_suite.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "dsl_lists.h"
#include "dsl_listsort.h"

/*
    General use functions and routines
*/
/*
    compare
    Compares two integers.
*/
int compare_int(void* a, void* b) {
    return *(int*)a - *(int*)b;
};

/*
    mean
    Given a array of doubles and its size, returns the mean of all elements
    @param double[] values
    @param int size
    @returns double
*/
double mean(double values[], int size) {
    double accumulator = 0.0;
    for(int i = 0; i < size; i++) {
        accumulator += values[i];
    }
    return accumulator / size;
};


/*
    sum
    Given a array of doubles and its size, returns the sum of all elements
    @param double[] values
    @param int size
    @returns double
*/
double sum(double values[], int size) {
    double accumulator = 0.0;
    for(int i = 0; i < size; i++) {
        accumulator += values[i];
    }
    return accumulator;
};


/*
    arithmetic_mean
    Given a array of doubles and its size, returns the arithmetic mean
    @param double[] values
    @param int size
    @returns double
*/
double arithmetic_mean(double values[], int size){
    double accumulator = 0.0;

    for(int i=0; i<size; i++){
        accumulator += values[i];
    }

    return accumulator / size;
};

/*
    geometric_mean
    Given a array of doubles and its size, returns the geometric mean
    @param double[] values
    @param int size
    @returns double
*/
double geometric_mean(double* values, int size){
    double accumulator = 1.0;

    for(int i=0; i<size; i++){
        accumulator *= values[i];
    }

    return pow(accumulator, 1.0 / size);
};


/*
    harmonic_mean
    Given a array of doubles and its size, returns the harmonic mean
    @param double[] values
    @param int size
    @returns double
*/
double harmonic_mean(double* values, int size){
    double accumulator = 0.0;

    for(int i=0; i<size; i++){
        accumulator += 1.0 / values[i];
    }

    return size / accumulator;
};

/*
    variance
    Given a array of doubles and its size, returns the variance
    @param double[] values
    @param int size
    @returns double
*/
double variance(double values[], int size) {
    double mean_value = mean(values, size);
    double accumulator = 0.0;
    for(int i = 0; i < size; i++) {
        accumulator += pow(values[i] - mean_value, 2);
    }
    return accumulator / size;
};


/*
    standard_deviation
    Given a array of doubles and its size, returns the standard deviation
    @param double[] values
    @param int size
    @returns double
*/
double standard_deviation(double values[], int size) {
    return sqrt(variance(values, size));
};




/*
    sll_get_random_sll
    Function to generate a list of random integers.
    @returns SinglyLinkedList* list
*/
SinglyLinkedList* sll_get_random_sll(int size){
    SinglyLinkedList* list = sll_create();
    for(int i = 0; i < size; i++){
        int* data = (int*)malloc(sizeof(int));
        *data = rand() % 1000;
        sll_insert(list, data);
    }
    return list;
};

/*
    dll_get_random_dll
    Function to generate a list of random integers.
    @returns DoublyLinkedList* list
*/
DoublyLinkedList* dll_get_random_dll(int size){
    DoublyLinkedList* list = dll_create();
    for(int i = 0; i < size; i++){
        int* data = (int*)malloc(sizeof(int));
        *data = rand() % 1000;
        dll_insert(list, data);
    }
    return list;
};

/*
    Methods over the `BenchmarkResult` struct.
*/

/*
    create_benchmark_result
    Creates a new benchmark result with the given parameters.

    Parameters:
    - bt_name: the name of the benchmark test
    - ds_name: the name of the data structure
    - alg_name: the name of the algorithm
    - ds_size: the size of the data structure
    - time: the time taken to run the test

    Returns:
    - a pointer to the new benchmark result
*/
BenchmarkResult* create_benchmark_result(char* bt_name, char* ds_name, char* alg_name, int ds_size, double time) {
    BenchmarkResult* result = (BenchmarkResult*) malloc(sizeof(BenchmarkResult));
    result->bt_name = bt_name;
    result->ds_name = ds_name;
    result->alg_name = alg_name;
    result->ds_size = ds_size;
    result->time = time;
    return result;
};


/*
    get_benchmark_result
    Returns a string representation of the benchmark result.

    Parameters:
    - result: the benchmark result to get the string representation of

    Returns:
    - a string representation of the benchmark result
*/
char* get_benchmark_result(BenchmarkResult* result) {
    char* buffer = (char*) malloc(256 * sizeof(char));
    sprintf(buffer, "Benchmark Test: %s\nData Structure: %s\nAlgorithm: %s\nData Structure Size: %d\nTime: %f ms\n", result->bt_name, result->ds_name, result->alg_name, result->ds_size, result->time);
    return buffer;
};

/*
    free_benchmark_result
    Frees the memory allocated for the benchmark result.

    Parameters:
    - result: the benchmark result to free
*/
void free_benchmark_result(BenchmarkResult* result) {
    free(result);
};


/*
    Benchmarking tests.
*/
/*
    benchmark_sll_bubblesort
    Benchmarks the bubble sort algorithm on a singly linked list.

    Parameters:
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the benchmark result
*/
BenchmarkResult* benchmark_sll_bubblesort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `SinglyLinkedList` structure
    SinglyLinkedList* sll = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    sll = sll_create();
    sll = sll_get_random_sll(1000);

    //  Start the clock
    start = clock();

    //  Run the bubble sort algorithm on a `SinglyLinkedList` structure
    sll_bubblesort(sll, compare);

    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Singly Linked List Bubble Sort", "Singly Linked List", "Bubble Sort", sll_len(sll), (double) (end - start) / CLOCKS_PER_SEC);
};


/*
    benchmark_sll_selectionsort
    Benchmarks the selection sort algorithm on a singly linked list.
    @param int (*compare)(void*, void*)
    @returns BenchmarkResult*
*/
BenchmarkResult* benchmark_sll_selectionsort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `SinglyLinkedList` structure
    SinglyLinkedList* sll = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    sll = sll_create();
    sll = sll_get_random_sll(1000);

    //  Start the clock
    start = clock();

    //  Run the selection sort algorithm on a `SinglyLinkedList` structure
    sll_selectionsort(sll, compare);

    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Singly Linked List Selection Sort", "Singly Linked List", "Selection Sort", sll_len(sll), (double) (end - start) / CLOCKS_PER_SEC);
};

/*
    benchmark_sll_insertionsort
    Benchmarks the insertion sort algorithm on a singly linked list.
    @param int (*compare)(void*, void*)
    @returns BenchmarkResult*
*/
BenchmarkResult* benchmark_sll_insertionsort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `SinglyLinkedList` structure
    SinglyLinkedList* sll = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    sll = sll_create();
    sll = sll_get_random_sll(1000);

    //  Start the clock
    start = clock();

    //  Run the insertion sort algorithm on a `SinglyLinkedList` structure
    sll_insertionsort(sll, compare);

    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Singly Linked List Insertion Sort", "Singly Linked List", "Insertion Sort", sll_len(sll), (double) (end - start) / CLOCKS_PER_SEC);
};

/*
    benchmark_sll_quicksort
    Benchmarks the quick sort algorithm on a singly linked list.
    @param int (*compare)(void*, void*)
    @returns BenchmarkResult*
*/
BenchmarkResult* benchmark_sll_quicksort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `SinglyLinkedList` structure
    SinglyLinkedList* sll = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    sll = sll_create();
    sll = sll_get_random_sll(1000);

    //  Start the clock
    start = clock();

    //  Run the quick sort algorithm on a `SinglyLinkedList` structure
    sll_quicksort(sll, compare);

    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Singly Linked List Quick Sort", "Singly Linked List", "Quick Sort", sll_len(sll), (double) (end - start) / CLOCKS_PER_SEC);
};

/*
    benchmark_sll_mergesort
    Benchmarks the merge sort algorithm on a singly linked list.
    @param int (*compare)(void*, void*)
    @returns BenchmarkResult*
*/
BenchmarkResult* benchmark_sll_mergesort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `SinglyLinkedList` structure
    SinglyLinkedList* sll = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    sll = sll_create();
    sll = sll_get_random_sll(1000);

    //  Start the clock
    start = clock();

    //  Run the merge sort algorithm on a `SinglyLinkedList` structure
    sll_mergesort(sll, compare);

    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Singly Linked List Merge Sort", "Singly Linked List", "Merge Sort", sll_len(sll), (double) (end - start) / CLOCKS_PER_SEC);
};

/*
    benchmark_dll_bubblesort
    Benchmarks the heap sort algorithm on a doubly linked list.
    @param int (*compare)(void*, void*)
    @returns BenchmarkResult*
*/
BenchmarkResult* benchmark_dll_bubblesort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `DoublyLinkedList` structure
    DoublyLinkedList* dll = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    dll = dll_create();
    dll = dll_get_random_dll(1000);

    //  Start the clock
    start = clock();

    //  Run the bubble sort algorithm on a `DoublyLinkedList` structure
    dll_bubblesort(dll, compare);


    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Doubly Linked List Bubble Sort", "Doubly Linked List", "Bubble Sort", dll_len(dll), (double) (end - start) / CLOCKS_PER_SEC);
};

/*
    benchmark_dll_selectionsort
    Benchmarks the selection sort algorithm on a doubly linked list.
    @param int (*compare)(void*, void*)
    @returns BenchmarkResult*
*/
BenchmarkResult* benchmark_dll_selectionsort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `DoublyLinkedList` structure
    DoublyLinkedList* dll = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    dll = dll_create();
    dll = dll_get_random_dll(1000);

    //  Start the clock
    start = clock();

    //  Run the selection sort algorithm on a `DoublyLinkedList` structure
    dll_selectionsort(dll, compare);

    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Doubly Linked List Selection Sort", "Doubly Linked List", "Selection Sort", dll_len(dll), (double) (end - start) / CLOCKS_PER_SEC);
};

/*
    benchmark_dll_insertionsort
    Benchmarks the insertion sort algorithm on a doubly linked list.
    @param int (*compare)(void*, void*)
    @returns BenchmarkResult*
*/
BenchmarkResult* benchmark_dll_insertionsort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `DoublyLinkedList` structure
    DoublyLinkedList* dll = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    dll = dll_create();
    dll = dll_get_random_dll(1000);

    //  Start the clock
    start = clock();

    //  Run the insertion sort algorithm on a `DoublyLinkedList` structure
    dll_insertionsort(dll, compare);

    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Doubly Linked List Insertion Sort", "Doubly Linked List", "Insertion Sort", dll_len(dll), (double) (end - start) / CLOCKS_PER_SEC);
};

/*
    benchmark_dll_quicksort
    Benchmarks the quick sort algorithm on a doubly linked list.
    @param int (*compare)(void*, void*)
    @returns BenchmarkResult*
*/
BenchmarkResult* benchmark_dll_quicksort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `DoublyLinkedList` structure
    DoublyLinkedList* dll = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    dll = dll_create();
    dll = dll_get_random_dll(1000);

    //  Start the clock
    start = clock();

    //  Run the quick sort algorithm on a `DoublyLinkedList` structure
    dll_quicksort(dll, compare);

    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Doubly Linked List Quick Sort", "Doubly Linked List", "Quick Sort", dll_len(dll), (double) (end - start) / CLOCKS_PER_SEC);
};

/*
    benchmark_dll_mergesort
    Benchmarks the merge sort algorithm on a doubly linked list.
    @param int (*compare)(void*, void*)
    @returns BenchmarkResult*
*/
BenchmarkResult* benchmark_dll_mergesort(int (*compare)(void*, void*)) {
    //  Set time variables
    clock_t start, end;

    //  Create a random `DoublyLinkedList` structure
    DoublyLinkedList* dll = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    dll = dll_create();
    dll = dll_get_random_dll(1000);

    //  Start the clock
    start = clock();

    //  Run the merge sort algorithm on a `DoublyLinkedList` structure
    dll_mergesort(dll, compare);

    //  Stop the clock
    end = clock();

    //  Return the benchmark result
    return create_benchmark_result("Doubly Linked List Merge Sort", "Doubly Linked List", "Merge Sort", dll_len(dll), (double) (end - start) / CLOCKS_PER_SEC);
};








/*
    Tests
*/

/*
    run_benchmark_sll_bubblesort
    Runs the benchmark test for the bubble sort algorithm on a singly linked list.

    Parameters:
    - ntests: the number of tests to run
    - list_size: the size of the list to sort

    Returns:
    - a string representation of the benchmark results
*/
char* run_benchmark_sll_bubblesort(int ntests, int list_size){
    //  Create an array to store the results
    BenchmarkResult** results = (BenchmarkResult**) malloc(ntests * sizeof(BenchmarkResult*));

    //  Run the tests
    for(int i = 0; i < ntests; i++){
        results[i] = benchmark_sll_bubblesort(compare_int);
    }

    //  Statistical measures

    //  Calculate the mean time
    double times[ntests];
    double sum;
    for(int i = 0; i < ntests; i++){
        times[i] = results[i]->time;
        sum += times[i];
    }
    double mean_time = arithmetic_mean(times, ntests);

    //  Geometric mean
    double geo_mean = geometric_mean(times, ntests);

    //  Harmonic mean
    double harm_mean = harmonic_mean(times, ntests);

    //  Variance
    double var = variance(times, ntests);

    //  Standard deviation
    double std_dev = standard_deviation(times, ntests);


    //  Create a buffer to store the results
    char* buffer = (char*) malloc(1024 * sizeof(char));
    sprintf(buffer, "Benchmark Test: Singly Linked List Selection Sort\nNumber of Tests: %d\nList Size: %d\nTotal time: %f s\nMean Time: %f ms\nGeometric Mean: %f ms\nHarmonic Mean: %f ms\nVariance: %f ms, Standard Deviation: %fms", ntests, list_size, sum, mean_time, geo_mean, harm_mean, var, std_dev);

    //  Free the memory allocated for the results
    for(int i = 0; i < ntests; i++){
        free_benchmark_result(results[i]);
    }

    free(results);

    return buffer;
};

/*
    run_benchmark_sll_selectionsort
    Runs the benchmark test for the selection sort algorithm on a singly linked list.
    @param int ntests
    @param int list_size
    @returns char*
*/
char* run_benchmark_sll_selectionsort(int ntests, int list_size){
    //  Create an array to store the results
    BenchmarkResult** results = (BenchmarkResult**) malloc(ntests * sizeof(BenchmarkResult*));

    //  Run the tests
    for(int i = 0; i < ntests; i++){
        results[i] = benchmark_sll_selectionsort(compare_int);
    }

    //  Statistical measures

    //  Calculate the mean time
    double times[ntests];
    double sum;
    for(int i = 0; i < ntests; i++){
        times[i] = results[i]->time;
        sum += times[i];
    }
    double mean_time = arithmetic_mean(times, ntests);

    //  Geometric mean
    double geo_mean = geometric_mean(times, ntests);

    //  Harmonic mean
    double harm_mean = harmonic_mean(times, ntests);

    //  Variance
    double var = variance(times, ntests);

    //  Standard deviation
    double std_dev = standard_deviation(times, ntests);

    //  Create a buffer to store the results
    char* buffer = (char*) malloc(1024 * sizeof(char));

    //  Format the buffer
    sprintf(buffer, "Benchmark Test: Singly Linked List Selection Sort\nNumber of Tests: %d\nList Size: %d\nTotal time: %f s\nMean Time: %f ms\nGeometric Mean: %f ms\nHarmonic Mean: %f ms\nVariance: %f ms, Standard Deviation: %fms", ntests, list_size, sum, mean_time, geo_mean, harm_mean, var, std_dev);

    //  Free the memory allocated for the results
    for(int i = 0; i < ntests; i++){
        free_benchmark_result(results[i]);
    }

    free(results);

    return buffer;
};




//  More abstract methods?

char* RUN_BENCHMARK(char* function, char* list_type, int ntests, int list_size){
    //  Create an array to store the results
    BenchmarkResult** results = (BenchmarkResult**) malloc(ntests * sizeof(BenchmarkResult*));

    if(!strcmp("sll", list_type)){
        if(!strcmp("sll_bubblesort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_sll_bubblesort(compare_int);
            }
        } else if(!strcmp("sll_selectionsort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_sll_selectionsort(compare_int);
            }
        } else if(!strcmp("sll_insertionsort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_sll_insertionsort(compare_int);
            }
        }   else if(!strcmp("sll_quicksort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_sll_quicksort(compare_int);
            }
        }   else if(!strcmp("sll_mergesort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_sll_mergesort(compare_int);
            }
        } else {
                return "Invalid function";
        }
    }   else if(!strcmp("dll", list_type)){
        if(!strcmp("dll_bubblesort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_dll_bubblesort(compare_int);
            }
        } else if(!strcmp("dll_selectionsort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_dll_selectionsort(compare_int);
            }
        } else if(!strcmp("dll_insertionsort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_dll_insertionsort(compare_int);
            }
        }   else if(!strcmp("dll_quicksort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_dll_quicksort(compare_int);
            }
        }   else if(!strcmp("dll_mergesort", function)){
            for(int i = 0; i < ntests; i++){
                results[i] = benchmark_dll_mergesort(compare_int);
            }
        } else {
                return "Invalid function";
        }
    } else {
        return "Invalid list type";
    };

    //  Statistical measures

    //  Calculate the mean time
    double times[ntests];
    double sum;
    for(int i = 0; i < ntests; i++){
        times[i] = results[i]->time;
        sum += times[i];
    }
    double mean_time = arithmetic_mean(times, ntests);

    //  Geometric mean
    double geo_mean = geometric_mean(times, ntests);

    //  Harmonic mean
    double harm_mean = harmonic_mean(times, ntests);

    //  Variance
    double var = variance(times, ntests);

    //  Standard deviation
    double std_dev = standard_deviation(times, ntests);

    //  Create a buffer to store the results
    char* buffer = (char*) malloc(1024 * sizeof(char));

    //  Format the buffer
    sprintf(buffer, "Benchmark Test: %s %s\nNumber of Tests: %d\nList Size: %d\nTotal time: %f s\nMean Time: %f ms\nGeometric Mean: %f ms\nHarmonic Mean: %f ms\nVariance: %f ms, Standard Deviation: %fms", list_type, function, ntests, list_size, sum, mean_time, geo_mean, harm_mean, var, std_dev);

    //  Free the memory allocated for the results
    for(int i = 0; i < ntests; i++){
        free_benchmark_result(results[i]);
    }

    free(results);

    return buffer;
};