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
    void showln() {
        cout<<data<<" \n";
    }
};
class multiLevelList : public List
{
public:
    multiLevelList *down;
    multiLevelList *next;
    multiLevelList() : List()
    {
        down = NULL;
    }
    multiLevelList(int d) : List(d)
    {
        down = NULL;
    }
};
void printList(List *head);
void printList(multiLevelList *head);
void usage();
int* processInputs (int *length, int argc, char *argv[]);
List* sortList(List *head);
List* reverseMerge(List *head1, List *head2);
List* makeSLL(int len, int* input);
List* getList(int argc, char *argv[], int multiply);
multiLevelList* getMultiLevelList(int argc, char *argv[], int multiply);
multiLevelList* makeMultiLevelSLL(int len, int* input);;
