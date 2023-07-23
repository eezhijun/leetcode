#include "internal.h"

/* https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/ */

int strStr(char * haystack, char * needle){
    if (needle == NULL) {
        return 0;
    }
    if (haystack == NULL) {
        return -1;
    }
    int i = 0, j = 0;
    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    while (i < hLen && j < nLen) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
        if (j == nLen) {
            return i - j;
        }
    }
    return -1;
}

void strStrTest(void)
{
    char haystack[] = "sadbutsad";
    char needle[] = "sad";

    int ans = strStr(haystack, needle);

    printf("output: ans=%d\n", ans);
}
