#include "leecode.h"
#include <stdio.h>
#include <stdlib.h>

int (*fp)(int *pl, int size);

int minarray(int *pl, int size) {
    int min = *pl;
    for (int i = 1; i < size; i++) {
        if (min > *(pl + i)) {
            min = *(pl + i);
        }
    }
    return min;
}

void *showtab(void) {
    const int x = 67;
    const int *px = &x; // *px不可修改
    printf("value's *px: %d\n", *px);

    int y = 90;
    int *const py = &y; // py不可修改
    printf("value's *py: %d\n", *py);

    const int *const pz = &x; // pz不可修改，*pz也不可修改
    printf("value's *pz: %d\n", *pz);
}

void main() {
    int numbers[] = {40, 52, 71, 30, 18, 89};
    int x = 0;
    int *returnSize = &x;
    int *pResult = NULL;
    pResult = twoSum(numbers, 6, 48, returnSize);
    printf("%d, %d \n", *pResult, *(pResult + 1));

#if 1
    fp = minarray;
    int min = (*fp)(numbers, sizeof(numbers) / sizeof(int));
    printf("minimum number is %ld \n", min);
#endif
    // showtab();
    mainc();
}