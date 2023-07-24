#ifndef _MAX_H_
#define _MAX_H_

/* https://zh.wikipedia.org/zh-hk/Typeof */
#define MAX(a, b) \
({ \
    typeof(a) _a = (a); \
    typeof(b) _b = (b); \
    _a > _b ? _a : _b; \
})

#define MIN(a, b) \
({ \
    typeof(a) _a = (a); \
    typeof(b) _b = (b); \
    _a < _b ? _a : _b; \
})

/* function template */
// #define MAXT(T) T max_##T(T a, T b) {return (a > b) ? a : b;}

int max(int a, int b);
int min(int a, int b);
void max_test(void);

#endif
