#include "numberAndCharecters.h"

int longestNonRepeatingSubstring(const char *string, int len) {
    bitset<256> TABLE;
    TABLE.reset();
    int i = 0, j = 0, longest = INT_MIN;
    cout<<"Length of Longest nonrepeating string in "<<string<<" is ";
    if (len == 0) return 0;
    while (i < len) {
        unsigned int index = (unsigned int) string[i];
        if (!TABLE.test(index)) {
            // Not set, continue.
            TABLE.set(index);
            i++;
        } else {
            longest = max(longest, i - j);
            while (i != j) {
                index = (unsigned int) string[j];
                TABLE.reset(index);
                j++;
            }
        }
    }
    return max(longest, i - j);
}
