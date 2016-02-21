/*
 * Sample program to see how mapOsMaps would work
 */
#include <iostream>
#include <map>
using namespace std;
map<int, map<int, int> > Storage;
int main() {
    std::map<int, char> myMap;
    myMap[1] = 'C';
    myMap[2] = 'D';
    for ( int i = 1; i <= 5; i++) {
        if(myMap[i] != 0) {
            cout<<" myMap["<<i<<"] = "<<myMap[i]<<endl;
        } else {
            cout<<" empMap["<<i<<"] = "<<myMap[i]<<endl;
        }
    }
    Storage[1][1] = 2;
    Storage[1][2] = 3;
    Storage[1][3] = 4;
    Storage[1][4] = 5;
    Storage[1][5] = 6;
    cout<<"Storage[1][1] = "<<Storage[1][1]<<endl;
    cout<<"Storage[1][2] = "<<Storage[1][2]<<endl;
    cout<<"Storage[1][3] = "<<Storage[1][3]<<endl;
    cout<<"Storage[1][4] = "<<Storage[1][4]<<endl;
    cout<<"Storage[1][5] = "<<Storage[1][5]<<endl;
    cout<<"Storage[1][6] = "<<Storage[1][6]<<endl;
    return 0;
}
