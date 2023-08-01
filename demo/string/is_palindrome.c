#include "stdio.h"
#include "string.h"
#include "stdbool.h"

/* https://leetcode.cn/problems/valid-palindrome/ */

bool IsLegalCharater(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z')) {
        return true;
    }
    return false;
}

char ConvertUpper2Lower(char c) {
    if ((c >= 'A') && (c <= 'Z')) {
        return c + 32;
    }
    return c;
}

bool isPalindrome(char * s){
    if (s == NULL || strlen(s) == 0) {
        return true;
    }

    int ls = strlen(s);
    int left = 0, right = ls - 1;

    while (left < right) {
        while (left < right && !IsLegalCharater(s[left])) {
            left++;
        }
        while (left < right && !IsLegalCharater(s[right])) {
            right--;
        }
        if (ConvertUpper2Lower(s[left]) != ConvertUpper2Lower(s[right])) {
            printf("left=%d, right=%d\n", left, right);
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void isPalindromeTest(void)
{
    char s[] = "A man, a plan, a canal: Panama";

    bool ans = isPalindrome(s);

    printf("output: ans=%d\n", ans);
}
