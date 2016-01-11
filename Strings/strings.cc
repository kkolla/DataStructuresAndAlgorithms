#include "strings.h"
/*
 * Given a c++ string, allocate memory and return a C style string.
 * The Caller is responsible to free the memory allocated.
 */
char* getCStyleString(std::string str) {
    int len = str.length();
    char *test = new char[len];
    memset(test,'\0',len);
    strncpy (test, str.c_str(),len);
    return test;
}

void testRemoveDuplicates()
{
    string str = "Hellooipipipipipipipipipipipipipipipipipipipipipipipipipipipiipippiipippipiipipipippipim";
    cout<<removeDuplicates(str)<<endl;
    str = "ii";
    cout<<removeDuplicates(str)<<endl;
    str = "o";
    cout<<removeDuplicates(str)<<endl;
}
void testPermutations(/* arguments */) {
    auto string testString = "abcd";
    char *test = getCStyleString(testString);
    std::cout << "Permutations of : "<< test << std::endl;
    permutations(test);
    free(test);
}
void testCombinations()
{
    auto string testString = "abc";
    char *test = getCStyleString(testString);
    std::cout << "Combinations of : "<< test << std::endl;
    combinations(test);
    free(test);
}
void testInterleave()
{
    auto string s1 = "ab";
    auto string s2 = "cd";
    char *testS1 = getCStyleString(s1);
    char *testS2 = getCStyleString(s2);
    std::cout << "Interleaved strings of : "<< s1 <<" "<< s2 << std::endl;
    printInterleave(testS1,testS2);
    free(testS1);
    free(testS2);
}
int main() {
    //testPermutations();
    //testCombinations();
    testInterleave();
    return 0;
}
