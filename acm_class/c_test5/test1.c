#include <stdio.h>

void delete_func(int *a, int len, int index)
{
    for (int i = index; i < len - 1; i++)
        a[i] = a[i + 1];
}

void func(int a[100][2], int count)
{
    for (int i = 0; i < count; i++)
    {
        int n = a[i][0];
        int m = a[i][1];
        // 建立数组
        int tmp[n];
        int len = n, index = 0;
        for (int j = 0; j < n; j++)
        {
            tmp[j] = j + 1;
        }

        int flag = 1;
        while (len != 1)
        {
            if (flag)
            {
                index = index + m - 1;
            }
            if (index < len && index >= 0)
            {
                // 前移一个元素
                // printf("idx: %d,ele:%d\n", index, tmp[index]);
                delete_func(tmp, len, index);
                flag = 1;
                len--;
            }
            else
            {
                index -= len;
                flag = 0;
                continue;
            }
        }
        printf("%d\n", tmp[0]);
    }
}

int main()
{
    int n, m;
    int count = 0;
    int a[100][2];
    while (1)
    {
        scanf("%d %d", &n, &m);
        if (n == 0 || m == 0)
        {
            break;
        }

        a[count][0] = n;
        a[count][1] = m;
        count++;
    }

    // func
    func(a, count);
}