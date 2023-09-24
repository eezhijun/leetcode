/**
 * @file lc_string_easy.c
 * @author eehongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-09-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdlib.h"

#include "uthash.h"
#include "utils.h"

/* https://leetcode.cn/problems/reverse-string-ii/ */
/* 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。


示例 1：

输入：s = "abcdefg", k = 2
输出："bacdfeg"
示例 2：

输入：s = "abcd", k = 2
输出："bacd"


提示：

1 <= s.length <= 104
s 仅由小写英文组成
1 <= k <= 104 */
char * reverseStr(char * s, int k)
{
    size_t rlen = strlen(s);
    size_t idx = 0;

    while (rlen) {
        if (rlen < k) {
            reverse(s + idx, 0, rlen - 1);
            rlen = 0;
        } else if (rlen < 2 * k) {
            reverse(s + idx, 0, k - 1);
            rlen = 0;
        } else {
            reverse(s + idx, 0, k - 1);
            rlen -= 2 * k;
            idx += 2 * k;
        }
    }
    return s;
}

void reverseStrTest(void)
{
    char s[128];
    int k;

    /* "abcdefg" k=1 */
    printf("please input string s:\n");
    fgets(s, 128, stdin);
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
    printf("please input integer k:\n");
    scanf("%d", &k);

    char *ret = reverseStr(s, k);
    printf("output=%s\n", ret);
}

/* https://leetcode.cn/problems/longest-uncommon-subsequence-i/ */
/* 给你两个字符串 a 和 b，请返回 这两个字符串中 最长的特殊序列  的长度。如果不存在，则返回 -1 。

「最长特殊序列」 定义如下：该序列为 某字符串独有的最长子序列（即不能是其他字符串的子序列） 。

字符串 s 的子序列是在从 s 中删除任意数量的字符后可以获得的字符串。

例如，"abc" 是 "aebdc" 的子序列，因为删除 "aebdc" 中斜体加粗的字符可以得到 "abc" 。 "aebdc" 的子序列还包括 "aebdc" 、 "aeb" 和 "" (空字符串)。


示例 1：

输入: a = "aba", b = "cdc"
输出: 3
解释: 最长特殊序列可为 "aba" (或 "cdc")，两者均为自身的子序列且不是对方的子序列。
示例 2：

输入：a = "aaa", b = "bbb"
输出：3
解释: 最长特殊序列是 "aaa" 和 "bbb" 。
示例 3：

输入：a = "aaa", b = "aaa"
输出：-1
解释: 字符串 a 的每个子序列也是字符串 b 的每个子序列。同样，字符串 b 的每个子序列也是字符串 a 的子序列。


提示：

1 <= a.length, b.length <= 100
a 和 b 由小写英文字母组成 */

int findLUSlength(char * a, char * b)
{
#if defined(WAY1)
    size_t la = strlen(a);
    size_t lb = strlen(b);
    int max_len = -1;

    if (la != lb) {
        return ((la > lb) ? la : lb);
    }

    for (int i = la; i >= 0; i--) {
        if (strncmp(a, b, i)) {
            return i;
        }
    }
    return max_len;
#else
    int lena = strlen(a);
    int lenb = strlen(b);
    return strcmp(a, b) != 0 ? MAX(lena, lenb) : -1;
#endif
}

void findLUSlengthTest(void)
{
    char a[128] = {0};
    char b[128] = {0};

    /*"aaaabcd" "aaaaacd"*/
    printf("please input string a:\n");
    scanf("%s", a);
    printf("please input string b:\n");
    scanf("%s", b);

    int ret = findLUSlength(a, b);

    printf("output:%d\n", ret);
}

/* https://leetcode.cn/problems/detect-capital/ */
/* 我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如 "USA" 。
单词中所有字母都不是大写，比如 "leetcode" 。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。

示例 1：

输入：word = "USA"
输出：true
示例 2：

输入：word = "FlaG"
输出：false


提示：

1 <= word.length <= 100
word 由小写和大写英文字母组成 */
bool detectCapitalUse(char * word)
{
    int i;
    int flag1 = 0, flag2 = 0;
    for (i = 0; word[i] != '\0'; i++) {
        if (flag1 == 1) {
            if (flag2 == 1) {
                if (!islower(word[i])) {
                    return false;
                }
            } else if (i == 1 && islower(word[i])) {
                flag2 = 1;
            } else if (islower(word[i])) {
                return false;
            }
        } else if (i == 0 && isupper(word[i])) {
            flag1 = 1;
        } else if (!islower(word[i])) {
            return false;
        }
    }
    return true;
}

void detectCapitalUseTest(void)
{
    char word[128] = {0};

    printf("please input string word by scanf:\n");
    scanf("%s", word);

    (detectCapitalUse(word) == true) ? printf("output:true\n") : printf("output:false\n");

}

