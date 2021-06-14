//#include "./easylogger/inc/elog.h"
//#include "./easylogger/inc/elog_cfg.h"
#include "demo.h"
#include "leecode.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    ///* close printf buffer */
    // setbuf(stdout, NULL);
    ///* initialize EasyLogger */
    // elog_init();
    ///* set EasyLogger log format */
    // elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    // elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG |
    // ELOG_FMT_TIME); elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG |
    // ELOG_FMT_TIME); elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG |
    // ELOG_FMT_TIME); elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL &
    // ~ELOG_FMT_FUNC); elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL &
    // ~ELOG_FMT_FUNC);
    ///* start EasyLogger */
    // elog_start();

    int (*fp)(int *pl, int size);
    int numbers[] = {40, 52, 71, 30, 18, 89};
    // log_a("Hello EasyLogger!");
    // log_e("Hello EasyLogger!");
    // log_w("Hello EasyLogger!");
    // log_i("Hello EasyLogger!");
    // log_d("Hello EasyLogger!");
    // log_v("Hello EasyLogger!");

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

#if 0
    fp = daoxu;
    (*fp)(numbers, sizeof(numbers) / sizeof(int));

    // showtab();

    int res = hammingWeight2(67);
    printf("res:%d \n", res);

    bool res = isPowerOfTwo(8);
    printf("res:%d \n", res);
#endif

    int y = 0;
    int *pSize = &y;
    int *pNums = NULL;
    pNums = countBits(9, pSize);
    return 0;
}