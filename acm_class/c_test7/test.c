#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int tmpInt = 0;
int res[100];
int resLen = 0;
int tmp[100];
int tmpLen = 0;

void resetString(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
}

void init()
{
    for (int i = 0; i < 100; i++)
    {
        res[i] = 0;
    }
}

int add(int (*c)[100], int *a, int *b, int glen, int llen)
{
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
                (*c)[i] = sum - 10;
            }
            else
            {
                (*c)[i] = sum;
            }
        }
        else
        {
            (*c)[i] = a[i];
        }
    }

    // 长度 +1
    if (flag)
    {
        (*c)[i] = 1;
        i++;
    }

    // for (int index = i - 1; index >= 0; index--)
    // {
    //     printf("%d", c[index]);
    // }
    // printf("\n");

    return i;
}

void changeIntToString()
{
    // int 转 string
    tmpLen = 0;
    while (tmpInt != 0)
    {
        tmp[tmpLen] = tmpInt % 10;
        tmpInt /= 10;
        tmpLen++;
    }
}

int formatIntToString(int a, int *tmp)
{
    // int 转 string
    int len = 0;
    while (a != 0)
    {
        tmp[len] = a % 10;
        a /= 10;
        len++;
    }
    return len;
}

void myPow()
{
    // tmp * res
    // 高精度乘法
    int tmpp[100];
    int tmppLen = 0;
    int sum = 0;
    int tmpSum[100];
    int sumLen = 0;
    int tmpRes[100];
    int tmpResLen = 0;

    // 归 0
    resetString(tmpp, 100);
    resetString(tmpSum, 100);
    resetString(tmpRes, 100);

    for (int i = 0; i < resLen; i++)
    {
        int count = 0;
        sum = 0;
        for (int j = 0; j < tmpLen; j++)
        {
            sum += res[i] * tmp[j] * pow(10, count);
            count++;
        }
        // 自身先反转成数组，再和 tmpSum 相加
        resetString(tmpp);
        tmppLen = formatIntToString(sum, tmpp);

        // printf("tmpp: ");
        // for (int i = 0; i < tmppLen; i++)
        // {
        //     printf("%d", tmpp[i]);
        // }
        // printf("\n");

        sumLen = add(&tmpSum, tmpp, tmpRes, tmppLen, tmpResLen);

        printf("tmpSum: ");
        for (int i = 0; i < sumLen; i++)
        {
            printf("%d", tmpSum[i]);
        }
        printf("\n");

        // 把中间结果赋值给 tmpRes
        for (int k = 0; k < sumLen; k++)
        {
            tmpRes[k] = tmpSum[k];
        }
    }

    // 把结果更新到 res 去
    for (int i = 0; i < tmpResLen; i++)
    {
        res[i] = tmpRes[i];
    }
}

void modifyInputToResult(char *a)
{
    resLen = 0;
    for (int i = strlen(a) - 1; i >= 0; i--, resLen++)
    {
        res[resLen] = a[i] - '0';
    }
}

void getResult()
{
    int flag = tmpInt;
    while (flag != 1)
    {
        flag--;
        tmpInt = flag;
        printf("In while, tmpInt: %d\n", flag);
        changeIntToString();

        // printf("In while,tmp: ");
        // for (int i = 0; i < tmpLen; i++)
        //     printf("%d", tmp[i]);
        // printf("\n");

        myPow();
    }
}

int main()
{
    char target[5];
    printf("样例输入： ");
    scanf("%s", target);
    tmpInt = atoi(target);

    printf("tmpInt: %d\n", tmpInt);

    // 转化
    modifyInputToResult(target);

    printf("res: ");
    for (int i = 0; i < resLen; i++)
    {
        printf("%d", res[i]);
    }
    printf("\n");

    getResult();

    for (int i = resLen - 1; i > 0; i--)
    {
        printf("%d", res[i]);
    }
    printf("\n");
}