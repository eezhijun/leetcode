#include "internal.h"

/* https://leetcode.cn/problems/count-and-say/ */

char * countAndSay(int n){
    if (n == 1) {
        return "1";
    }

    char *s = countAndSay(n - 1);
    char *ans = (char *)malloc(5000);
    int cnt = 1, idx = 0;
    while (*s != 0) {
        if (*s == *(s + 1)) {
            cnt++;
        } else {
            ans[idx++] = cnt + '0';
            ans[idx++] = *s;
            cnt = 1;
        }
        s++;
    }
    ans[idx] = 0;

    return ans;
}

void countAndSayTest(void)
{
    int n = 4;

    char *ans = countAndSay(n);

    printf("output: ans=%s\n", ans);
    free(ans);
}
