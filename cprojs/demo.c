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

    signed int zx = -6;
    signed int zy = -2;
    char ppx[32];
    char ppy[32];
    itoa(zx, ppx, 2);
    // itoa(zy, ppy, 2);
    printf("%d, %s\n", zx, ppx);
    printf("%d, %s\n", zy, ppy);
}