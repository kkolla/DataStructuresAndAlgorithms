#include "strings.h"

int main() {
    string str = "Hellooipipipipipipipipipipipipipipipipipipipipipipipipipipipiipippiipippipiipipipippipim";
    cout<<removeDuplicates(str)<<endl;
    str = "ii";
    cout<<removeDuplicates(str)<<endl;
    str = "o";
    cout<<removeDuplicates(str)<<endl;
    return 0;
}
