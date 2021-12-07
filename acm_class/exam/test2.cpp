#include <iostream>
#include <cstdio>

using namespace std;

static const int LEN = 2600;
int a[LEN], b[LEN], c[LEN];

void clear(int a[])
{
    for (int i = 0; i < LEN; ++i)
        a[i] = 0;
}

void print(int a[])
{
    int i;
    for (i = LEN - 1; i >= 1; --i)
        if (a[i] != 0)
            break;
    for (; i >= 0; --i)
        putchar(a[i] + '0');
    putchar('\n');
}

int getLen(int a[])
{
    int i;
    for (i = LEN - 1; i >= 1; --i)
        if (a[i] != 0)
            return i + 1;
    return 0;
}

// 双高精度乘法运算
void mul(int a[], int b[], int c[])
{
    clear(c);

    for (int i = 0; i < LEN - 1; i++)
    {
        for (int j = 0; j <= i; j++)
            c[i] += a[j] * b[i - j];

        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

void switchIntToArray(int num, int a[])
{
    int index = 0;
    while (num > 0)
    {
        a[index] = num % 10;
        num /= 10;
        index++;
    }
}

void copy(int src[], int dest[])
{
    for (int i = 0; i < LEN; i++)
    {
        dest[i] = src[i];
    }
}

void func(int n, int m)
{
    int sub = 1;
    switchIntToArray(n, a);
    while (sub <= m - 1)
    {
        clear(b);
        switchIntToArray(n - sub, b); // b = n - sub
        mul(a, b, c);                 // c = a * b
        clear(a);
        copy(c, a); // a = c
        sub++;
    }

    int len = getLen(a);
    if (len <= 6)
        print(a);
    else
    {
        for (int i = 5; i >= 0; i--)
            cout << a[i];
        cout << endl;
    }
}

int main()
{
    int n = 0, m = 0;
    cin >> m >> n;

    func(n, m);
}