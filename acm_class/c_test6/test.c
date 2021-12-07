#include <stdio.h>
#include <string.h>
#define maxsize 210

// a > b
void add(int *a, int *b, int glen, int llen)
{
    int c[maxsize];
    int flag = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < glen; i++, j++)
    {
        // 进位判断
        if (flag)
        {
            a[i] += 1;
            if (a[i] > 9)
            {
                a[i] -= 10;
            }
            else
            {
                flag = 0;
            }
        }

        // 较小者判断终点
        if (j < llen)
        {
            int sum = a[i] + b[j];
            if (sum > 9)
            {
                flag = 1;
                c[i] = sum - 10;
            }
            else
            {
                c[i] = sum;
            }
        }
        else
        {
            c[i] = a[i];
        }
    }

    // 长度 +1
    if (flag)
    {
        c[i] = 1;
        i++;
    }

    // 输出
    for (int index = i - 1; index >= 0; index--)
    {
        printf("%d", c[index]);
    }
    printf("\n");
}

int main()
{
    int aInt[maxsize];
    int bInt[maxsize];
    char a[200];
    char b[200];
    // 输入两个数
    printf("please input two number:\n");
    scanf("%s %s", a, b);

    // 转换
    int alen = 0;
    for (int i = strlen(a) - 1; i >= 0; i--, alen++)
    {
        aInt[alen] = a[i] - '0';
    }

    int blen = 0;
    for (int i = strlen(b) - 1; i >= 0; i--, blen++)
    {
        bInt[blen] = b[i] - '0';
    }

    if (alen > blen)
    {
        add(aInt, bInt, alen, blen);
    }
    else
    {
        add(bInt, aInt, blen, alen);
    }
}