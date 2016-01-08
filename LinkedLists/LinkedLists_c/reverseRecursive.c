#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list_
{
    struct list_* next;
    int data;
} list;

list* makeNode(int data)
{
    list* newNode = (list*)malloc(sizeof(list));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void usage()
{
    printf("sll <size> <SLL1> <SLL2> ...\n");
    exit(1);
}
list* makeSLL(int len, int* input)
{
    list *head;
    if(len == 0) {
        return NULL;
    }
    head = makeNode(input[0]);
    head->next = makeSLL(len - 1, input+1);
    return head;
}
void printList(list *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL \n");
}
list* reverseRecursive(list *head)
{
    list *nextNode;
    if (head == NULL || head->next == NULL) return head;
    nextNode = head->next;
    head->next = nextNode->next;
    nextNode->next = head;
    head->next = reverseRecursive(head->next);
    return nextNode;
}
int main(int argc, char *argv[]) {
    list *head;
    int *input;
    int size;
    if (argc <= 1)
    {
        usage();
    }
    size = atoi(argv[1]);
    printf("size %d\n",size);
    if (size == 0)
    {
        return 0;
    }

    if (argc != size + 2)
    {
        usage();
    }
    input = (int*)malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++)
    {
        input[i] = atoi(argv[i+2]);
    }
    head = makeSLL(size, input);
    printList(head);
    head = reverseRecursive(head);
	printList(head);
    return 0;
}
