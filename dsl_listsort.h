#ifndef DSL_LISTSORT_H
#define DSL_LISTSORT_H

/*
    Interface for the implementation of sorting algorithms over the list data structures defined in `dsl_lists.h`

    Currently, the following sorting algorithms are implemented:
    - Bubble Sort
    - Selection Sort
    - Insertion Sort
    - Merge Sort

    For all data structures:
    - Singly Linked List
    - Doubly Linked List
    - Circular Linked List
    - Queue?
    - Stack?

    nrdc
    v1.0 2024-03-27
*/

#include "dsl_lists.h"

/*
    sll_bubblesort
    Sorts a singly linked list using the bubble sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the singly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted singly linked list
*/
SinglyLinkedList* sll_bubblesort(SinglyLinkedList* list, int (*compare)(void*, void*));

/*
    sll_selectionsort
    Sorts a singly linked list using the selection sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the singly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted singly linked list

*/
SinglyLinkedList* sll_selectionsort(SinglyLinkedList* list, int (*compare)(void*, void*));

/*
    sll_insertionsort
    Sorts a singly linked list using the insertion sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the singly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted singly linked list
*/
SinglyLinkedList* sll_insertionsort(SinglyLinkedList* list, int (*compare)(void*, void*));

/*
    sll_mergesort
    Sorts a singly linked list using the merge sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the singly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted singly linked list
*/
SinglyLinkedList* sll_mergesort(SinglyLinkedList* list, int (*compare)(void*, void*));

/*
    sll_quicksort
    Sorts a singly linked list using the quick sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the singly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted singly linked list
*/
SinglyLinkedList* sll_quicksort(SinglyLinkedList* list, int (*compare)(void*, void*));

/*
    dll_bubblesort
    Sorts a doubly linked list using the bubble sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
DoublyLinkedList* dll_bubblesort(DoublyLinkedList* list, int (*compare)(void*, void*));

/*
    dll_selectionsort
    Sorts a doubly linked list using the bubble sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
DoublyLinkedList* dll_selectionsort(DoublyLinkedList* list, int (*compare)(void*, void*));

/*
    dll_insertionsort
    Sorts a doubly linked list using the bubble sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
DoublyLinkedList* dll_insertionsort(DoublyLinkedList* list, int (*compare)(void*, void*));

/*
    dll_mergesort
    Sorts a doubly linked list using the bubble sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
DoublyLinkedList* dll_mergesort(DoublyLinkedList* list, int (*compare)(void*, void*));

/*
    dll_quicksort
    Sorts a doubly linked list using the bubble sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
DoublyLinkedList* dll_quicksort(DoublyLinkedList* list, int (*compare)(void*, void*));

//  `CircularLinkedList` sorting algorithms


/*
    cll_bubblesort
    Sorts a circular linked list using the bubble sort algorithm.

    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
CircularLinkedList* cll_bubblesort(CircularLinkedList* list, int (*compare)(void*, void*));

/*
    cll_selectionsort
    Sorts a circular linked list using the selection sort algorithm.

    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
CircularLinkedList* cll_selectionsort(CircularLinkedList* list, int (*compare)(void*, void*));

/*
    cll_insertionsort
    Sorts a circular linked list using the insertion sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element
    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
CircularLinkedList* cll_insertionsort(CircularLinkedList* list, int (*compare)(void*, void*));

/*
    cll_mergesort
    Sorts a circular linked list using the merge sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element

    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
CircularLinkedList* cll_mergesort(CircularLinkedList* list, int (*compare)(void*, void*));

/*
    cll_quicksort
    Sorts a circular linked list using the quick sort algorithm.
    The compare function is used to compare two elements in the list.
    The compare function should return:
    - 0 if the two elements are equal
    - -1 if the first element is less than the second element
    - 1 if the first element is greater than the second element

    The compare function should have the following signature:
    int compare(void* a, void* b);

    Parameters:
    - list: the doubly linked list to sort
    - compare: the comparison function to use to compare two elements in the list

    Returns:
    - a pointer to the sorted doubly linked list
*/
CircularLinkedList* cll_quicksort(CircularLinkedList* list, int (*compare)(void*, void*));


// ?

Queue* queue_bubblesort(Queue* queue, int (*compare)(void*, void*));
Queue* queue_selectionsort(Queue* queue, int (*compare)(void*, void*));
Queue* queue_insertionsort(Queue* queue, int (*compare)(void*, void*));
Queue* queue_mergesort(Queue* queue, int (*compare)(void*, void*));
Queue* queue_quicksort(Queue* queue, int (*compare)(void*, void*));

Stack* stack_bubblesort(Stack* stack, int (*compare)(void*, void*));
Stack* stack_selectionsort(Stack* stack, int (*compare)(void*, void*));
Stack* stack_insertionsort(Stack* stack, int (*compare)(void*, void*));
Stack* stack_mergesort(Stack* stack, int (*compare)(void*, void*));
Stack* stack_quicksort(Stack* stack, int (*compare)(void*, void*));


#endif // DSL_LISTSORT_H