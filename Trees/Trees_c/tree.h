#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int stackInit = 0;
int queueInit = 0;

typedef struct tree_
{
    struct tree_ *left;
    struct tree_ *right;
    int data;
} tree;


void inOrderFree_(tree *root)
{
    if (root == NULL) return;
    inOrderFree_(root->left);
    inOrderFree_(root->right);
    free(root);
}
void inOrderFree(tree *root) {
    inOrderFree_(root);
}

tree* makeTreeNode(int data)
{
    tree* newNode = (tree*)malloc(sizeof(tree));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}
tree* makeTree_(int *input, int low, int high)
{
    if (low == high) return makeTreeNode(input[low]);
    if (low < high) {
        int mid = (low + high) / 2;
        tree *root = makeTreeNode(input[mid]);
        root->left = makeTree_(input, low, mid - 1);
        root->right = makeTree_(input, mid+1, high);
        return root;
    } else {
        return NULL;
    }
}

tree* makeTree(int *input, int len)
{
    return makeTree_(input, 0, len - 1);
}

/*
 *  Utility Functions
 */

void usage()
{
 printf("tree [7 numbers..]\n");
 exit(1);
}

int *processArguments(int argc, char *argv[])
{
    if (argc < 8)
    {
        usage();
    }
    int *input = (int*)malloc(sizeof(int)*(argc-1));
    memset(input, 0, argc-1);
    for(int i = 0; i < argc-1; i++)
    {
        input[i] = atoi(argv[i+1]);
    }
    return input;
}
void printArray(int *a, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

/*
 *  Stack Functions
 */

typedef struct stack_
{
    int capacity;
    int top;
    tree **a;
} stack;

/*
 *  queue Functions
 */
typedef struct queue_
{
    int capacity;
    int front;
    int rear;
    tree **a;
} queue;

stack* createQueue(int capacity)
{
    queueInit = 1;
    queue *s = (queue*)malloc(sizeof(queue));
    s->capacity = capacity;
    s->front = -1;
    s->rear = -1;
    s->a = (tree**)malloc(sizeof(tree*) * capacity);
    memset(s->a, 0, sizeof(tree*) * capacity);
    return s;
}

int queueSize(queue *q)
{   // insertion at front
    return (q->capacity + q->front - q->rear + 1) % q->capacity;
}

int isQEmpty(queue *q)
{
    return (q->front == -1);
}

int isQFull(queue *q)
{
    return (((q->front + 1) % q->capacity) == q->rear);
}

void enqueue(tree *root)
{
    
}
stack* createStack(int capacity)
{
    stackInit = 1;
    stack *s = (stack*)malloc(sizeof(stack));
    s->capacity = capacity;
    s->top = -1;
    s->a = (tree**)malloc(sizeof(tree*) * capacity);
    memset(s->a, 0, sizeof(tree*) * capacity);
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
void push(stack *s, tree* data)
{
    if(isFull(s)) return;
    s->top = s->top + 1;
    s->a[s->top] = data;
}
tree* pop(stack *s)
{
    if(isEmpty(s)) return NULL;
    tree *data = s->a[s->top];
    s->top--;
    return data;
}
void showTreeStack(stack* S)
{
    if (isEmpty(S)) {
        printf("Empty Stack\n");
        return;
    }
    for (int i = S->top; i >=0; i--)
    {
        printf("%d ",S->a[i]->data);
    }
}


void shutDown(stack *s, tree *root, int *input)
{
    free(input);
    removeStack(s);
    inOrderFree(root);
}
