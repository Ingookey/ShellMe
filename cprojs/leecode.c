#include "leecode.h"

void mainc() { printf("sc"); }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *returnList = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (target == *(nums + i) + *(nums + j)) {
                *returnList = i;
                *(returnList + 1) = j;
                *returnSize = sizeof(returnList) / sizeof(int);
                return returnList;
            }
        }
    }
    return NULL;
}