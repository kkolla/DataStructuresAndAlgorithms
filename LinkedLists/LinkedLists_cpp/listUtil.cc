#include "list.h"
void printList(List *head)
{
    while(head != NULL)
    {
        head->show();
        cout<<"-> ";
        head = head->next;
    }
    printf("NULL \n");
}

List* makeSLL(int len, int* input)
{
    List *head;
    if(len == 0) {
        return NULL;
    }
    head = new List(input[0]);
    head->next = makeSLL(len - 1, input+1);
    return head;
}
void usage()
{
    printf("list <size> <SLL1> <SLL2> ...\n");
    exit(1);
}

int* processInputs (int *length, int argc, char *argv[])
{
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
    int* input = new int[size];
    for(int i = 0; i < size; i++)
    {
        input[i] = atoi(argv[i+2]);
    }
    *length = size;
    return input;
}
