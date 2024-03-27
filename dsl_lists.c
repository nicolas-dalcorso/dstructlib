/*
    Implementation of lists data structures
    - Singly linked list
    - Doubly linked list
    - Circular linked list
    - Stack
    - Queue


    nrdc
    v1.0 2024-03-27
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dsl_lists.h"

/*
    1. Singly linked list
*/
/*
    sllnode_create
    Create a new node for a singly linked list
    @param  void*       Pointer to data to be stored in the node
    @return SLLNode*    Pointer to the new node
*/
SLLNode* sllnode_create(void* data){
    //  Allocate memory for the node
    SLLNode* node = (SLLNode*)malloc(sizeof(SLLNode));

    //  Initialize the node
    node->data = data;
    node->next = NULL;

    if(!node){
        return NULL;
    }   else{
            return node;
    }
}

/*
    sllnode_free
    Free a node from a singly linked list
    @param  SLLNode*    Pointer to the node to be freed
    @return void
*/
void sllnode_free(SLLNode* node){
    free(node);
}

/*
    sll_get_next
    Get the next node in a singly linked list
    @param  SLLNode*    Pointer to the current node
    @return SLLNode*    Pointer to the next node
*/
SLLNode* sll_get_next(SLLNode* node){
    return node->next;
};

/*
    sll_create
    Create a new, empty, singly linked list
    @param                      void
    @return SinglyLinkedList*   Pointer to the new list
*/
SinglyLinkedList* sll_create(void){
    //  Allocate memory for the list
    SinglyLinkedList* sll = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));

    //  Initialize the list
    sll->head = NULL;
    sll->size = 0;

    if(!sll){
        return NULL;
    }   else{
            return sll;
    }
}

/*
    sll_destroy
    Destroy a singly linked list
    @param  SinglyLinkedList*   Pointer to the list to be destroyed
    @return void
*/
void sll_destroy(SinglyLinkedList* sll){
    SLLNode* current = sll->head;
    SLLNode* next = NULL;

    while(current){
        next = current->next;
        sllnode_free(current);
        current = next;
    }

    free(sll);
}

/*
    sll_insert
    Insert a new node at the beginning of a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be stored in the new node
    @return bool                true if the operation was successful, false otherwise
*/
bool sll_insert(SinglyLinkedList* sll, void* data){
    //  Create a new node
    SLLNode* node = sllnode_create(data);

    if(!node){
        return false;
    }

    //  Insert the new node at the beginning of the list
    node->next = sll->head;
    sll->head = node;
    sll->size++;

    return true;
}

/*
    sll_append
    Append a new node at the end of a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be stored in the new node
    @return bool                true if the operation was successful, false otherwise
*/
bool sll_append(SinglyLinkedList* sll, void* data){
    //  Create a new node
    SLLNode* node = sllnode_create(data);

    if(!node){
        return false;
    }

    //  Find the last node in the list
    SLLNode* current = sll->head;
    while(current->next){
        current = current->next;
    }

    //  Append the new node to the list
    current->next = node;
    sll->size++;

    return true;
}

/*
    sll_remove
    Remove a node from a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be removed
    @return bool                true if the operation was successful, false otherwise
*/
bool sll_remove(SinglyLinkedList* sll, void* data){
    SLLNode* current = sll->head;
    SLLNode* previous = NULL;

    while(current){
        if(current->data == data){
            if(previous){
                previous->next = current->next;
            }   else{
                    sll->head = current->next;
            }

            sllnode_free(current);
            sll->size--;

            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
};

/*
    sll_search
    Search for a node in a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be searched
    @return SLLNode*            Pointer to the node if found, NULL otherwise
*/
SLLNode* sll_search(SinglyLinkedList* sll, void* data){
    SLLNode* current = sll->head;

    while(current){
        if(current->data == data){
            return current;
        }

        current = current->next;
    }

    return NULL;
};

/*
    sll_print
    Print the contents of a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @return void
*/
void sll_print(SinglyLinkedList* sll){
    SLLNode* current = sll->head;

    while(current){
        printf("%d\n", *(int*)current->data);
        current = current->next;
    }
};

/*
    sll_len
    Get the number of nodes in a singly linked list
    @param  SinglyLinkedList*   Pointer to the list
    @return size_t              Number of nodes in the list
*/
int sll_len(SinglyLinkedList* sll){
    return sll->size;
};


/*
    2. Doubly linked list
*/

/*
    dllnode_create
    Create a new doubly linked list node
    @param `data` is a pointer to the data to store in the node
    @returns pointer to the new doubly linked list node
*/
DLLNode* dllnode_create(void* data){
    DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));

    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if(!node){
        return NULL;
    }   else{
            return node;
    }
};

