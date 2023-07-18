#include "common.h"

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
