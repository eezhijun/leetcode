#include "common.h"

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
