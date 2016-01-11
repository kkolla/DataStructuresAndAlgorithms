#include "strings.h"
void printInterleave_(char *s1, int m,char *s2, int n, char *output, int i) {
    if (m == 0 || n == 0) {
        cout<<output;
        if (m == 0) {
            cout<<s2<<endl;
        } else if (n == 0){
            cout<<s1<<endl;
        }
        return;
    }
    output[i] = s1[0];
    printInterleave_(s1+1, m-1, s2, n, output, i+1);

    output[i] = s2[0];
    printInterleave_(s1, m, s2+1, n-1, output, i+1);
}

void printInterleave(char *s1, char *s2)
{
    if (s1 == NULL && s2 == NULL) return;
    if (s1 == NULL || s2 == NULL) {
        if (s1 == NULL) {
            cout<<s2;
        } else {
            cout<<s1;
        }
    }
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    char *output = new char[l1+l2];
    printInterleave_(s1, strlen(s1), s2, strlen(s2), output, 0);
}
