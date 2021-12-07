#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    clock_t start, finish;
    start = clock();
    long i = 10000000L;
    double duration;

    /* 测量一个事件持续的时间*/
    printf("Time to do %ld empty loops is ", i);
    while (i--)
        ;
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
}