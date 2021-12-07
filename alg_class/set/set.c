#include <stdio.h>
#include <stdlib.h>

int array[] = {1, 2, 3, 4, 5};

#define N 5
#define M 3
int results[N] = {0}; //保存已经找到的结果前缀数组
int results_end = 0;  //结果前缀数组有效数据下标
int is_used[N] = {0}; //是否已经排列过了的标志

// 排列
void perm(int deep, int n)
{
    int i;
    if (deep > n) // 越界递归结束
    {
        return;
    }

    if (deep == n) // 找到结果，打印，递归结束
    {
        for (i = 0; i < n; i++)
        {
            printf("%d", results[i]);
        }
        printf("\t");
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (is_used[i] == 0)
        {
            is_used[i] = 1;
            results[deep] = array[i];
            perm(deep + 1, n);
            is_used[i] = 0;
        }
    }
}

// 组合
void comb(int deep, int n, int m)
{
    int i = 0;
    if (deep > n) // 越界递归结束
        return;
    if (results_end == m) // 找到结果，打印，递归结束
    {
        for (i = 0; i < m; i++)
        {
            printf("%d", results[i]);
        }
        printf("\t");
        return;
    }
    results[results_end++] = array[deep];
    comb(deep + 1, n, m); //向下一级递归
    results_end--;
    comb(deep + 1, n, m); //向下一级递归
}

int main()
{
    int i = 0;
    perm(0, N);
    printf("\n组合\n");
    for (i = 1; i <= N; i++)
    {
        comb(0, N, i);
    }
    printf("\n");
    return 0;
}