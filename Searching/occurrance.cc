#include "iostream"
using namespace std;

int firstOccurrance_(int A[], int low, int high, int data) {
    if (low > high) return -1;
    if (low == high) return ((A[low] == data) ? low : -1);
    int mid = (low + high)/2;
    if (mid == low){
        // This case is true if there are two elements in the array
        if (A[low] == data) return low;
        if (A[high] == data) return high;
        return -1;
    }
    if (A[mid] == data && A[mid-1] < data) return mid;
    if (data <= A[mid]) return firstOccurrance_(A, low, mid-1, data);
    return firstOccurrance_(A, mid+1, high, data);
}
/*
 * Finds the First Occurrance of a number.
 */
 int firstOccurrance(int A[], int len, int data) {
     if (len <= 0) return -1;
     if (len == 1) return ((A[0] == data) ? 0 : -1);
     return (firstOccurrance_(A, 0, len-1, data));
 }
int main() {
    int A[11] = {0,1,1,1,2,2,2,2,3,3,4};
    cout<<"Array: ";
    for (int i = 0; i < 10; i++) std::cout << A[i] <<" ";
    cout<<endl;
    cout<<"First Occurrance of 0 - "<<firstOccurrance(A, 11, 0)<<endl;
    cout<<"First Occurrance of 1 - "<<firstOccurrance(A, 11, 1)<<endl;
    cout<<"First Occurrance of 2 - "<<firstOccurrance(A, 11, 2)<<endl;
    cout<<"First Occurrance of 3 - "<<firstOccurrance(A, 11, 3)<<endl;
    cout<<"First Occurrance of 4 - "<<firstOccurrance(A, 11, 4)<<endl;
    cout<<"First Occurrance of 5 - "<<firstOccurrance(A, 11, 5)<<endl;
    return 0;
}
