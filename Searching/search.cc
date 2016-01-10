#include "search.h"

/*
 * Finds the majority number.
 */
int main() {
    int majNum[7] = {1,2,3,4,4,4,4};
    cout<<"Majority num: "<<majorityNum(majNum, 7)<<endl;
    int DNF[35] = {0,0,1,0,2,0,1,0,2,0,1,0,1,0,2,0,2,0,1,0,1,0,1,1,0,2,2,0,2,2,0,2,0,2,2};
    dutchNationalFlag(DNF, 35);
    return 0;
}
