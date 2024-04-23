#   `dstructlib`
The DataStructuresLibrary (`dstructlib`) project is a series of library implementations for data structures and its methods. 

##  Array and list-like structures: `dsl_lists`
The `dsl_lists` module implements several types of list-like structures:
- Singly Linked List (`SinglyLinkedList` or `sll` in the function calls);
- Doubly Linked List (`DoublyLinkedList` or `dll`);
- Circular Linked List (`CircularLinkedList` or `cll`);
- Stack (`Stack` and `stack`);
- Queue (`Queue` and `queue`);

##  List sorting: `dsl_listsort`
The `dsl_listsort` module implements the most common sorting algorithms over the lists defined in `dsl_lists`
- bubblesort
- insertionsort
- selectionsort
- quicksort
- mergesort

---

##  Benchmarking: `dsl_benchmarking_suite` 
The `dsl_benchmarking_suite` implements functions for building a benchmarking suite. Currently, the benchmarking is possible for sorting `SinglyLinkedList`, `DoublyLinkedList` and `CircularLinkedList`. As the project progresses, other algorithms over data structures will be tested.

The tests over the datastructures and sorting algorithms can be visualized by running the `main.c` program.

```shell
gcc -o main main.c dsl_lists.c dsl_listsort.c dsl_benchmarking_suite.c -lm
./main
```