/*
    dllnode_free
    Free a node from a doubly linked list
    @param  DLLNode*    Pointer to the node to be freed
    @return void
*/
void dllnode_free(DLLNode* node){
    free(node);
};

/*
    dll_create
    Create a new doubly linked list
    @param  void
    @return DoublyLinkedList*   Pointer to the new list
*/
DoublyLinkedList* dll_create(void){
    DoublyLinkedList* dll = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));

    dll->head = NULL;
    dll->tail = NULL;
    dll->size = 0;

    if(!dll){
        return NULL;
    }   else{
            return dll;
    }
};

/*
    dll_destroy
    Destroy a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @return void
*/
void dll_destroy(DoublyLinkedList* dll){
    DLLNode* current = dll->head;
    DLLNode* next = NULL;

    while(current){
        next = current->next;
        dllnode_free(current);
        current = next;
    }

    free(dll);
};

/*
    dll_insert
    Insert a new node at the beginning of a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be stored in the new node
    @return bool                true if the operation was successful, false otherwise
*/
bool dll_insert(DoublyLinkedList* dll, void* data){
    DLLNode* node = dllnode_create(data);

    if(!node){
        return false;
    }

    node->next = dll->head;
    node->prev = NULL;

    if(dll->head){
        dll->head->prev = node;
    }   else{
            dll->tail = node;
    }

    dll->head = node;
    dll->size++;

    return true;
};

/*
    dll_append
    Append a new node at the end of a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be stored in the new node
    @return bool                true if the operation was successful, false otherwise
*/
bool dll_append(DoublyLinkedList* dll, void* data){
    DLLNode* node = dllnode_create(data);

    if(!node){
        return false;
    }

    node->next = NULL;
    node->prev = dll->tail;

    if(dll->tail){
        dll->tail->next = node;
    }   else{
            dll->head = node;
    }

    dll->tail = node;
    dll->size++;

    return true;
};

/*
    dll_remove
    Remove a node from a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be removed
    @return bool                true if the operation was successful, false otherwise
*/
bool dll_remove(DoublyLinkedList* dll, void* data){
    DLLNode* current = dll->head;

    while(current){
        if(current->data == data){
            if(current->prev){
                current->prev->next = current->next;
            }   else{
                    dll->head = current->next;
            }

            if(current->next){
                current->next->prev = current->prev;
            }   else{
                    dll->tail = current->prev;
            }

            dllnode_free(current);
            dll->size--;

            return true;
        }

        current = current->next;
    }

    return false;
};

/*
    dll_search
    Search for a node in a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @param  void*               Pointer to the data to be searched
    @return DLLNode*            Pointer to the node if found, NULL otherwise
*/
DLLNode* dll_search(DoublyLinkedList* dll, void* data){
    DLLNode* current = dll->head;

    while(current){
        if(current->data == data){
            return current;
        }

        current = current->next;
    }

    return NULL;
};

/*
    dll_print
    Print the contents of a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @return void
*/
void dll_print(DoublyLinkedList* dll){
    DLLNode* current = dll->head;

    while(current){
        printf("%d\n", *(int*)current->data);
        current = current->next;
    }
};

/*
    dll_len
    Get the number of nodes in a doubly linked list
    @param  DoublyLinkedList*   Pointer to the list
    @return size_t              Number of nodes in the list

*/
size_t dll_len(DoublyLinkedList* dll){
    return dll->size;
};



/*
    3. Circular linked list
*/

/*
    cllnode_create
    Create a new circular linked list node
    @param `data` is a pointer to the data to store in the node
    @returns pointer to the new circular linked list node
*/
CLLNode* cllnode_create(void* data){
    CLLNode* node = (CLLNode*)malloc(sizeof(CLLNode));

    node->data = data;
    node->next = NULL;

    if(!node){
        return NULL;
    }   else{
            return node;
    }
};

/*
    cllnode_free
    Free a node from a circular linked list
    @param  CLLNode*    Pointer to the node to be freed
    @return void
*/
void cllnode_free(CLLNode* node){
    free(node);
};

