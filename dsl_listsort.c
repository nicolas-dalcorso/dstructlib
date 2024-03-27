/*
    Implementation of sorting functions for the list data structures defined in `dsl_lists.h`.
    Currently, the following list sorting algorithms are implemented:
    - Bubble Sort
    - Selection Sort
    - Insertion Sort
    - Merge Sort
    - Quick Sort

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
    Function to sort a `SinglyLinkedList` (sll) using the bubble sort algorithm.
    The compare function is used to compare two elements in the list. It must be provided by the user.

    @param SinglyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns SinglyLinkedList* list
*/
SinglyLinkedList* sll_bubblesort(SinglyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    int swapped;
    SLLNode* temp;
    SLLNode* end = NULL;

    do{
        swapped = 0;
        temp = list->head;

        while(temp->next != end){
            if(compare(temp->data, temp->next->data) > 0){
                void* t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
                swapped = 1;
            }
            temp = temp->next;
        }
        end = temp;
    }while(swapped);

    return list;
};

/*
    sll_selectionsort
    Function to sort a `SinglyLinkedList` (sll) using the selection sort algorithm.
    The compare function is used to compare two elements in the list. It must be provided by the user.

    @param SinglyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns SinglyLinkedList* list
*/
SinglyLinkedList* sll_selectionsort(SinglyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    SLLNode* temp = list->head;
    SLLNode* min;

    while(temp->next != NULL){
        min = temp;
        SLLNode* r = temp->next;

        while(r != NULL){
            if(compare(r->data, min->data) < 0){
                min = r;
            }
            r = r->next;
        }

        void* t = min->data;
        min->data = temp->data;
        temp->data = t;

        temp = temp->next;
    }

    return list;
};

/*
    sll_insertionsort
    Function to sort a `SinglyLinkedList` (sll) using the insertion sort algorithm.
    The compare function is used to compare two elements in the list. It must be provided by the user.

    @param SinglyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns SinglyLinkedList* list
*/
SinglyLinkedList* sll_insertionsort(SinglyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    SLLNode* temp = list->head;
    SLLNode* r;

    while(temp != NULL){
        r = temp->next;

        while(r != NULL){
            if(compare(temp->data, r->data) > 0){
                void* t = temp->data;
                temp->data = r->data;
                r->data = t;
            }
            r = r->next;
        }

        temp = temp->next;
    }

    return list;
};

/*
    sll_mergesort
    Function to sort a `SinglyLinkedList` (sll) using the merge sort algorithm.
    The compare function is used to compare two elements in the list. It must be provided by the user.

    @param SinglyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns SinglyLinkedList* list
*/
SinglyLinkedList* sll_mergesort(SinglyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    SinglyLinkedList* left = sll_create();
    SinglyLinkedList* right = sll_create();
    SinglyLinkedList* result = sll_create();

    int size = sll_len(list);
    int mid = size / 2;

    SLLNode* temp = list->head;
    for(int i = 0; i < mid; i++){
        sll_insert(left, temp->data);
        temp = temp->next;
    }

    for(int i = mid; i < size; i++){
        sll_insert(right, temp->data);
        temp = temp->next;
    }

    left = sll_mergesort(left, compare);
    right = sll_mergesort(right, compare);

    SLLNode* l = left->head;
    SLLNode* r = right->head;

    while(l != NULL && r != NULL){
        if(compare(l->data, r->data) < 0){
            sll_insert(result, l->data);
            l = l->next;
        }else{
            sll_insert(result, r->data);
            r = r->next;
        }
    }

    while(l != NULL){
        sll_insert(result, l->data);
        l = l->next;
    }

    while(r != NULL){
        sll_insert(result, r->data);
        r = r->next;
    }

    return result;
};

