#include "Heap.h"
void chartest() {
    char ch = 'a';
    char ch1 = 'b';
    ch < ch1 ? cout << "yes\n" : cout<<"no\n";
    cout << ch1 - ch;
}
void heapTest()
{

    char myword[] = "Hello";
    Heap<char> *H1 = new Heap<char>(myword, 5, 10, MAXHEAP);
    H1->show();
    Heap<int> *H = new Heap<int>(10, MAXHEAP);
    H->insert(12);
    H->show();
    H->insert(120);
    H->insert(130);
    H->insert(13);
    H->insert(14);
    H->corrupt(1);
    H->percolateDown(0);
    H->show();
    H->remove();
    H->show();
    H->remove();
}

int main() {
    //heapTest();
    int data[] = {1,2,3,4,5,6};
    Heap<int> *H = new Heap<int>(data, 6, 10, MAXHEAP);
    H->show();
    H->heapSort();
    H->show();
}
