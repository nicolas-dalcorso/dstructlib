#ifndef DSL_LISTS_H
#define DSL_LISTS_H
/*
    Interface for the implementation of list data structures
    Currently, the following list data structures are implemented:
    - Singly Linked List
    - Doubly Linked List
    - Circular Linked List
    - Stack
    - Queue


    nrdc
    v1.0 2024-03-27
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    1. Singly linked list
    A `SinglyLinkedList` is a list of elements, where each element has a reference to the next element in the list.
*/

/*
    Node of a singly linked list
    - `data` is a pointer to the data stored in the node
    - `next` is a pointer to the next node in the list
*/
typedef struct SinglyLinkedListNode {
    void *data;
    struct SinglyLinkedListNode *next;
} SLLNode;

/*
    Singly linked list
    - `head` is a pointer to the first node in the list
    - `size` is the number of nodes in the list
*/
typedef struct SinglyLinkedList {
    SLLNode *head;
    size_t size;
} SinglyLinkedList;

//  Singly Linked List methods

/*
    sllnode_create
    Create a new singly linked list node
    @param `data` is a pointer to the data to store in the node
    @returns pointer to the new singly linked list node
*/
SLLNode *sllnode_create(void *data);

/*
    sllnode_free
    Free a node from a singly linked list
    @param  SLLNode*    Pointer to the node to be freed
    @return void
*/
void sllnode_free(SLLNode* node);

/*
    sll_get_next
    Get the next node in a singly linked list
    @param  SLLNode*    Pointer to the current node
    @return SLLNode*    Pointer to the next node
*/
SLLNode* sll_get_next(SLLNode* node);

/*  
    sll_create
    Create a new singly linked list
    @returns pointer to the new singly linked list
*/
SinglyLinkedList *sll_create();

/*
    sll_destroy
    Destroy a singly linked list
    @param `list` is a pointer to the singly linked list to destroy
*/
void sll_destroy(SinglyLinkedList *sll);

/*
    sll_insert
    Insert a new node at the beginning of a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be stored in the new node
    @return bool                true if the operation was successful, false otherwise
*/
bool sll_insert(SinglyLinkedList* sll, void* data);

/*
    sll_append
    Append a new node at the end of a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be stored in the new node
    @return bool                true if the operation was successful, false otherwise
*/
bool sll_append(SinglyLinkedList* sll, void* data);

/*
    sll_remove
    Remove a node from a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be removed
    @return bool                true if the operation was successful, false otherwise
*/
bool sll_remove(SinglyLinkedList* sll, void* data);

/*
    sll_search
    Search for a node in a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be searched
    @return SLLNode*            Pointer to the node if found, NULL otherwise
*/
SLLNode* sll_search(SinglyLinkedList* sll, void* data);

/*
    sll_print
    Print the contents of a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @return void
*/
void sll_print(SinglyLinkedList* sll);

/*
    sll_len
    Get the number of nodes in a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @return size_t              Number of nodes in the list
*/
int sll_len(SinglyLinkedList* sll);



/*
    2. Doubly linked list
    A `DoublyLinkedList` is a list of elements, where each element has a reference to the next and previous elements in the list.

    The `DoublyLinkedList` structure contains a pointer to the first node in the list (`head`), a pointer to the last node in the list (`tail`), and the number of nodes in the list (`size`).

    The `DLLNode` structure contains a pointer to the data stored in the node (`data`), a pointer to the next node in the list (`next`), and a pointer to the previous node in the list (`prev`).

    The following functions are provided for working with doubly linked lists:
    - `dll_create`: Create a new doubly linked list
    - `dll_destroy`: Destroy a doubly linked list
    - `dll_insert`: Insert a new node at the beginning of a doubly linked list
    - `dll_append`: Append a new node at the end of a doubly linked list
    - `dll_remove`: Remove a node from a doubly linked list
    - `dll_search`: Search for a node in a doubly linked list
    - `dll_print`: Print the contents of a doubly linked list
    - `dll_len`: Get the number of nodes in a doubly linked list

    Note that, unlike the implementation for singly linked lists, the `dll_insert` and `dll_append` functions take a pointer to the data to be stored in the new node, rather than the data itself. This allows the functions to work with data of any type. Also, a `tail` pointer to the last node in the list is maintained to allow for efficient appending of new nodes.
*/

