#include <iostream>
#include <queue>          // std::queue
#include <algorithm>    // std::max
#include <signal.h>

using namespace std;
class List
{
public:
    int data;
    List *next;
    List() {
        data = 0;
        next = NULL;
    }
    List(int d) {
        data = d;
        next = NULL;
    }
    void show() {
        cout<<data<<" ";
    }
};
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
