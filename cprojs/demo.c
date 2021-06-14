#include "demo.h"

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