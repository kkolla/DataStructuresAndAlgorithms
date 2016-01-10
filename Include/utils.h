#include <iostream>
template <class T>
void showArray(T array[], int n) {
    std::cout<<"Displaying Array\n";
    for (int i = 0; i < n; i++) std::cout<<array[i]<<" ";
    std::cout<<std::endl;
}
/*
 * Given an array str, this api swaps values at indices l1 and l2
 */
inline void swap(char *str, int l1, int l2) {
    char ch = str[l1];
    str[l1] = str[l2];
    str[l2] = ch;
}
