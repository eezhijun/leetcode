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

#include "utils.h"


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
char * reverseVowels(char * s)
{

}

void reverseVowelsTest(void)
{

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
char * reverseWords(char * s)
{
    int l = 0, t = 0, r = strlen(s) - 1;
    int offset = 0;
    char *ans = (char* )malloc(sizeof(char) * (strlen(s) + 1));
    if (ans == NULL) {
        printf("ans malloc fail\n");
        return NULL;
    }
    memset(ans, 0, sizeof(char) * (strlen(s) + 1));

    while (s[l] == ' ') {
        l++;
    }

    while( s[r] == ' ') {
        r--;
    }

    t = l;
    while (1) {
        while (t <= r && s[t + 1] !=' ' && s[t + 1] != '\0') {
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
char * reverseWords3(char *s)
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
bool wordPattern(char *pattern, char *s)
{
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
bool isIsomorphic(char *s, char *t)
{
    size_t len = strlen(s);

    if (len == 1) {
        return true;
    }

    return true;
}

void isIsomorphicTest(void)
{
    char *s = "badc";
    char *t = "baba";

    printf("intput:s=%s, t=%s\n", s, t);

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
    /* 1-26 26+1-26x26+26 26x26+26+1-26x26x26+26x26+26
        1    2             3
    */
    char *table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
    int columNumber = 703;

    printf("input:%d\n", columNumber);

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