/*
    cll_create
    Create a new circular linked list
    @param  void
    @return CircularLinkedList*   Pointer to the new list
*/
CircularLinkedList* cll_create(void){
    CircularLinkedList* cll = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));

    cll->head = NULL;
    cll->size = 0;

    if(!cll){
        return NULL;
    }   else{
            return cll;
    }
};

/*
    cll_destroy
    Destroy a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @return void
*/
void cll_destroy(CircularLinkedList* cll){
    CLLNode* current = cll->head;
    CLLNode* next = NULL;

    while(current){
        next = current->next;
        cllnode_free(current);
        current = next;
    }

    free(cll);
};

/*
    cll_insert
    Insert a new node at the beginning of a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @param  void*                 Pointer to the data to be stored in the new node
    @return bool                  true if the operation was successful, false otherwise
*/
bool cll_insert(CircularLinkedList* cll, void* data){
    CLLNode* node = cllnode_create(data);

    if(!node){
        return false;
    }

    if(!cll->head){
        cll->head = node;
        node->next = node;
    }   else{
            CLLNode* current = cll->head;

            while(current->next != cll->head){
                current = current->next;
            }

            current->next = node;
            node->next = cll->head;
            cll->head = node;
    }

    cll->size++;

    return true;
};

/*
    cll_append
    Append a new node at the end of a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @param  void*                 Pointer to the data to be stored in the new node
    @return bool                  true if the operation was successful, false otherwise
*/
bool cll_append(CircularLinkedList* cll, void* data){
    CLLNode* node = cllnode_create(data);

    if(!node){
        return false;
    }

    if(!cll->head){
        cll->head = node;
        node->next = node;
    }   else{
            CLLNode* current = cll->head;

            while(current->next != cll->head){
                current = current->next;
            }

            current->next = node;
            node->next = cll->head;
    }

    cll->size++;

    return true;
};