/*
    Node of a doubly linked list
    - `data` is a pointer to the data stored in the node
    - `next` is a pointer to the next node in the list
    - `prev` is a pointer to the previous node in the list
*/
typedef struct DoublyLinkedListNode {
    void *data;
    struct DoublyLinkedListNode *next;
    struct DoublyLinkedListNode *prev;
} DLLNode;

/*
    Doubly linked list
    - `head` is a pointer to the first node in the list
    - `tail` is a pointer to the last node in the list
    - `size` is the number of nodes in the list
*/
typedef struct DoublyLinkedList {
    DLLNode *head;
    DLLNode *tail;
    size_t size;
} DoublyLinkedList;

//  Doubly Linked List methods

/*
    dllnode_create
    Create a new doubly linked list node
    @param `data` is a pointer to the data to store in the node
    @returns pointer to the new doubly linked list node
*/
DLLNode* dllnode_create(void *data);

/*
    dllnode_free
    Free a node from a doubly linked list
    @param  DLLNode*    Pointer to the node to be freed
    @return void
*/
void dllnode_free(DLLNode* node);

/*
    dll_create
    Create a new doubly linked list
    @param  void
    @return DoublyLinkedList*   Pointer to the new list
*/
DoublyLinkedList* dll_create(void);

/*
    dll_destroy
    Destroy a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @return void
*/
void dll_destroy(DoublyLinkedList* dll);

/*
    dll_insert
    Insert a new node at the beginning of a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be stored in the new node
    @return bool                true if the operation was successful, false otherwise
*/
bool dll_insert(DoublyLinkedList* dll, void* data);

/*
    dll_append
    Append a new node at the end of a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be stored in the new node
    @return bool                true if the operation was successful, false otherwise
*/
bool dll_append(DoublyLinkedList* dll, void* data);

/*
    dll_remove
    Remove a node from a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be removed
    @return bool                true if the operation was successful, false otherwise
*/
bool dll_remove(DoublyLinkedList* dll, void* data); 

/*
    dll_search
    Search for a node in a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be searched
    @return DLLNode*            Pointer to the node if found, NULL otherwise
*/
DLLNode* dll_search(DoublyLinkedList* dll, void* data);

/*
    dll_print
    Print the contents of a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @return void
*/
void dll_print(DoublyLinkedList* dll);

/*
    dll_len
    Get the number of nodes in a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @return size_t              Number of nodes in the list

*/
size_t dll_len(DoublyLinkedList* dll);



/*
    3.  Circular linked list
    A `CircularLinkedList` is a list of elements, where each element has a reference to the next element in the list. The last element in the list points back to the first element, forming a circular structure.

    The `CircularLinkedList` structure contains a pointer to the first node in the list (`head`) and the number of nodes in the list (`size`).

    The `CLLNode` structure contains a pointer to the data stored in the node (`data`) and a pointer to the next node in the list (`next`).

    The following functions are provided for working with circular linked lists:
    - `cll_create`: Create a new circular linked list
    - `cll_destroy`: Destroy a circular linked list
    - `cll_insert`: Insert a new node at the beginning of a circular linked list
    - `cll_append`: Append a new node at the end of a circular linked list
    - `cll_remove`: Remove a node from a circular linked list
    - `cll_search`: Search for a node in a circular linked list
    - `cll_print`: Print the contents of a circular linked list
    - `cll_len`: Get the number of nodes in a circular linked list
*/

