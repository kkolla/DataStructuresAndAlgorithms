#include <iostream>
#include <queue>          // std::queue
#include <algorithm>    // std::max
#include <unistd.h>
using namespace std;
int majorityNum(int array[], int len);
int dutchNationalFlag(int array[], int len);
template <class T>
void showArray(T array[], int n) {
    cout<<"Displaying Array\n";
    for (int i = 0; i < n; i++) cout<<array[i]<<" ";
    cout<<endl;
}
