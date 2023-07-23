#include "internal.h"

/* https://leetcode.cn/problems/reverse-string/ */


/*
    1 =< s.length <= 10^5
    s[i]都是ASCII码可打印字符
*/
void reverseString(char *s, int sSize)
{
    if (s == NULL) {
        printf("s is NULL\n");
        return;
    }
    uint16_t l = 0, r = sSize - 1;
    while (l < r) {
        // printf("l=%d, r=%d\n", l, r);
        swap((int *)&s[l], (int *)&s[r], sizeof(char));
        l++;
        r--;
    }

}

void reverseStringTest(void)
{
    char s[] = "hello";
    int sSize = strlen(s);

    reverseString(s, sSize);

    printf("output: s=%s\n", s);
}
