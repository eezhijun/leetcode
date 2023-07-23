#include "internal.h"


/* https://leetcode.cn/problems/add-binary/ */

void reverse2(char *s, int len)
{
    for (int i = 0; i < len / 2; i++) {
        char tmp = s[len - i - 1];
        s[len - i - 1] = s[i];
        s[i] = tmp;
    }
}

char * addBinary(char * a, char * b){
    int la = (int)strlen(a);
    int lb = (int)strlen(b);
    reverse2(a, la);
    reverse2(b, lb);
    int ln = (la > lb) ? (la) : (lb);
    char *res = (char *)malloc(sizeof(char) * (ln + 2));
    if (res == NULL) {
        return NULL;
    }
    memset(res, 0, sizeof(char) * (ln + 2));
    int carry = 0, len = 0;
    for (int i = 0; i < ln; i++) {
        carry += (i < la) ? (a[i] == '1') : 0;
        carry += (i < lb) ? (b[i] == '1') : 0;
        res[len] = (carry % 2) + '0';
        len++;
        carry /= 2;
    }
    if (carry) {
        res[len] = '1';
        len++;
    }
    res[len] = '\0';
    reverse2(res, strlen(res));
    return res;
}

void addBinaryTest(void)
{
    char a[] = "11";
    char b[] = "1";

    char* ans = addBinary(a, b);

    printf("output: ans=%s\n", ans);
    free(ans);
}
