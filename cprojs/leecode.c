#include "leecode.h"

int minarray(int *pl, int size) {
    int min = *pl;
    for (int i = 1; i < size; i++) {
        if (min > *(pl + i)) {
            min = *(pl + i);
        }
    }
    return min;
}

/**
 * 1
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target) {
    int *returnList = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (target == *(nums + i) + *(nums + j)) {
                *returnList = i;
                *(returnList + 1) = j;
                return returnList;
            }
        }
    }
    return NULL;
}

int daoxu(int *nums, int numsSize) {
    printf("nums:%d\n", numsSize);
    if (numsSize == 1)
        return 0;
    for (int i = 0; i < numsSize; i++)
        printf("%d\t", *(nums + i));
    printf("\n");
    for (int i = 0; i < numsSize / 2; i++) {
        int temp = *(nums + numsSize - i - 1);
        *(nums + numsSize - i - 1) = *(nums + i);
        *(nums + i) = temp;
    }

    for (int i = 0; i < numsSize; i++)
        printf("%d\t", *(nums + i));
    return 0;
}

int hammingWeight1(unsigned int n) {
    int count = 0;
    for (; n; n &= (n - 1))
        ++count;
    return count;
}

int hammingWeight2(unsigned int n) {
    int count = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if (n & mask)
            count++;
        mask = mask << 1;
    }
    return count;
}

// 231
bool isPowerOfTwo(int n) { return n > 0 && !(n & (n - 1)); }

/**
 * 338
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize) {
    int *pNums = (int *)malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;
    for (int i = 0; i <= n; i++)
        *(pNums + i) = 0;
    for (int i = 1; i <= n; i++)
        *(pNums + i) = *(pNums + (i & (i - 1))) + 1;
    for (int i = 0; i <= n; i++)
        printf("%d\t", *(pNums + i));
    return pNums;
}

int dfs(int n, int row, int col, int pie, int na) {
    int res = 0;
    if (row >= n) {
        res++;
        return res;
    }

    // 将所有能放置皇后的位置由 0 变成 1，以便后续的位遍历
    int bits = ~(col | pie | na) & ((1 << n) - 1);
    while (bits > 0) {
        int pick = bits & -bits; // 注: x & -x，取出最后一个1
        res += dfs(n, row + 1, col | pick, (pie | pick) << 1, (na | pick) >> 1);
        bits &= bits - 1; // 注: x & (x - 1), 去掉最后一个1
    }
    return res;
}
/*
 * 52
 */
int totalNQueens(int n) { return dfs(n, 0, 0, 0, 0); }