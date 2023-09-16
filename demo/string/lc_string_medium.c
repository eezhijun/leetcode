/**
 * @file lc_string_medium.c
 * @author eehongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"


/* https://leetcode.cn/problems/longest-substring-without-repeating-characters/

无重复字符的最长子串

给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。



示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成 */
int lengthOfLongestSubstring(char * s)
{
    if (!s[0]) {
        return 0;
    }
    int max = 1, n = 0;

    for (int i = 1; s[i] != 0; i++) {
        int tmp = 1;
        for (int j = n; j < i; j++) {
            if (s[j] == s[i]) {
                n = j + 1;
                break;
            } else {
                tmp++;
            }
        }
        max = tmp > max ? tmp : max;
    }

    return max;

}
