#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"

#include "utils.h"


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


/* https://leetcode.cn/problems/reverse-words-in-a-string/ */

void reverse(char* answer, int begin, int end)
{
    // 字符串反转
    while (begin + 1 <= end) {
        answer[begin] = answer[begin] ^ answer[end];
        answer[end] = answer[begin] ^ answer[end];
        answer[begin] = answer[begin] ^ answer[end];
        begin++;
        end--;
    }
}

char * reverseWords(char * s)
{
    if (s == NULL) {
        printf("s is NULL\n");
        return NULL;
    }
    // printf("strlen(s)=%d\n", strlen(s));
    // log_trace(s, strlen(s));
    int s_first = 0, s_last = 0, s_end = strlen(s) - 1;
    int a_offset = 0;
    char *answer = (char* )malloc(sizeof(char) * (strlen(s) + 1));
    if (answer == NULL) {
        printf("answer malloc fail\n");
        return NULL;
    }
    memset(answer, 0, sizeof(char) * (strlen(s) + 1));

    while (s[s_first] == ' ') {
        s_first++;
    }

    while( s[s_end] == ' ') {
        s_end--;
    }

    s_last = s_first;
    // printf("s_last=%d, s_first=%d, s_end=%d, a_offset=%d\n", s_last, s_first, s_end, a_offset);
    while (1) {
        while (s_last <= s_end && s[s_last + 1] !=' ' && s[s_last + 1] != '\0') {
            s_last++;
        }
        // printf("s_last - s_first + 1=%d\n", s_last - s_first + 1);
        memcpy(answer + a_offset, s + s_first, (s_last - s_first + 1));
        // log_trace(answer, (strlen(s) + 1));
        // return NULL;
        reverse(answer, a_offset, a_offset + (s_last - s_first));
        *(answer + a_offset + (s_last - s_first + 1)) = ' ';
        a_offset += (s_last - s_first + 1) + 1;
        if (s_last < s_end) {
            s_first = s_last + 1;
            while (s[s_first] == ' ') {
                s_first++;
            }
            s_last = s_first;
        } else {
            break;
        }
    }
    answer[a_offset - 1] = '\0';
    reverse(answer, 0, a_offset - 2);
    return answer;
}

void reverseWordsTest(void)
{
    char s[] = "the sky is blue";

    char *ans = reverseWords(s);

    printf("output: ans=%s\n", ans);

}

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

/* https://leetcode.cn/problems/valid-anagram/ */

bool isAnagram(char * s, char * t){
    if (s == NULL || t == NULL) {
        return false;
    }

    int *ss = (int *)malloc(sizeof(int) * 26);
    memset(ss, 0, sizeof(int) * 26);

    int i;
    int ls = strlen(s);
    int lt = strlen(t);
    int count = 0;

    if (ls != lt) {
        return false;
    }
    for (i = 0; i < ls; i++) {
        ss[s[i] - 'a']++;
        ss[t[i] - 'a']--;
    }
    for (i = 0; i < 26; i++) {
        if (ss[i] != 0) {
            count++;
        }
    }
    return (count == 0) ? true : false;

}

void isAnagramTest(void)
{
    char s[] = "anagram";
    char t[] = "nagaram";

    bool ans = isAnagram(s, t);

    printf("output: ans=%d\n", ans);
}

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

/* https://leetcode.cn/problems/add-binary/ */

void reverse2(char *s, int len)
{
    for (int i = 0; i < len / 2; i++) {
        char tmp = s[len - i - 1];
        s[len - i - 1] = s[i];
        s[i] = tmp;
    }
}

char *addBinary(char *a, char *b)
{
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

    char *ans = addBinary(a, b);

    printf("output: ans=%s\n", ans);
    free(ans);
}
