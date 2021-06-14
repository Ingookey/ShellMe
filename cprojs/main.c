#include "demo.h"
#include "leecode.h"
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    int (*fp)(int *pl, int size);
    int numbers[] = {40, 52, 71, 30, 18, 89};

#if 0
    int *pResult = NULL;
    pResult = twoSum(numbers, 6, 48);
    printf("index of target:%d, %d \n", *pResult, *(pResult + 1));
#endif

#if 0
    fp = minarray;
    int min = (*fp)(numbers, sizeof(numbers) / sizeof(int));
    printf("minimum number:%d \n", min);
#endif
    showtab();
}