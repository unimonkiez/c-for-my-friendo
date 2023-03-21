#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main()
{
    Stack *s;
    size_t element_size;
    int num1 = 7;
    int num2 = 450;
    int num3 = 350;
    int *num = NULL;

    element_size = sizeof(int);
    s = CreateStack(element_size, 10);

    assert(10 == Capacity(s));

    Push(s, &num1);
    Push(s, &num2);
    Push(s, &num3);

    Pop(s);
    assert(2 == Size(s));

    num = (int *)Pop(s);
    assert(num2 == *num);

    Pop(s);
    Pop(s);
    Pop(s);
    Pop(s);
    Pop(s);

    assert(0 == Size(s));

    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);
    Push(s, &num1);

    assert(10 == Size(s));

    return 0;
}