/*
    Node of a circular linked list
    - `data` is a pointer to the data stored in the node
    - `next` is a pointer to the next node in the list
*/
typedef struct CircularLinkedListNode {
    void *data;
    struct CircularLinkedListNode *next;
} CLLNode;

/*
    Circular linked list
    - `head` is a pointer to the first node in the list
    - `size` is the number of nodes in the list
*/
typedef struct CircularLinkedList {
    CLLNode *head;
    size_t size;
} CircularLinkedList;

//  Circular Linked List methods

/*
    cllnode_create
    Create a new circular linked list node
    @param `data` is a pointer to the data to store in the node
    @returns pointer to the new circular linked list node
*/
CLLNode* cllnode_create(void *data);

/*
    cllnode_free
    Free a node from a circular linked list
    @param  CLLNode*    Pointer to the node to be freed
    @return void
*/
void cllnode_free(CLLNode* node);

/*
    cll_create
    Create a new circular linked list
    @param  void
    @return CircularLinkedList*   Pointer to the new list
*/
CircularLinkedList* cll_create(void);

/*
    cll_destroy
    Destroy a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @return void
*/
void cll_destroy(CircularLinkedList* cll);

/*
    cll_insert
    Insert a new node at the beginning of a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @param  void*                 Pointer to the data to be stored in the new node
    @return bool                  true if the operation was successful, false otherwise
*/
bool cll_insert(CircularLinkedList* cll, void* data);

/*
    cll_append
    Append a new node at the end of a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @param  void*                 Pointer to the data to be stored in the new node
    @return bool                  true if the operation was successful, false otherwise
*/
bool cll_append(CircularLinkedList* cll, void* data);

/*
    cll_remove
    Remove a node from a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @param  void*                 Pointer to the data to be removed
    @return bool                  true if the operation was successful, false otherwise
*/
bool cll_remove(CircularLinkedList* cll, void* data);

/*
    cll_search
    Search for a node in a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @param  void*                 Pointer to the data to be searched
    @return CLLNode*              Pointer to the node if found, NULL otherwise
*/
CLLNode* cll_search(CircularLinkedList* cll, void* data);

/*
    cll_print
    Print the contents of a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @return void
*/
void cll_print(CircularLinkedList* cll);

/*
    cll_len
    Get the number of nodes in a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @return size_t                Number of nodes in the list
*/
size_t cll_len(CircularLinkedList* cll);


/*
    4.  Stack
    A `Stack` is a last-in, first-out (LIFO) data structure that supports two main operations: push (add an element to the top of the stack) and pop (remove the top element from the stack).

    The `Stack` structure contains a pointer to the top element of the stack (`top`) and the number of elements in the stack (`size`).

    The current version of the `Stack` data structure is implemented using de `DoublyLinkedListNode` as its node structure.

    The current `Stack` methods are:
    - `stack_create`: Create a new stack
    - `stack_destroy`: Destroy a stack
    - `stack_push`: Push a new element onto the stack
    - `stack_pop`: Pop the top element from the stack
    - `stack_top`: Get the top element of the stack
    - `stack_size`: Get the number of elements in the stack
*/

/*
    Stack
    - `top` is a pointer to the top element of the stack
    - `size` is the number of elements in the stack
*/
typedef struct Stack {
    DLLNode *top;
    size_t size;
} Stack;


//  Stack methods

/*
    stack_create
    Create a new stack
    @param  void
    @return Stack*   Pointer to the new stack
*/
Stack* stack_create(void);

/*
    stack_destroy
    Destroy a stack
    @param  Stack*  Pointer to the stack
    @return void
*/
void stack_destroy(Stack* stack);

/*
    stack_push
    Push a new element onto the stack
    @param  Stack*  Pointer to the stack
    @param  void*   Pointer to the data to be stored in the new element
    @return bool    true if the operation was successful, false otherwise
*/
bool stack_push(Stack* stack, void* data);