/* https://leetcode.cn/problems/keyboard-row/ */
/* 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

美式键盘 中：

第一行由字符 "qwertyuiop" 组成。
第二行由字符 "asdfghjkl" 组成。
第三行由字符 "zxcvbnm" 组成。
American keyboard

示例 1：

输入：words = ["Hello","Alaska","Dad","Peace"]
输出：["Alaska","Dad"]
示例 2：

输入：words = ["omk"]
输出：[]
示例 3：

输入：words = ["adsdf","sfd"]
输出：["adsdf","sfd"]


提示：

1 <= words.length <= 20
1 <= words[i].length <= 100
wordis_keyboard_row_wordss[i] 由英文字母（小写和大写字母）组成
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool is_keyboard_row_words(char *s)
{
    char *table[] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
    size_t len = ARRAY_SIZE(table);
    size_t lt[len];
    size_t ls = strlen(s);
    int i, j;
    int row = 0;
    bool is_found = false;

    for (i = 0; i < len; i++) {
        lt[i] = strlen(table[i]);
    }

    for (i = 0; i < ls; i++) {

        if (row == 0 || row == 1) {
            for (j = 0; j < lt[0]; j++) {
                if (s[i] == table[0][j]) {
                    row = 1;
                    is_found = true;
                    break;
                }
            }
        }

        if (row == 0 || row == 2) {
            for (j = 0; j < lt[1]; j++) {
                if (s[i] == table[1][j]) {
                    row = 2;
                    is_found = true;
                    break;
                }
            }
        }

        if (row == 0 || row == 3) {
            for (j = 0; j < lt[2]; j++) {
                if (s[i] == table[2][j]) {
                    row = 3;
                    is_found = true;
                    break;
                }
            }
        }

        if (!is_found) {
            return false;
        }
        is_found = false;
    }
    return true;
}

char ** findWords(char ** words, int wordsSize, int* returnSize)
{
    char **ret = (char **)malloc(sizeof(char *) * wordsSize);
    memset(ret, 0, sizeof(char *) * wordsSize);

    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (is_keyboard_row_words(words[i])) {
            size_t len = strlen(words[i]) + 1;
            ret[*returnSize] = (char *)malloc(len);
            strncpy(ret[*returnSize], words[i], len);
            (*returnSize)++;
        }
    }

    return ret;
}

#define STR0 "Hello","Alaska","Dad","Peace"
#define STR1 "omk"
#define STR2 "adsdf","sfd"
void findWordsTest(void)
{
    char *s[] = {STR2};

    size_t len = ARRAY_SIZE(s);
    int return_size = 0;

    char buf[100] = {0};

    strncpy(buf, s[0], 3);
    PRINT_ARRAY(buf, 10, "%d ");

    printf("iuput:\n");
    PRINT_ARRAY(s, len, "%s ");

    char **ret = findWords(s, len, &return_size);

    PRINT_ARRAY(ret, return_size, "%s ");

    for (int i = 0; i < return_size; i++) {
        free(ret[i]);
        ret[i] = NULL;
    }
    free(ret);
    ret = NULL;
}

/* https://leetcode.cn/problems/license-key-formatting/ */
/* 给定一个许可密钥字符串 s，仅由字母、数字字符和破折号组成。字符串由 n 个破折号分成 n + 1 组。你也会得到一个整数 k 。

我们想要重新格式化字符串 s，使每一组包含 k 个字符，除了第一组，它可以比 k 短，但仍然必须包含至少一个字符。
此外，两组之间必须插入破折号，并且应该将所有小写字母转换为大写字母。

返回 重新格式化的许可密钥 。

示例 1：

输入：S = "5F3Z-2e-9-w", k = 4
输出："5F3Z-2E9W"
解释：字符串 S 被分成了两个部分，每部分 4 个字符；
     注意，两个额外的破折号需要删掉。
示例 2：

输入：S = "2-5g-3-J", k = 2
输出："2-5G-3J"
解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。


提示:

1 <= s.length <= 105
s 只包含字母、数字和破折号 '-'.
1 <= k <= 104 */
/* "2-4A0r7-4k" k=4 k=3 "--a-a-a-a--" k=2 "0123456789" k=1*/
char * licenseKeyFormatting(char * s, int k)
{
    size_t len = strlen(s);

    char *ret = (char *)malloc(sizeof(char) * (len * 2));
    memset(ret, 0, sizeof(char) * (len * 2));

    int i = len - 1, j = 0;
    int idx = 0;
    int cnt = 0;

    for (; s[j] == '-'; j++);
    for (; i >= j; i--) {
        if (s[i] != '-') {
            ret[idx++] = s[i];
            cnt++;
            if (cnt % k == 0 && i != j) {
                ret[idx++] = '-';
            }
        }
    }
    reverse(ret, 0, idx - 1);

    for (i = 0; i < idx; i++) {
        ret[i] = toupper(ret[i]);
    }

    return ret;
}