/*
    cll_remove
    Remove a node from a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @param  void*                 Pointer to the data to be removed
    @return bool                  true if the operation was successful, false otherwise
*/
bool cll_remove(CircularLinkedList* cll, void* data){
    CLLNode* current = cll->head;
    CLLNode* previous = NULL;

    while(current->next != cll->head){
        if(current->data == data){
            if(previous){
                previous->next = current->next;
            }   else{
                    cll->head = current->next;
            }

            cllnode_free(current);
            cll->size--;

            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
};

/*
    cll_search
    Search for a node in a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @param  void*                 Pointer to the data to be searched
    @return CLLNode*              Pointer to the node if found, NULL otherwise
*/
CLLNode* cll_search(CircularLinkedList* cll, void* data){
    CLLNode* current = cll->head;

    while(current->next != cll->head){
        if(current->data == data){
            return current;
        }

        current = current->next;
    }

    return NULL;
};

/*
    cll_print
    Print the contents of a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @return void
*/
void cll_print(CircularLinkedList* cll){
    CLLNode* current = cll->head;

    while(current->next != cll->head){
        printf("%d\n", *(int*)current->data);
        current = current->next;
    }
};

/*
    cll_len
    Get the number of nodes in a circular linked list
    @param  CircularLinkedList*   Pointer to the list
    @return size_t                Number of nodes in the list
*/
size_t cll_len(CircularLinkedList* cll){
    return cll->size;
};





/*
    4. Stack
*/

/*
    stack_create
    Create a new stack
    @param  void
    @return Stack*   Pointer to the new stack
*/
Stack* stack_create(void){
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    stack->top = NULL;
    stack->size = 0;

    if(!stack){
        return NULL;
    }   else{
            return stack;
    }
}

/*
    stack_destroy
    Destroy a stack
    @param  Stack*  Pointer to the stack
    @return void
*/
void stack_destroy(Stack* stack){
    DLLNode* current = stack->top;
    DLLNode* next = NULL;

    while(current){
        next = current->next;
        dllnode_free(current);
        current = next;
    }

    free(stack);

}

/*
    stack_push
    Push a new element onto the stack
    @param  Stack*  Pointer to the stack
    @param  void*   Pointer to the data to be stored in the new element
    @return bool    true if the operation was successful, false otherwise
*/
bool stack_push(Stack* stack, void* data){
    DLLNode* node = dllnode_create(data);

    if(!node){
        return false;
    }

    node->next = stack->top;
    stack->top = node;
    stack->size++;

    return true;

}

/*
    stack_pop
    Pop the top element from the stack
    @param  Stack*  Pointer to the stack
    @return void*   Pointer to the data of the top element
*/
void* stack_pop(Stack* stack){
    if(!stack->top){
        return NULL;
    }

    DLLNode* node = stack->top;
    void* data = node->data;

    stack->top = node->next;
    dllnode_free(node);
    stack->size--;

    return data;
}

/*
    stack_top
    Get the top element of the stack
    @param  Stack*  Pointer to the stack
    @return void*   Pointer to the data of the top element
*/
void* stack_top(Stack* stack){
    if(!stack->top){
        return NULL;
    }

    return stack->top->data;
}

/*
    stack_size
    Get the number of elements in the stack
    @param  Stack*  Pointer to the stack
    @return size_t  Number of elements in the stack
*/
size_t stack_size(Stack* stack){
    return stack->size;
}



/*
    5. Queue
*/

/*
    queue_create
    Create a new queue
    @param  void
    @return Queue*   Pointer to the new queue
*/
Queue* queue_create(void){
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;

    if(!queue){
        return NULL;
    }   else{
            return queue;
    }
};

/*
    queue_destroy
    Destroy a queue
    @param  Queue*  Pointer to the queue
    @return void
*/
void queue_destroy(Queue* queue){
    DLLNode* current = queue->front;
    DLLNode* next = NULL;

    while(current){
        next = current->next;
        dllnode_free(current);
        current = next;
    }

    free(queue);
};

/*
    queue_enqueue
    Enqueue a new element into the queue
    @param  Queue*  Pointer to the queue
    @param  void*   Pointer to the data to be stored in the new element
    @return bool    true if the operation was successful, false otherwise
*/
bool queue_enqueue(Queue* queue, void* data){
    DLLNode* node = dllnode_create(data);

    if(!node){
        return false;
    }

    if(!queue->front){
        queue->front = node;
    }   else{
            queue->back->next = node;
    }

    queue->back = node;
    queue->size++;

    return true;
};

/*
    queue_dequeue
    Dequeue the front element from the queue
    @param  Queue*  Pointer to the queue
    @return void*   Pointer to the data of the front element
*/
void* queue_dequeue(Queue* queue){
    if(!queue->front){
        return NULL;
    }

    DLLNode* node = queue->front;
    void* data = node->data;

    queue->front = node->next;
    dllnode_free(node);
    queue->size--;

    return data;
};

/*
    queue_front
    Get the front element of the queue
    @param  Queue*  Pointer to the queue
    @return void*   Pointer to the data of the front element
*/
void* queue_front(Queue* queue){
    if(!queue->front){
        return NULL;
    }

    return queue->front->data;
};

/*
    queue_back
    Get the back element of the queue
    @param  Queue*  Pointer to the queue
    @return void*   Pointer to the data of the back element
*/
void* queue_back(Queue* queue){
    if(!queue->back){
        return NULL;
    }

    return queue->back->data;
};

/*
    queue_size
    Get the number of elements in the queue
    @param  Queue*  Pointer to the queue
    @return size_t  Number of elements in the queue
*/
size_t queue_size(Queue* queue){
    return queue->size;
};




/*
    6.  Conversion functions
*/
/*
    sll_to_dll
    Convert a singly linked list to a doubly linked list
    @param `sll` is a pointer to the singly linked list to convert
    @returns pointer to the new doubly linked list
*/
DoublyLinkedList* sll_to_dll(SinglyLinkedList* sll){
    DoublyLinkedList* dll = dll_create();
    SLLNode* current = sll->head;

    while(current){
        dll_append(dll, current->data);
        current = current->next;
    }

    return dll;
};

/*
    dll_to_sll
    Convert a doubly linked list to a singly linked list. The conversion is done by traversing the doubly linked list from the head to the tail and creating a new singly linked list with the same elements.
    It is useful to understand this function as a 'forgetful functor' that forgets the previous node relationship.
    @param `dll` is a pointer to the doubly linked list to convert
    @returns pointer to the new singly linked list
*/
SinglyLinkedList* dll_to_sll(DoublyLinkedList* dll){
    SinglyLinkedList* sll = sll_create();
    DLLNode* current = dll->head;

    while(current){
        sll_append(sll, current->data);
        current = current->next;
    }

    return sll;
};
