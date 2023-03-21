#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *CreateStack(size_t elem_size, size_t capacity)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL)
    {
        return NULL;
    }

    s->data = malloc(elem_size * capacity);
    s->elem_size = elem_size;
    s->num_elements = 0;
    s->capacity = capacity;

    return s;
}

int DestroyStack(Stack *s)
{
    free(s->data);
    free(s);

    s->data = NULL;
    s = NULL;

    return 0;
}

int IsEmpty(const Stack *s)
{
    return s->num_elements == 0;
}

size_t Size(Stack *s)
{
    return s->num_elements;
}

size_t Capacity(const Stack *s)
{
    return s->capacity;
}

void *Peek(const Stack *s)
{
    char *ptr = NULL;
    int v;
    if (s->num_elements == 0)
    {
        return ptr;
    }

    ptr = s->data;
    ptr += (s->elem_size * (s->num_elements - 1));
    v = *ptr;

    return ptr;
}

int Push(Stack *s, void *elem)
{
    size_t i = 0;
    char *ptr_to_value = elem;
    char *ptr = NULL;

    if (s->num_elements == s->capacity)
    {
        return 1;
    }

    ptr = s->data;
    ptr += (s->elem_size * s->num_elements);

    for (i = 0; i < s->elem_size; i++)
    {
        *(ptr + i) = *((char *)(ptr_to_value + i));
    }

    s->num_elements++;

    return 0;
}

void *Pop(Stack *s)
{
    void *ptr = NULL;
    if (s->num_elements == 0)
    {
        return ptr;
    }

    ptr = Peek(s);

    s->num_elements--;

    return ptr;
}
