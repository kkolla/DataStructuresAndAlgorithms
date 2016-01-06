#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int stackInit = 0;
typedef struct stack_
{
    int capacity;
    int top;
    int *a;
} stack;

stack* createStack(int capacity)
{
    stackInit = 1;
    stack *s = (stack*)malloc(sizeof(stack));
    s->capacity = capacity;
    s->top = -1;
    s->a = (int*)malloc(sizeof(int)*capacity);
    memset(s->a, 0, capacity);
    return s;
}

int isEmpty(stack *s)
{
    return (s->top == -1);
}

int isFull(stack *s)
{
    return (s->top == (s->capacity-1));
}
void removeStack(stack *s)
{
    free(s->a);
    free(s);
    stackInit = 0;
}
void push(stack *s, int data)
{
    if(isFull(s)) return;
    s->top = s->top + 1;
    s->a[s->top] = data;
}
int pop(stack *s)
{
    if(isEmpty(s)) return -1;
    int data = s->a[s->top];
    s->top--;
    return data;
}
