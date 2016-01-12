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
void printList(List *head);
List* makeSLL(int len, int* input);
void usage();
int* processInputs (int *length, int argc, char *argv[]);
List* sortList(List *head);
List* reverseMerge(List *head1, List *head2);
