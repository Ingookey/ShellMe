#include "leecode.h"

void mainc() { printf("sc"); }

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