#include <stdio.h>

// 二分查找
int func(int a[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("a[mid]:%d,mid:%d\n", a[mid], mid);
        if (a[mid] > mid + 1)
        {
            high = mid - 1;
        }
        else if (a[mid] < mid + 1)
        {
            low = mid + 1;
        }
        else
        {
            return mid + 1;
        }
    }

    return 0;
}

int main()
{
    int a[] = {0, 1, 3, 6, 7, 8, 9, 10};
    printf("%d\n", func(a, 8));
}