void licenseKeyFormattingTest(void)
{
    char s[128];
    int k;

    printf("please input string s:\n");
    fgets(s, 128, stdin);

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    printf("please input integer k:\n");
    scanf("%d", &k);

    char *ret = licenseKeyFormatting(s, k);

    printf("output:%s\n", ret);
    free(ret);
    ret = NULL;
}

/* https://leetcode.cn/problems/repeated-substring-pattern/ */
/* 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。



示例 1:

输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。
示例 2:

输入: s = "aba"
输出: false
示例 3:

输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)


提示：

1 <= s.length <= 104
s 由小写英文字母组成 */
bool repeatedSubstringPattern(char * s)
{

}

void repeatedSubstringPatternTest(void)
{
    char s[128];

    printf("please input string s:\n");
    fgets(s, 128, stdin);

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    bool ret = repeatedSubstringPattern(s);

    (ret == true) ? printf("output:true\n") : printf("output:false\n");
}

/* https://leetcode.cn/problems/number-of-segments-in-a-string/ */
/* 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。*/
/* 全是空格 */
int countSegments(char * s)
{
#if 0
    size_t len = strlen(s);
    if (s == NULL || len == 0) {
        return 0;
    }

    int l = 0, r = len - 1;
    int cnt = 0;
    bool is_space = false;
    while (s[l] == ' ') { /* 前导空格 */
        l++;
    }

    while (r >= 0 && s[r] == ' ') { /* 尾随空格 */
        r--;
    }

    if (l > r) {
        return 0;
    }
    while (l < r) {
        l++;
        while (s[l] == ' ') {
            is_space = true;
            l++;
        }
        if (is_space) {
            is_space = false;
            cnt++;
        }
    }

    if (len) {
        cnt++;
    }

#else
    int cnt = 0, i, len = strlen(s);
    for(i = 0; i < len; i++) {
        if((i == 0 || s[i-1] == ' ') && s[i] != ' ')
            cnt++;
    }
#endif
    return cnt;
}

void countSegmentsTest(void)
{
    char s[128];

    printf("please input string s:\n");
    fgets(s, 128, stdin);

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    int ret = countSegments(s);

    printf("output:%d\n", ret);
}

