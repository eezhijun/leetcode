#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/* https://leetcode.cn/problems/longest-palindromic-substring/ */

bool IsPalindrome(char *s, int left, int right)
{
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

char * longestPalindrome(char * s){

    if (s == NULL) {
        return NULL;
    }
    int len = strlen(s);
    int i, j;
    for (i = len; i > 0; i--) {
        for (j = 0; j <= len - i; j++) {
            if (IsPalindrome(s, j, i + j - 1)) {
                char *ans = (char *)malloc(sizeof(char) * (i + 1)); // +1预留字符串末尾字符'\0'
                if (ans == NULL) {
                    printf("malloc fail");
                    return NULL;
                }
                memset(ans, 0, sizeof(char) * (i + 1));
                memcpy(ans, &s[j], i);
                printf("find i=%d, j=%d\n", i, j);
                return ans;
            }
        }
    }
    return NULL;

}

void longestPalindromeTest(void)
{
    char s[] = "babad";

    char *ans = longestPalindrome(s);

    printf("output: ans=%s\n", ans);
    free(ans);
}
