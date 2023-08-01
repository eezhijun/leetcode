#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/* https://leetcode.cn/problems/longest-common-prefix/ */


char *longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0 || strs == NULL) {
        return "";
    }

    char cmp;
    bool ifNeed = true;
    int i;
    for (i = 0; ifNeed && strs[0][i] != '\0'; i++) {
        cmp = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != cmp) {
                ifNeed = false;
                i--;
                break;
            }
        }
    }
    char *ret;
    ret = (char *)malloc(sizeof(char) * (i + 1));
    memcpy(ret, strs[0], i);
    ret[i] = '\0';
    return ret;
}

void longestCommonPrefixTest(void)
{
    char *s[] = {"flower","flow","flight"};
    int strsSize = sizeof(s) / sizeof(char *);

    printf("%d\n", strsSize);
    char *ans = longestCommonPrefix(s, strsSize);

    printf("output: ans=%s\n", ans);
    free(ans);
}
