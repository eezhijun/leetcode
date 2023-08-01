#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* https://leetcode.cn/problems/first-unique-character-in-a-string/ */

int firstUniqChar(char * s){
    int *st = (int *)malloc(sizeof(int) * 26);
    memset(st, 0, sizeof(int) * 26);
    int i;
    int len = strlen(s);

    for (i = 0; i < len; i++) {
        st[s[i] - 'a']++;
    }
    for (i = 0; i < len; i++) {
        if (st[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

void firstUniqCharTest(void)
{
    char s[] = "loveleetcode";

    int ans = firstUniqChar(s);

    printf("output: ans=%d\n", ans);
}
