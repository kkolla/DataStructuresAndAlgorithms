#include "numberAndCharecters.h"
bool isUpper(char ch){
    if (ch >= 'A' && ch <= 'Z') return true;
    return false;
}
bool isLower(char ch){
    if (ch >= 'a' && ch <= 'z') return true;
    return false;
}
char toLower(char ch){
    if (isLower(ch)) return ch;

    return ((char)(ch - 'A' + 'a'));
}
char toUpper(char ch){
    if (isUpper(ch)) return ch;
    return ((char)(ch - 'a' + 'A'));
}
int myStrCmp(const char *p, const char *q) {
    cout<<"Comparing "<<p<<" and "<<q<<endl;
    while(*p == *q) {
        if (*p == '\0') return 0;
        p++;
        q++;
    }
    int ret = (*p - *q);
    cout<<"returning :"<<ret<<endl;
    return ret;
}
void charTest_(char ch) {
    if (isUpper(ch)) {
        cout<<ch<<" is Upper, make it lower : "<<toLower(ch)<<endl;
    } else if(isLower(ch)) {
        cout<<ch<<" is Lower, make it Upper : "<<toUpper(ch)<<endl;
    } else {
        cout<<ch<<" is an invalid char "<<endl;
    }
    return;
}
void charTest()
{
    charTest_('A');
    charTest_('a');
    charTest_('1');
    charTest_('*');
    charTest_('%');
    charTest_('Z');
}
void cmpTest() {
    myStrCmp("abc", "abc") ? cout<<"not same\n" : cout<<"same\n";
    myStrCmp("abcd", "abc") ? cout<<"not same\n" : cout<<"same\n";
    myStrCmp("abcd", "ABCD") ? cout<<"not same\n" : cout<<"same\n";
    myStrCmp("d", "D") ? cout<<"not same\n" : cout<<"same\n";
}

void longestNonRepeatingCharTest() {
    cout<<longestNonRepeatingSubstring("abcd", 4)<<endl;
    cout<<longestNonRepeatingSubstring("abad", 4)<<endl;
    cout<<longestNonRepeatingSubstring("aaaa", 4)<<endl;
    cout<<longestNonRepeatingSubstring("a", 1)<<endl;
    cout<<longestNonRepeatingSubstring("", 0)<<endl;
    cout<<longestNonRepeatingSubstring("!@!@", 4)<<endl;
    cout<<longestNonRepeatingSubstring("  ", 2)<<endl;
    cout<<longestNonRepeatingSubstring(" ", 1)<<endl;
}
int main() {
    longestNonRepeatingCharTest();
    return 0;
}
