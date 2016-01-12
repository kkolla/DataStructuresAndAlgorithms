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
void printDeep(multiLevelList *head) {
    while(head != NULL)
    {
        head->show();
        cout<<"-> ";
        head = head->down;
    }
    printf("NULL \n");
}

void printList(multiLevelList *head)
{
    while(head != NULL)
    {
        //head->showln();
        printDeep(head);
        cout<<"|\n";
        cout<<"v\n";
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
multiLevelList* makeMultiLevelSLL(int len, int* input)
{
    multiLevelList *head;
    if(len == 0) {
        return NULL;
    }
    head = new multiLevelList(input[0]);
    head->next = makeMultiLevelSLL(len - 1, input+1);
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
/*
 * 'multiply' multiplies the given data by a given number;
 *
 */
List* getList(int argc, char *argv[], int multiply)
{
    int listLen;
    int *input = processInputs(&listLen, argc, argv);
    for (size_t i = 0; i < listLen; i++) {
        input[i] *= multiply;
    }
    List *head = makeSLL(listLen, input);
    free(input);
    return head;
}
/*
 * 'multiply' multiplies the given data by a given number;
 *
 */
multiLevelList* getMultiLevelList(int argc, char *argv[], int multiply)
{
    int listLen;
    int *input = processInputs(&listLen, argc, argv);
    for (size_t i = 0; i < listLen; i++) {
        input[i] *= multiply;
    }
    multiLevelList *head = makeMultiLevelSLL(listLen, input);
    free(input);
    return head;
}
