#include <iostream>
#include <queue>          // std::queue
#include <algorithm>    // std::max
#include <signal.h>
#define MINHEAP 0
#define MAXHEAP 1

using namespace std;

int parent(int i, int count)
{
    if (i <=0 || i >= count) return -1;
    return (i - 1) / 2;
}
int rchild(int i, int count)
{
    int right = (2*i) + 2;
    if (right >= count) return -1;
    return right;
}
int lchild(int i, int count)
{
    int left = (2*i) + 1;
    if (left >= count) return -1;
    return left;
}
template <class T>
int maximum(T* memory, int i, int l, int r)
{
    if (memory[i] > memory[l] && memory[i] > memory[r]) return i;
    if (memory[l] > memory[i] && memory[l] > memory[r]) return l;
    return r;
}
template <class T>
int givemax(T* memory, int i, int j)
{
    if (memory[i] > memory[j]) return i;
    return j;
}
template <class T>
void swap(T* memory, int i, int j)
{
    T temp = memory[i];
    memory[i] = memory[j];
    memory[j] = temp;
}
template <class T> class Heap
{
public:
    T *memory;
    int count;
    int capacity;
    int type;
    Heap() {
        count = 0;
        capacity = 0;
        type = MINHEAP;
    }
    Heap(int cap, int t) {
        count = 0;
        capacity = cap;
        if (type != MINHEAP && type != MAXHEAP) {
            type = MINHEAP;
        } else {
            type = t;
        }
        memory = new T[cap];
        memset (memory, 0, cap);
    }
    Heap(T array[], int len, int cap, int t) {
        count = len;
        capacity = max(cap, len);
        if (t != MINHEAP && t != MAXHEAP) {
            type = MINHEAP;
        } else {
            type = t;
        }
        memory = new T[capacity];
        memset (memory, 0, capacity);
        for (int i = 0; i < len; i++) {
            memory[i] = array[i];
        }
    }
    void showmem() {
        if (count != 0) {
            for (int i = 0; i < count; i++) {
                cout << memory[i] << " ";
            }
        }
        cout<<endl;
    }
    void show() {
        cout<<"Heap Capacity: "<<capacity<<endl;
        cout<<"Heap Count   : "<<count<<endl;
        cout<<"Heap type    : ";
        type ? cout<<"MAXHEAP":cout<<"MINHEAP";
        cout<<"\nHeap Contents:"<<endl;
        if (count != 0) {
            for (int i = 0; i < count; i++) {
                cout << memory[i] << " ";
            }
        } else {
            cout<<"  --empty--";
        }
        cout<<endl;
    }
    int isFull() {
        return (count == capacity);
    }
    void insert(T data){
        int insertionPoint;
        int p, l, r;
        if (isFull()) return;
        insertionPoint = count;
        memory[count] = data;
        count++;
        while (insertionPoint >= 0 ) {
            p = parent(insertionPoint, count);
            if(memory[insertionPoint] > memory[p])
            {
                swap(memory, insertionPoint, p);
            }
            insertionPoint = p;
        }
    }
    void corrupt(T a)
    {
        memory[0] = a;
    }
    void percolateDown(int i)
    {
        int l, r, max;
        while (i < count) {
            l = lchild(i, count);
            r = rchild(i, count);
            if (l == -1 && r == -1) break;
            if (l == -1) max = givemax(memory, i, r);
            else if (r == -1) max = givemax(memory, i, l);
            else max = maximum(memory, i, l, r);
            if (max == i) break;
            swap(memory, max, i);
            i = max;
        }
    }
    void percolateUp(int i)
    {
        int p, max;
        while (i < count) {
            p = parent(i, count);
            if (p == -1) break;
            max = givemax(memory, i, p);
            if (max == p) break;
            swap(memory, p, i);
            i = p;
        }
    }
    T remove() {
        T data = memory[0];
        memory[0] = memory[count - 1];
        count --;
        percolateDown(0);
        return data;
    }
    void heapSort()
    {
        for (int i = 0; i < count; i++)
        {
            percolateUp(i);
            showmem();
        }
    }
};
