#include <iostream>
#include <cstdio>

using namespace std;

int s[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};     // 开始
int f[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // 结束
bool a[11];                                       // 判断是否选择，结果集
int n = 11;                                       // 事件个数

int func()
{
    a[0] = true;
    int j = 0;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] >= f[j])
        {
            a[i] = true;
            j = i;
            count++;
        }
        else
            a[i] = false;
    }
    return count;
}

int main()
{
    int count = func();
    printf("活动个数：%d\n", count);
    printf("有：\n");
    for (int i = 0; i <= n; i++)
        if (a[i])
            cout << i + 1 << " ";

    cout << endl;
    return 0;
}