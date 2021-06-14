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