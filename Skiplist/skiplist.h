#include <iostream>
#include <math.h>
#define LEVELS 4
using namespace std;
static int x = 0, y = 0;

void usage()
{
    printf("skiplist <size> <SLL1> <SLL2> ...\n");
    printf("Example:\n\t./skiplist 9 1 3 5 7 9 11 13 15 17\n");
    exit(1);
}
class Skiplist
{
public:
    int data;
    Skiplist *next[LEVELS];
    Skiplist() {
        data = 0;
        for (size_t i = 0; i < LEVELS; i++) {
            next[i] = NULL;
        }
    }
    Skiplist(int d) {
        data = d;
        for (size_t i = 0; i < LEVELS; i++) {
            next[i] = NULL;
        }
    }
    void show() {
        cout<<data;
    }
};
