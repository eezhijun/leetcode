#include "common.h"

/* https://leetcode.cn/problems/string-to-integer-atoi/ */

int myAtoi(char * s){
    if (s == NULL) {
        return 0;
    }

    int i;
    int len = strlen(s);
    double ans = 0;
    int sign = 1; // 默认为正
    bool flag = true;

    for (i = 0; i < len; i++) {
        if (flag && s[i] == ' ') {
            continue;
        }
        if (flag && s[i] == '+') {
            sign = 1;
            flag = false;
            continue;
        }
        if (flag && s[i] == '-') {
            sign = -1;
            flag = false;
            continue;
        }
        if (s[i] < '0' || s[i] > '9') {
            break;
        } else {
            flag = false;
            ans = ans * 10 + s[i] - '0';
        }
    }
    ans = sign * ans;
    if (ans <= -pow(2, 31)) {
        ans = -pow(2, 31);
    } else if (ans >= pow(2, 31) - 1) {
        ans = pow(2, 31) - 1;
    }
    return (int)ans;
}

void myAtoiTest(void)
{
    char s[] = "42";

    int ans = myAtoi(s);

    printf("output: ans=%d\n", ans);
}
