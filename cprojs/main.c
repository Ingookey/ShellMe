#include "demo.h"
#include "leecode.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    int (*fp)(int *pl, int size);
    int numbers[] = {40, 52, 71, 30, 18, 89};

#if 0
    int *pResult = NULL;
    pResult = twoSum(numbers, sizeof(numbers) / sizeof(int), 48);
    printf("index of target:%d, %d \n", *pResult, *(pResult + 1));
#endif

#if 0
    fp = minarray;
    int min = (*fp)(numbers, sizeof(numbers) / sizeof(int));
    printf("minimum number:%d \n", min);
#endif

#if 1
    fp = daoxu;
    (*fp)(numbers, sizeof(numbers) / sizeof(int));
#endif
    // showtab();
    return 0;
}