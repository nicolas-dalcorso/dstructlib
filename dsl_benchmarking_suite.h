#ifndef DSL_BENCHMARKING_SUITE_H
#define DSL_BENCHMARKING_SUITE_H

/*
    Interface for the functions and structs necessary to benchmarking the datastructures and algorithms implemented in the DSL.


    nrdc
    v1.0 2024-03-27
*/

#include <time.h>
#include "dsl_lists.h"

/*
    BenchmarkResult
    Struct to store the results of a benchmarking test.
*/
typedef struct BenchmarkResult {
    char* bt_name;              // The name of the benchmark test
    char* ds_name;              // The name of the data structure
    char* alg_name;             // The name of the algorithm
    int ds_size;                // The size of the data structure
    double time;                // The time taken to run the test
} BenchmarkResult;

/*
    General use functions and routines
*/

/*
    compare_int
    Compares two integers.

    Parameters:
    - a: the first integer
    - b: the second integer

    Returns:
    - true if a is less than b, false otherwise
*/
int compare_int(void* a, void* b);

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
BenchmarkResult* create_benchmark_result(char* bt_name, char* ds_name, char* alg_name, int ds_size, double time);

/*
    free_benchmark_result
    Frees the memory allocated for a benchmark result.

    Parameters:
    - result: the benchmark result to free
*/
void free_benchmark_result(BenchmarkResult* result);

/*
    get_benchmark_result
    Returns a string representation of the benchmark result.

    Parameters:
    - result: the benchmark result to get the string representation of

    Returns:
    - a string representation of the benchmark result
*/
char* get_benchmark_result(BenchmarkResult* result);


/*
    Benchmarking tests
*/
BenchmarkResult* benchmark_sll_bubblesort(int (*compare)(void*, void*));
#endif // DSL_BENCHMARKING_SUIT_H

char* run_benchmark_sll_bubblesort(int ntests, int list_size);

char* RUN_BENCHMARK(char* function, char* list_type, int ntests, int list_size);