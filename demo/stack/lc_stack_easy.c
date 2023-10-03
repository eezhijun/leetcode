/**
 * @file lc_stack_easy.c
 * @author eehongzhijun (eehongzhijun@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* https://leetcode.cn/problems/next-greater-element-i/ */
/* nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。



示例 1：

输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
输出：[-1,3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
示例 2：

输入：nums1 = [2,4], nums2 = [1,2,3,4].
输出：[3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
- 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。


提示：

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
nums1和nums2中所有整数 互不相同
nums1 中的所有整数同样出现在 nums2 中


进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？ */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size,
                        int *returnSize)
{
}

void nextGreaterElementTest(void)
{
}

/* https://leetcode.cn/leetbook/read/queue-stack/g5l7d/ */
/* 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

提示：

-231 <= val <= 231 - 1
pop、top 和 getMin 操作总是在 非空栈 上调用
push, pop, top, and getMin最多被调用 3 * 104 次
*/

#define STACK_SIZE 30000
typedef struct {
    int data[STACK_SIZE];
    int top;
} MinStack;

MinStack *minStackCreate(void)
{
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    if (obj == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    memset(obj->data, 0, STACK_SIZE);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack *obj, int val)
{
    obj->top++;
    obj->data[obj->top] = val;
}

void minStackPop(MinStack *obj)
{
    obj->top--;
}

int minStackTop(MinStack *obj)
{
    return obj->data[obj->top];
}

int minStackGetMin(MinStack *obj)
{
    int min = obj->data[obj->top];
    for (int i = obj->top; i >= 0; i--) {
        if (obj->data[i] < min) {
            min = obj->data[i];
        }
    }
    return min;
}

void minStackFree(MinStack *obj)
{
    if (obj != NULL) {
        free(obj);
        obj = NULL;
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
void minStackTest(void)
{
    int ret = 0;
    MinStack* obj = minStackCreate();

    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    ret = minStackGetMin(obj);
    printf("min=%d\n", ret);
    minStackPop(obj);
    ret = minStackTop(obj);
    printf("top=%d\n", ret);
    ret = minStackGetMin(obj);
    printf("min=%d\n", ret);
    minStackFree(obj);
}
