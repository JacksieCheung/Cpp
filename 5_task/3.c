#include <stdio.h>

int BinSearch(int r[], int res[], int n, int a, int b)
{
    int low = 0, high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a < r[mid])
        {
            high = mid - 1;
        }
        else if (a > r[mid])
        {
            low = mid + 1;
        }
        else
        {
            int index = 0, i = 0;
            for (i = mid; i < n; i++, index++)
            {
                res[index] = r[i];
                if (r[i] == b)
                {
                    break;
                }
            }

            if (r[i] != b)
                return 0;

            return index + 1;
        }
    }
    return 0;
}

int main()
{
    int r[] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int res[100];
    for (int i = 0; i < 4; i++)
    {
        res[i] = 0;
    }

    int len = BinSearch(r, res, 10, 3, 7);

    if (len == 0)
        printf("no b number\n");

    for (int i = 0; i < len; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
}