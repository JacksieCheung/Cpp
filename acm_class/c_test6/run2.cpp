#include <stdio.h>

int fun(int n)
{
    int a[10000], l = 0, i, j; //位数限制10000位 可以再多
    for (i = 0; i < 10000; i++)
        a[i] = 0;
    a[0] = 1;

    for (i = 2; i <= n; i++)
    {
        for (j = 0; j <= l; j++)
            a[j] *= i;
        l += 3;
        for (j = 0; j < l; j++)
            if (a[j] > 9)
            {
                a[j + 1] += a[j] / 10;
                a[j] %= 10;
            }
        while (a[l] == 0)
            l--;
    }

    for (i = l; i >= 0; i--)
        printf("%d", a[i]);
    printf("\n");
    return l;
}
int main()
{
    int a = 0;
    scanf("%d", &a);
    // for (int n = 0; n < 10000; n++)
    {
        // printf("共%d位 %d!= ", fun(999) + 1, 999);
        fun(a);
    }
}