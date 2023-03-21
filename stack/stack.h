#ifndef __STACK_H__
#define __STACK_H__

typedef struct {
    void *data; /* the stack itself */
    size_t elem_size; /* size of data type of every element */
    size_t num_elements; /* number of elements in stack */
    size_t capacity; /* capacity of stack in bytes */
} Stack;

Stack *CreateStack(size_t elem_size, size_t capacity); 

int DestroyStack(Stack *s);

int IsEmpty(const Stack *s);

size_t Size(Stack *s);

size_t Capacity(const Stack *s);

void *Peek(const Stack *s); 

int Push(Stack *s, void *elem);

void *Pop(Stack *s);

#endif