/*
    stack_pop
    Pop the top element from the stack
    @param  Stack*  Pointer to the stack
    @return void*   Pointer to the data of the top element
*/
void* stack_pop(Stack* stack);

/*
    stack_top
    Get the top element of the stack
    @param  Stack*  Pointer to the stack
    @return void*   Pointer to the data of the top element
*/
void* stack_top(Stack* stack);

/*
    stack_size
    Get the number of elements in the stack
    @param  Stack*  Pointer to the stack
    @return size_t  Number of elements in the stack
*/
size_t stack_size(Stack* stack);



/*
    5.  Queue
    A `Queue` is a first-in, first-out (FIFO) data structure that supports two main operations: enqueue (add an element to the back of the queue) and dequeue (remove the front element from the queue).

    The `Queue` structure contains a pointer to the front element of the queue (`front`), a pointer to the back element of the queue (`back`), and the number of elements in the queue (`size`).

    The current version of the `Queue` data structure is implemented using de `DoublyLinkedListNode` as its node structure.

    The current `Queue` implemented methods are:
    -   `queue_create`: Create a new queue
    -   `queue_destroy`: Destroy a queue
    -   `queue_enqueue`: Enqueue a new element into the queue
    -   `queue_dequeue`: Dequeue the front element from the queue
    -   `queue_front`: Get the front element of the queue
    -   `queue_back`: Get the back element of the queue
    -   `queue_size`: Get the number of elements in the queue
*/


/*
    Queue
    - `front` is a pointer to the front element of the queue
    - `back` is a pointer to the back element of the queue
    - `size` is the number of elements in the queue
*/
typedef struct Queue {
    DLLNode *front;
    DLLNode *back;
    size_t size;
} Queue;

//  Queue methods

/*
    queue_create
    Create a new queue
    @param  void
    @return Queue*   Pointer to the new queue
*/
Queue* queue_create(void);

/*
    queue_destroy
    Destroy a queue
    @param  Queue*  Pointer to the queue
    @return void
*/
void queue_destroy(Queue* queue);

/*
    queue_enqueue
    Enqueue a new element into the queue
    @param  Queue*  Pointer to the queue
    @param  void*   Pointer to the data to be stored in the new element
    @return bool    true if the operation was successful, false otherwise
*/
bool queue_enqueue(Queue* queue, void* data);

/*
    queue_dequeue
    Dequeue the front element from the queue
    @param  Queue*  Pointer to the queue
    @return void*   Pointer to the data of the front element
*/
void* queue_dequeue(Queue* queue);

/*
    queue_front
    Get the front element of the queue
    @param  Queue*  Pointer to the queue
    @return void*   Pointer to the data of the front element
*/
void* queue_front(Queue* queue);

/*
    queue_back
    Get the back element of the queue
    @param  Queue*  Pointer to the queue
    @return void*   Pointer to the data of the back element
*/
void* queue_back(Queue* queue);

/*
    queue_size
    Get the number of elements in the queue
    @param  Queue*  Pointer to the queue
    @return size_t  Number of elements in the queue
*/
size_t queue_size(Queue* queue);









/*
    6. Conversion functions
    The conversion functions allow you to convert between different list data structures.
*/

/*
    sll_to_dll
    Convert a singly linked list to a doubly linked list
    @param `sll` is a pointer to the singly linked list to convert
    @returns pointer to the new doubly linked list
*/
DoublyLinkedList* sll_to_dll(SinglyLinkedList* sll);

/*
    dll_to_sll
    Convert a doubly linked list to a singly linked list. The conversion is done by traversing the doubly linked list from the head to the tail and creating a new singly linked list with the same elements.
    It is useful to understand this function as a 'forgetful functor' that forgets the previous node relationship.
    @param `dll` is a pointer to the doubly linked list to convert
    @returns pointer to the new singly linked list
*/
SinglyLinkedList* dll_to_sll(DoublyLinkedList* dll);

#endif // DSL_LISTS_H