/*
    sll_quicksort
    Function to sort a `SinglyLinkedList` (sll) using the quick sort algorithm.
    The compare function is used to compare two elements in the list. It must be provided by the user.

    @param SinglyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns SinglyLinkedList* list
*/
SinglyLinkedList* sll_quicksort(SinglyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    SinglyLinkedList* left = sll_create();
    SinglyLinkedList* right = sll_create();
    SinglyLinkedList* result = sll_create();

    SLLNode* pivot = list->head;
    SLLNode* temp = list->head->next;

    while(temp != NULL){
        if(compare(temp->data, pivot->data) < 0){
            sll_insert(left, temp->data);
        }else{
            sll_insert(right, temp->data);
        }
        temp = temp->next;
    }

    left = sll_quicksort(left, compare);
    right = sll_quicksort(right, compare);

    SLLNode* l = left->head;
    SLLNode* r = right->head;

    while(l != NULL){
        sll_insert(result, l->data);
        l = l->next;
    }

    sll_insert(result, pivot->data);

    while(r != NULL){
        sll_insert(result, r->data);
        r = r->next;
    }

    return result;
};


/*
    `DoublyLinkedList` sorting functions
*/

/*
    dll_bubblesort
    Function to sort a `DoublyLinkedList` (dll) using the bubble sort algorithm.
    @param DoublyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns DoublyLinkedList* list
*/
DoublyLinkedList* dll_bubblesort(DoublyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    DLLNode* current = list->head;
    DLLNode* next = current->next;

    while(current != NULL){
        while(next != NULL){
            if(compare(current->data, next->data) > 0){
                void* temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
        if(current != NULL) {
            next = current->next;
        }
    }

    return list;
};

/*
    dll_selectionsort
    Function to sort a `DoublyLinkedList` (dll) using the selection sort algorithm.
    @param DoublyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns DoublyLinkedList* list
*/
DoublyLinkedList* dll_selectionsort(DoublyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    DLLNode* current = list->head;
    DLLNode* min;

    while(current->next != NULL){
        min = current;
        DLLNode* r = current->next;

        while(r != NULL){
            if(compare(r->data, min->data) < 0){
                min = r;
            }
            r = r->next;
        }

        void* temp = min->data;
        min->data = current->data;
        current->data = temp;

        current = current->next;
    }

    return list;
};

/*
    dll_insertionsort
    Function to sort a `DoublyLinkedList` (dll) using the insertion sort algorithm.
    @param DoublyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns DoublyLinkedList* list
*/
DoublyLinkedList* dll_insertionsort(DoublyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    DLLNode* current = list->head;
    DLLNode* r;

    while(current != NULL){
        r = current->next;

        while(r != NULL){
            if(compare(current->data, r->data) > 0){
                void* temp = current->data;
                current->data = r->data;
                r->data = temp;
            }
            r = r->next;
        }

        current = current->next;
    }

    return list;
};

/*
    dll_mergesort
    Function to sort a `DoublyLinkedList` (dll) using the merge sort algorithm.
    @param DoublyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns DoublyLinkedList* list
*/
DoublyLinkedList* dll_mergesort(DoublyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    DoublyLinkedList* left = dll_create();
    DoublyLinkedList* right = dll_create();
    DoublyLinkedList* result = dll_create();

    int size = dll_len(list);
    int mid = size / 2;

    DLLNode* current = list->head;
    for(int i = 0; i < mid; i++){
        dll_insert(left, current->data);
        current = current->next;
    }

    for(int i = mid; i < size; i++){
        dll_insert(right, current->data);
        current = current->next;
    }

    left = dll_mergesort(left, compare);
    right = dll_mergesort(right, compare);

    DLLNode* l = left->head;
    DLLNode* r = right->head;

    while(l != NULL && r != NULL){
        if(compare(l->data, r->data) < 0){
            dll_insert(result, l->data);
            l = l->next;
        }else{
            dll_insert(result, r->data);
            r = r->next;
        }
    }

    while(l != NULL){
        dll_insert(result, l->data);
        l = l->next;
    }

    while(r != NULL){
        dll_insert(result, r->data);
        r = r->next;
    }

    return result;
};

/*
    dll_quicksort
    Function to sort a `DoublyLinkedList` (dll) using the quick sort algorithm.
    @param DoublyLinkedList* list
    @param int (*compare)(void*, void*)
    @returns DoublyLinkedList* list
*/
DoublyLinkedList* dll_quicksort(DoublyLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    DoublyLinkedList* left = dll_create();
    DoublyLinkedList* right = dll_create();
    DoublyLinkedList* result = dll_create();

    DLLNode* pivot = list->head;
    DLLNode* current = list->head->next;

    while(current != NULL){
        if(compare(current->data, pivot->data) < 0){
            dll_insert(left, current->data);
        }else{
            dll_insert(right, current->data);
        }
        current = current->next;
    }

    left = dll_quicksort(left, compare);
    right = dll_quicksort(right, compare);

    DLLNode* l = left->head;
    DLLNode* r = right->head;

    while(l != NULL){
        dll_insert(result, l->data);
        l = l->next;
    }

    dll_insert(result, pivot->data);

    while(r != NULL){
        dll_insert(result, r->data);
        r = r->next;
    }

    return result;
};


/*
    `CircularLinkedList` sorting functions
*/
CircularLinkedList* cll_bubblesort(CircularLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    int swapped;
    CLLNode* temp;
    CLLNode* end = NULL;

    do{
        swapped = 0;
        temp = list->head;

        while(temp->next != end){
            if(compare(temp->data, temp->next->data) > 0){
                void* t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
                swapped = 1;
            }
            temp = temp->next;
        }
        end = temp;
    }while(swapped);

    return list;
};

CircularLinkedList* cll_selectionsort(CircularLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    CLLNode* temp = list->head;
    CLLNode* min;

    while(temp->next != NULL){
        min = temp;
        CLLNode* r = temp->next;

        while(r != NULL){
            if(compare(r->data, min->data) < 0){
                min = r;
            }
            r = r->next;
        }

        void* t = min->data;
        min->data = temp->data;
        temp->data = t;

        temp = temp->next;
    }

    return list;
};

CircularLinkedList* cll_insertionsort(CircularLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    CLLNode* temp = list->head;
    CLLNode* r;

    while(temp != NULL){
        r = temp->next;

        while(r != NULL){
            if(compare(temp->data, r->data) > 0){
                void* t = temp->data;
                temp->data = r->data;
                r->data = t;
            }
            r = r->next;
        }

        temp = temp->next;
    }

    return list;
};

CircularLinkedList* cll_mergesort(CircularLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    CircularLinkedList* left = cll_create();
    CircularLinkedList* right = cll_create();
    CircularLinkedList* result = cll_create();

    int size = cll_len(list);
    int mid = size / 2;

    CLLNode* temp = list->head;
    for(int i = 0; i < mid; i++){
        cll_insert(left, temp->data);
        temp = temp->next;
    }

    for(int i = mid; i < size; i++){
        cll_insert(right, temp->data);
        temp = temp->next;
    }

    left = cll_mergesort(left, compare);
    right = cll_mergesort(right, compare);

    CLLNode* l = left->head;
    CLLNode* r = right->head;

    while(l != NULL && r != NULL){
        if(compare(l->data, r->data) < 0){
            cll_insert(result, l->data);
            l = l->next;
        }else{
            cll_insert(result, r->data);
            r = r->next;
        }
    }

    while(l != NULL){
        cll_insert(result, l->data);
        l = l->next;
    }

    while(r != NULL){
        cll_insert(result, r->data);
        r = r->next;
    }

    return result;
};

CircularLinkedList* cll_quicksort(CircularLinkedList* list, int (*compare)(void*, void*)){
    if(list == NULL || list->head == NULL || list->head->next == NULL){
        return list;
    }

    CircularLinkedList* left = cll_create();
    CircularLinkedList* right = cll_create();
    CircularLinkedList* result = cll_create();

    CLLNode* pivot = list->head;
    CLLNode* temp = list->head->next;

    while(temp != NULL){
        if(compare(temp->data, pivot->data) < 0){
            cll_insert(left, temp->data);
        }else{
            cll_insert(right, temp->data);
        }
        temp = temp->next;
    }

    left = cll_quicksort(left, compare);
    right = cll_quicksort(right, compare);

    CLLNode* l = left->head;
    CLLNode* r = right->head;

    while(l != NULL){
        cll_insert(result, l->data);
        l = l->next;
    }

    cll_insert(result, pivot->data);

    while(r != NULL){
        cll_insert(result, r->data);
        r = r->next;
    }

    return result;
};

