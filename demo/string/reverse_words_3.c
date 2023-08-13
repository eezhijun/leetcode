#include "stdio.h"
#include "string.h"
#include "utils.h"

/* https://leetcode.cn/problems/reverse-words-in-a-string-iii/ */

char * reverseWords3(char *s)
{
    if (s == NULL) {
        return NULL;
    }
    int len = strlen(s);
    int l = 0, r = 0;
    if (len == 1) {
        return s;
    }
    int i;
    for (i = 0; i < len + 1; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            r = i - 1;
            while (l < r ) {
                swap((int *)&s[l], (int *)&s[r], sizeof(char));
                l++;
                r--;
            }
            l = i + 1;
        }
    }
    return s;
}

void reverseWordsTest3(void)
{
    char s[] = "Let's take LeetCode contest";

    char *ans = reverseWords3(s);

    printf("output: ans=%s\n", ans);
}
