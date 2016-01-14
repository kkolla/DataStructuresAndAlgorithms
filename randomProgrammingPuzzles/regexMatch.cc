#include "puzzles.h"

/*
 * We define a single charecter match with the following criteria
 * (a, a) ==> return true
 * (a, b) ==> false
 * (anystring, .) ==>true
 * ('\0', .) ==> false
 */
bool singleMatch(const char *s, const char *r) {
    return ((*s == *r) ||
            (*r == '.' && *s !='\0')
           );
}

bool isMatch(const char* str, const char* regex)
{
    if (str == NULL || regex == NULL) return false;
    if (*regex == '\0') return (*str == '\0');

    if (*regex == '.')
    {
        if(singleMatch(str, regex) == false) return false;
        return isMatch(str+1, regex+1);
    }
    // Firstly we have a regexes [(S, S*), (Sa, S*) which is true.
    // Lets not look into this case now, but look at cases like, [(sa,s.), (aa,aa)] etc.
    if ((*(regex + 1)) != '*') {
        // If they clash at the beginning itself.
        // a, b
        if(singleMatch(str, regex) == false) return false;
        return isMatch(str+1, regex+1);
    }

    // In this case we look at baa c*c, b and c are not equal, if the second char is *
    // it should be disregarded
    if(!singleMatch(str, regex)) return false;


    // If we reach here, then we are looking at these cases
    // 1 a, a*
    // 2 aa, a*
    // 3 aaaaaa, a*
    // 4 aaaaaabbbb,a*bbbb
    // 5 bbbb, a*bbbb
    // which are true.

    // case 5
    // bb, a*bb; either you assume the first char has been eaten by *, or you dont assume it is eaten by *
    if (isMatch(str, regex+2)) return true;     // ==> * ate nothing case 5
    if (isMatch(str+1, regex)) return true;     // ==> * ate something but * is alive
    if (isMatch(str+1, regex+2)) return true;     // ==> * ate something and * perished

    return false;
}
void testRegex(const char* str, const char* regex) {
    cout<<"Result : "<<(isMatch(str,regex) ? "true" : "false");
    cout << "\tTested REGEX validation  - string: "<<str<<" Regex : "<<regex<<endl;
}
int main() {
    testRegex("aaaaaaaaaaaaab","a*a*a*a*a*a*a*a*a*a*c");
    testRegex("baa","c*c");
    testRegex("ab",".*c");
    testRegex("aaaaaaaaaaaaab","a*b");
    testRegex("aaaaaaaaaaaaab","ab");
    testRegex("aaaaaa", "a*");
    testRegex("aaaaaabbbb","a*bbbb");
    testRegex("aaaaaabbbb","a*bbb");
    testRegex("aaaaaabbcb","a*bb.b");
    testRegex("aaaaaa","a*");
    return 0;
}
