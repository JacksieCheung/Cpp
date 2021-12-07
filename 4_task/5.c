#include <stdio.h>

int func(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    int mid = n / 2;
    int left = a[mid - 1];
    int right = a[mid];

    // 分两边分别查找
    for (int i = 0; i < mid - 1; i++)
    {
        if (a[i] > left)
        {
            left = a[i];
        }
    }

    for (int i = mid + 1; i < n; i++)
    {
        if (a[i] > right)
        {
            right = a[i];
        }
    }

    return left > right ? left : right;
}

int main()
{
    int a[] = {1, 3, 2, 5, 7, 6, 3, 1};
    printf("%d\n", func(a, 8));
}