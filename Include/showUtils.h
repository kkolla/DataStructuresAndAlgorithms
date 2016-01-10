#include <iostream>
template <class T>
void showArray(T array[], int n) {
    std::cout<<"Displaying Array\n";
    for (int i = 0; i < n; i++) std::cout<<array[i]<<" ";
    std::cout<<std::endl;
}