/* https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/ */
/* 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

示例 1：

输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
示例 2：

输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。


提示：

1 <= haystack.length, needle.length <= 104
haystack 和 needle 仅由小写英文字符组成 */
int strStr(char *haystack, char *needle)
{
    int i = 0, j = 0;
    int lh = strlen(haystack);
    int ln = strlen(needle);

    while (i < lh && j < ln) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
        if (j == ln) {
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

/* https://leetcode.cn/problems/longest-common-prefix/ */
/* 编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。



示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。


提示：

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成 */
char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0) {
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
    char *s[] = { "flower", "flow", "flight" };
    int strsSize = sizeof(s) / sizeof(char *);

    printf("%d\n", strsSize);
    char *ans = longestCommonPrefix(s, strsSize);

    printf("output: ans=%s\n", ans);
    free(ans);
}

/* https://leetcode.cn/problems/valid-anagram/ */
/* 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。



示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false


提示:

1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母


进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ */
bool isAnagram(char *s, char *t)
{
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
/* 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。



示例 1：

输入: s = "leetcode"
输出: 0
示例 2:

输入: s = "loveleetcode"
输出: 2
示例 3:

输入: s = "aabb"
输出: -1


提示:

1 <= s.length <= 105
s 只包含小写字母 */
int firstUniqChar(char *s)
{
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

/* https://leetcode.cn/problems/add-binary/ */
/* 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。



示例 1：

输入:a = "11", b = "1"
输出："100"
示例 2：

输入：a = "1010", b = "1011"
输出："10101"


提示：

1 <= a.length, b.length <= 104
a 和 b 仅由字符 '0' 或 '1' 组成
字符串如果不是 "0" ，就不含前导零 */
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

/* https://leetcode.cn/problems/add-strings/ */
/* 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。



示例 1：

输入：num1 = "11", num2 = "123"
输出："134"
示例 2：

输入：num1 = "456", num2 = "77"
输出："533"
示例 3：

输入：num1 = "0", num2 = "0"
输出："0"

提示：

1 <= num1.length, num2.length <= 104
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零 */

char *addStrings(char *num1, char *num2)
{
    int n = string2int(num1) + string2int(num2);

    size_t size = COUNT_DIGITS(n);

    char *s = (char *)malloc(sizeof(char) * (size + 1));
    memset(s, 0, sizeof(char) * (size + 1));

    sprintf(s, "%d", n);

    return s;
}

void addStringsTest(void)
{
    char num1[128], num2[128];

    printf("please input string num1 and num2:\n");
    scanf("%s\n%s", num1, num2);

    char *ret = addStrings(num1, num2);

    printf("output:%s\n", ret);
    free(ret);
    ret = NULL;
}

/* https://leetcode.cn/problems/fizz-buzz/ */
/* 给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：

answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
answer[i] == "Fizz" 如果 i 是 3 的倍数。
answer[i] == "Buzz" 如果 i 是 5 的倍数。
answer[i] == i （以字符串形式）如果上述条件全不满足。


示例 1：

输入：n = 3
输出：["1","2","Fizz"]
示例 2：

输入：n = 5
输出：["1","2","Fizz","4","Buzz"]
示例 3：

输入：n = 15
输出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]


提示：

1 <= n <= 104 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize)
{
    int i;
    int size = 0;

    char **s = (char **)malloc(sizeof(char *) * n);
    if (s == NULL) {
        return NULL;
    }
    memset(s, 0, sizeof(char *) * n);
    *returnSize = n;

#if defined(WAY1)
    for (i = 0; i < n; i++) {
        s[i] = (char *)malloc(sizeof(char) * 9);
        memset(s[i], 0, sizeof(char) * 9);
    }

    for (i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            strcpy(s[i - 1], "FizzBuzz");
        } else if (i % 3 == 0) {
            strcpy(s[i - 1], "Fizz");
        } else if (i % 5 == 0) {
            strcpy(s[i - 1], "Buzz");
        } else {
            sprintf(s[i - 1], "%d", i);
        }
    }
#else
    for (i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            s[i - 1] = (char *)malloc(sizeof(char) * 9);
            strncpy(s[i - 1], "FizzBuzz", 9);
        } else if (i % 3 == 0) {
            s[i - 1] = (char *)malloc(sizeof(char) * 5);
            strncpy(s[i - 1], "Fizz", 5);
        } else if (i % 5 == 0) {
            s[i - 1] = (char *)malloc(sizeof(char) * 5);
            strncpy(s[i - 1], "Buzz", 5);
        } else {
            size = COUNT_DIGITS(i);
            s[i - 1] = (char *)malloc(sizeof(char) * (size + 1));
            sprintf(s[i - 1], "%d", i);
        }
    }
#endif
    return s;
}

void fizzBuzzTest(void)
{
    int n;
    int returnSize = 0;

    printf("please input integer:\n");
    scanf("%d", &n);

    char **ret = fizzBuzz(n, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s ", ret[i]);
    }

    for (int i = 0; i < returnSize; i++) {
        free(ret[i]);
        ret[i] = NULL;
    }

    free(ret);
    ret = NULL;
}

/* https://leetcode.cn/problems/longest-palindrome/ */
/* 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。

在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。



示例 1:

输入:s = "abccccdd"
输出:7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
示例 2:

输入:s = "a"
输出:1
示例 3：

输入:s = "aaaaaccc"
输出:7


提示:

1 <= s.length <= 2000
s 只由小写 和/或 大写英文字母组成 */
int longestPalindromex(char *s)
{
}

void longestPalindromexTest(void)
{
}

/* https://leetcode.cn/problems/longest-palindromic-substring/ */
/* 给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。



示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"


提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成 */
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

char *longestPalindrome(char *s)
{
    int len = strlen(s);
    int i, j;
    for (i = len; i > 0; i--) {
        for (j = 0; j <= len - i; j++) {
            if (IsPalindrome(s, j, i + j - 1)) {
                char *ans = (char *)malloc(sizeof(char) *
                                           (i + 1)); // +1预留字符串末尾字符'\0'
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

/* https://leetcode.cn/problems/valid-palindrome/ */
/* 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。



示例 1：

输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。
示例 2：

输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。
示例 3：

输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。


提示：

1 <= s.length <= 2 * 105
s 仅由可打印的 ASCII 字符组成 */

bool IsLegalCharater(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
        return true;
    }
    return false;
}

bool isPalindrome(char *s)
{
    int ls = strlen(s);
    int left = 0, right = ls - 1;

    while (left < right) {
        while (left < right && !IsLegalCharater(s[left])) {
            left++;
        }
        while (left < right && !IsLegalCharater(s[right])) {
            right--;
        }
        if (tolower(s[left]) != tolower(s[right])) {
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

    (ans == true) ? printf("output:true\n") : printf("output:false\n");
}

/* https://leetcode.cn/problems/is-subsequence/ */
/* 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：

特别感谢 @pbrother 添加此问题并且创建所有测试用例。



示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false


提示：

0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。*/
bool isSubsequence(char *s, char *t)
{
    int i, j, index = 0;
    size_t lt = strlen(t);

    for (i = 0; s[i] != '\0'; i++) {
        for (j = index; t[j] != '\0'; j++) {
            if (s[i] == t[j]) {
                index = j + 1;
                break;
            }
        }
        if (j == lt) {
            return false;
        }
    }
    return true;
}

void isSubsequenceTest(void)
{
    char s[128], t[128];

    printf("please input string s and t:\n");
    scanf("%s %s", s, t);

    bool ret = isSubsequence(s, t);

    (ret == true) ? printf("output:true\n") : printf("output:false\n");
}

/* https://leetcode.cn/problems/find-the-difference/ */
/* 给定两个字符串 s 和 t ，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。



示例 1：

输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。
示例 2：

输入：s = "", t = "y"
输出："y"


提示：

0 <= s.length <= 1000
t.length == s.length + 1
s 和 t 只包含小写字母 */
#define WAYS 1
#if (WAYS == 1)
/* 计数 */
char findTheDifference(char *s, char *t)
{
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    int n = strlen(s), m = strlen(t);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < m; i++) {
        cnt[t[i] - 'a']--;
        if (cnt[t[i] - 'a'] < 0) {
            return t[i];
        }
    }
    return ' ';
}
#elif (WAYS == 2)
/* 求和 */
char findTheDifference(char *s, char *t)
{
    int n = strlen(s), m = strlen(t);
    int as = 0, at = 0;
    for (int i = 0; i < n; i++) {
        as += s[i];
    }
    for (int i = 0; i < m; i++) {
        at += t[i];
    }
    return at - as;
}
#elif (WAYS == 3)
/* 位运算 */
char findTheDifference(char *s, char *t)
{
    int n = strlen(s), m = strlen(t);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret ^= s[i];
    }
    for (int i = 0; i < m; i++) {
        ret ^= t[i];
    }
    return ret;
}
#else
char findTheDifference(char *s, char *t)
{
    int a[26] = { 0 };
    int b[26] = { 0 };
    size_t ls = strlen(s);
    size_t lt = strlen(t);

    for (int i = 0; i < ls; i++) {
        a[s[i] - 'a']++;
    }

    for (int i = 0; i < lt; i++) {
        b[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (b[i] > a[i]) {
            return i + 'a';
        }
    }

    return 0;
}
#endif

void findTheDifferenceTest(void)
{
    char s[128], t[128];
    // char s[] = "", t[] = "y";

    printf("please input string s and t\n");
    scanf("%s %s", s, t);

    char ret = findTheDifference(s, t);

    printf("output:%c\n", ret);
}

/* https://leetcode.cn/problems/ransom-note/ */
/* 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。



示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true


提示：

1 <= ransomNote.length, magazine.length <= 105
ransomNote 和 magazine 由小写英文字母组成 */
#if 1
bool canConstruct(char *ransomNote, char *magazine)
{
    int a[26] = { 0 };
    int b[26] = { 0 };
    size_t lr = strlen(ransomNote);
    size_t lm = strlen(magazine);

    for (int i = 0; i < lr; i++) {
        a[ransomNote[i] - 'a']++;
    }

    for (int i = 0; i < lm; i++) {
        b[magazine[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (a[i] > b[i]) {
            return false;
        }
    }

    return true;
}
#else
bool canConstruct(char *ransomNote, char *magazine)
{
    size_t len = strlen(magazine);
    bool is_used[len];
    bool is_found = 0;

    memset(is_used, 0, sizeof(bool) * len);

    for (int i = 0; ransomNote[i] != '\0'; i++) {
        for (int j = 0; magazine[j] != '\0'; j++) {
            if (is_used[j]) {
                continue;
            } else {
                if (ransomNote[i] == magazine[j]) {
                    is_used[j] = true;
                    is_found = true;
                    break;
                }
            }
        }

        if (!is_found) {
            return false;
        }
        is_found = false;
    }
    return true;
}
#endif

void canConstructTest(void)
{
    char s1[128], s2[128];

    printf("please string s1 and s2:\n");
    scanf("%s %s", s1, s2);

    bool ret = canConstruct(s1, s2);

    (ret == true) ? printf("output:true\n") : printf("output:false\n");
}

/* https://leetcode.cn/problems/reverse-vowels-of-a-string/ */
/* 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。



示例 1：

输入：s = "hello"
输出："holle"
示例 2：

输入：s = "leetcode"
输出："leotcede"


提示：

1 <= s.length <= 3 * 105
s 由 可打印的 ASCII 字符组成 */

bool is_vowels(char c)
{
    char s[] = "aeiouAEIOU";

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

char *reverseVowels(char *s)
{
    int l = 0, r = strlen(s) - 1;

    if (r == 1) {
        if (is_vowels(s[l]) && is_vowels(s[r])) {
            SWAP(char, &s[l], &s[r]);
        }
    }

    while (l + 1 < r) {
        while (l < r && !is_vowels(s[l])) {
            l++;
        }

        while (r > l && !is_vowels(s[r])) {
            r--;
        }

        SWAP(char, &s[l], &s[r]);
        l++;
        r--;
    }

    return s;
}

void reverseVowelsTest(void)
{
    char s[128];

    printf("please input string:\n");
    scanf("%s", s);

    char *ret = reverseVowels(s);

    printf("output:%s\n", ret);
}

/* https://leetcode.cn/problems/reverse-words-in-a-string/ */
/* 给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。



示例 1：

输入：s = "the sky is blue"
输出："blue is sky the"
示例 2：

输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。
示例 3：

输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。


提示：

1 <= s.length <= 104
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词


进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。*/
char *reverseWords(char *s)
{
    int l = 0, t = 0, r = strlen(s) - 1;
    int offset = 0;
    char *ans = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    if (ans == NULL) {
        printf("ans malloc fail\n");
        return NULL;
    }
    memset(ans, 0, sizeof(char) * (strlen(s) + 1));

    while (s[l] == ' ') {
        l++;
    }

    while (s[r] == ' ') {
        r--;
    }

    t = l;
    while (1) {
        while (t <= r && s[t + 1] != ' ' && s[t + 1] != '\0') {
            t++;
        }
        memcpy(ans + offset, s + l, (t - l + 1));
        reverse(ans, offset, offset + (t - l));
        *(ans + offset + (t - l + 1)) = ' ';
        offset += (t - l + 1) + 1;
        if (t < r) {
            l = t + 1;
            while (s[l] == ' ') {
                l++;
            }
            t = l;
        } else {
            break;
        }
    }
    ans[offset - 1] = '\0';
    reverse(ans, 0, offset - 2);
    return ans;
}

void reverseWordsTest(void)
{
    char s[] = "the sky is blue";

    printf("input:%s\n", s);
    char *ans = reverseWords(s);

    printf("output:%s\n", ans);
    free(ans);
}

/* https://leetcode.cn/problems/reverse-words-in-a-string-iii/ */
/* 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。



示例 1：

输入：s = "Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
示例 2:

输入： s = "God Ding"
输出："doG gniD"


提示：

1 <= s.length <= 5 * 104
s 包含可打印的 ASCII 字符。
s 不包含任何开头或结尾空格。
s 里 至少 有一个词。
s 中的所有单词都用一个空格隔开。*/
char *reverseWords3(char *s)
{
    int len = strlen(s);
    int l = 0, r = 0;

    for (int i = 0; i < len + 1; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            r = i - 1;
            reverse(s, l, r);
            l = i + 1;
        }
    }
    return s;
}

void reverseWordsTest3(void)
{
    char s[] = "Let's take LeetCode contest";

    printf("input:%s\n", s);
    char *ans = reverseWords3(s);

    printf("output:%s\n", ans);
}

/* https://leetcode.cn/problems/reverse-string/ */
/* 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。



示例 1：

输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
示例 2：

输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]


提示：

1 <= s.length <= 105
s[i] 都是 ASCII 码表中的可打印字符 */
void reverseString(char *s, int sSize)
{
    int l = 0, r = sSize - 1;
    reverse(s, l, r);
}

void reverseStringTest(void)
{
    char s[] = "hello";
    int sSize = strlen(s);

    printf("input:%s, %d\n", s, sSize);
    reverseString(s, sSize);

    printf("output:%s\n", s);
}

/* https://leetcode.cn/problems/word-pattern/ */
/* 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。



示例1:

输入: pattern = "abba", s = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", s = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", s = "dog cat cat dog"
输出: false


提示:

1 <= pattern.length <= 300
pattern 只包含小写英文字母
1 <= s.length <= 3000
s 只包含小写英文字母和 ' '
s 不包含 任何前导或尾随对空格
s 中每个单词都被 单个空格 分隔 */

/* abac dog cat dog cat */
bool wordPattern(char *pattern, char *s)
{
    char *hash_set_str[26]; //字母映射字符串

    memset(hash_set_str, 0, sizeof(char *) * 26);

    const char target[2] = " ";
    int len = strlen(pattern);
    char *token = NULL;
    for (int i = 0; i < len; i++) {
        if (token == NULL) {
            token = strtok(s, target);
        } else {
            token = strtok(NULL, target);
            if (token == NULL) {
                return false;
            }
        }

        if (hash_set_str[pattern[i] - 'a'] == NULL) {
            hash_set_str[pattern[i] - 'a'] = token;
        } else {
            if (strcmp(hash_set_str[pattern[i] - 'a'], token) != 0) {
                return false;
            }
        }
    }
    token = strtok(NULL, target);
    if (token != NULL) {
        return false;
    }

    for (int i = 0; i < 26; i++) {
        if (hash_set_str[i] != NULL) {
            for (int j = i + 1; j < 26; j++) {
                if (hash_set_str[j] != NULL) {
                    if (strcmp(hash_set_str[i], hash_set_str[j]) == 0) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

void wordPatternTest(void)
{
    char pattern[128] = { 0 };
    char s[128] = { 0 };
    int len = 0;

    printf("please input string pattern:\n");
    fgets(pattern, 128, stdin);
    len = strlen(pattern);
    if (len > 0 && pattern[len - 1] == '\n') {
        pattern[len - 1] = '\0';
    }

    printf("please input string s:\n");
    fgets(s, 128, stdin);
    len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    bool ret = wordPattern(pattern, s);

    (ret == true) ? printf("output:true\n") : printf("output:false\n");
}

/* https://leetcode.cn/problems/isomorphic-strings/ */
/* 给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，
字符可以映射到自己本身。



示例 1:

输入：s = "egg", t = "add"
输出：true
示例 2：

输入：s = "foo", t = "bar"
输出：false
示例 3：

输入：s = "paper", t = "title"
输出：true


提示：

1 <= s.length <= 5 * 104
t.length == s.length
s 和 t 由任意有效的 ASCII 字符组成 */

#if 1
struct HashTable {
    char key;
    char val;
    UT_hash_handle hh;
};

bool isIsomorphic(char *s, char *t)
{
    struct HashTable *s2t = NULL;
    struct HashTable *t2s = NULL;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        char x = s[i], y = t[i];
        struct HashTable *tmp1, *tmp2;
        HASH_FIND(hh, s2t, &x, sizeof(char), tmp1);
        HASH_FIND(hh, t2s, &y, sizeof(char), tmp2);
        if (tmp1 != NULL) {
            if (tmp1->val != y) {
                return false;
            }
        } else {
            tmp1 = malloc(sizeof(struct HashTable));
            tmp1->key = x;
            tmp1->val = y;
            HASH_ADD(hh, s2t, key, sizeof(char), tmp1);
        }
        if (tmp2 != NULL) {
            if (tmp2->val != x) {
                return false;
            }
        } else {
            tmp2 = malloc(sizeof(struct HashTable));
            tmp2->key = y;
            tmp2->val = x;
            HASH_ADD(hh, t2s, key, sizeof(char), tmp2);
        }
    }
    return true;
}
#else
bool isIsomorphic(char *s, char *t)
{
    char mapping_s2t[128] = { 0 }; /* 用于存储字符映射关系 s->t */
    char mapping_t2s[128] = { 0 }; /* 用于存储字符映射关系 t->s */

    for (int i = 0; s[i] != '\0'; i++) {
        /* check s->t */
        if (mapping_s2t[s[i]] == 0) {
            mapping_s2t[s[i]] = t[i];
        } else if (mapping_s2t[s[i]] != t[i]) {
            return false;
        }

        /* check t->s */
        if (mapping_t2s[t[i]] == 0) {
            mapping_t2s[t[i]] = s[i];
        } else if (mapping_t2s[t[i]] != s[i]) {
            return false;
        }
    }

    return true;
}
#endif

void isIsomorphicTest(void)
{
    char s[128];
    char t[128];

    printf("please input string s and t:\n");
    scanf("%s\n%s", s, t);

    bool ret = isIsomorphic(s, t);

    (ret == 1) ? printf("output:true\n") : printf("output:false\n");
}

/* https://leetcode.cn/problems/excel-sheet-column-number/ */
/* 给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回 该列名称对应的列序号 。
例如：

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

示例 1:

输入: columnTitle = "A"
输出: 1
示例 2:

输入: columnTitle = "AB"
输出: 28
示例 3:

输入: columnTitle = "ZY"
输出: 701


提示：

1 <= columnTitle.length <= 7
columnTitle 仅由大写英文组成
columnTitle 在范围 ["A", "FXSHRXW"] 内 */

int find_index_by_table(char ch)
{
    char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen(table);

    for (int i = 0; i < len; i++) {
        if (table[i] == ch) {
            return i + 1;
        }
    }
    return 0;
}

int titleToNumber(char *columnTitle)
{
    int len = strlen(columnTitle);
    int n = 0;

    for (int i = len - 1; i >= 0; i--) {
        n += find_index_by_table(columnTitle[i]) * pow(26, len - i - 1);
    }

    return n;
}

void titleToNumberTest(void)
{
    char s[] = "AAA";

    printf("input:%s\n", s);

    int ret = titleToNumber(s);

    printf("output:%d\n", ret);
}

/* https://leetcode.cn/problems/excel-sheet-column-title/ */
/* 给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
例如：

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

示例 1：

输入：columnNumber = 1
输出："A"
示例 2：

输入：columnNumber = 28
输出："AB"
示例 3：

输入：columnNumber = 701
输出："ZY"
示例 4：

输入：columnNumber = 2147483647
输出："FXSHRXW"

1 <= columnNumber <= 231 - 1 */
char *convertToTitle(int columnNumber)
{
    /*  ZY=26^1*26+26^0*25 ZZ=26^1*26+26^0*26
        26^0*1 -                26^0*26
        26^1+26^0 -             26^1*26+26^0*26
        26^2+26^1+26^0 -        26^2*26+26^1*26+26^0*26
    */
    char *table = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
    size_t size = 1;
    int n = 0, m = 0, sum = 26;

    while (columnNumber > sum) {
        size++;
        sum += pow(26, size - 1) * 26;
    }
    char *s = (char *)malloc(sizeof(char) * (size + 1));
    s[size] = '\0';

    return s;
}

void convertToTitleTest(void)
{
    int columNumber;

    printf("please input integer:\n");
    scanf("%d", &columNumber);

    char *res = convertToTitle(columNumber);

    printf("output:%s\n", res);

    free(res);
}

/* https://leetcode.cn/problems/length-of-last-word/ */
/* 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。



示例 1：

输入：s = "Hello World"
输出：5
解释：最后一个单词是“World”，长度为5。
示例 2：

输入：s = "   fly me   to   the moon  "
输出：4
解释：最后一个单词是“moon”，长度为4。
示例 3：

输入：s = "luffy is still joyboy"
输出：6
解释：最后一个单词是长度为6的“joyboy”。


提示：

1 <= s.length <= 104
s 仅有英文字母和空格 ' ' 组成
s 中至少存在一个单词 */
int lengthOfLastWord(char *s)
{
    size_t len = strlen(s);

    int n = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            n++;
        } else if (n != 0) {
            break;
        }
    }
    return n;
}

void lengthOfLastWordTest(void)
{
    char s[] = "luffy is still joyboy";

    printf("input:%s\n", s);

    int ret = lengthOfLastWord(s);

    printf("output=%d\n", ret);
}

/* https://leetcode.cn/problems/valid-parentheses/ */
/* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。


示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false


提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成 */
char pairs(char a)
{
    if (a == '}')
        return '{';
    if (a == ']')
        return '[';
    if (a == ')')
        return '(';
    return 0;
}

bool isValid(char *s)
{
    size_t len = strlen(s);

    if (len % 2 == 1) {
        return false;
    }

    int stk[len + 1], top = 0;
    for (int i = 0; i < len; i++) {
        char ch = pairs(s[i]);
        if (ch) {
            if (top == 0 || stk[top - 1] != ch) {
                return false;
            }
            top--;
        } else {
            stk[top++] = s[i];
        }
    }
    return top == 0;
}

void isValidTest(void)
{
    /*  true: ((())) ()()() ()((())) ((()))() (())))()
        false: ([)]  */
    char s[] = "((()))()";

    printf("input:%s\n", s);

    bool ret = isValid(s);
    if (ret) {
        printf("output:true\n");
    } else {
        printf("output:false\n");
    }
}

/* https://leetcode.cn/problems/roman-to-integer/ */
/* 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，
所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。



示例 1:

输入: s = "III"
输出: 3
示例 2:

输入: s = "IV"
输出: 4
示例 3:

输入: s = "IX"
输出: 9
示例 4:

输入: s = "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: s = "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.


提示：

1 <= s.length <= 15
s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
关于罗马数字的详尽书写规则，可以参考 罗马数字 - Mathematics 。*/
int romanToInt(char *s)
{
    int n = 0;
    for (int i = 0; s[i] != 0; i++) {
        switch (s[i]) {
        case 'I':
            if (s[i + 1] == 'V') {
                n += 4;
                i++;
            } else if (s[i + 1] == 'X') {
                n += 9;
                i++;
            } else {
                n += 1;
            }
            break;
        case 'V':
            n += 5;
            break;
        case 'X':
            if (s[i + 1] == 'L') {
                n += 40;
                i++;
            } else if (s[i + 1] == 'C') {
                n += 90;
                i++;
            } else {
                n += 10;
            }
            break;
        case 'L':
            n += 50;
            break;
        case 'C':
            if (s[i + 1] == 'M') {
                n += 900;
                i++;
            } else if (s[i + 1] == 'D') {
                n += 400;
                i++;
            } else {
                n += 100;
            }
            break;
        case 'D':
            n += 500;
            break;
        case 'M':
            n += 1000;
            break;
        default:
            break;
        }
    }

    return n;
}

void romanToIntTest(void)
{
    char s[] = "CMLII";

    printf("input=%s\n", s);
    int ret = romanToInt(s);
    printf("output=%d\n", ret);
}
