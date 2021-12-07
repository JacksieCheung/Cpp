#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int selected[10] = {0};
int target = 62;

void switch_to_int(vector<int> res)
{
    char a[6] = {'\0'};
    char b[6] = {'\0'};
    int x = 0;
    int y = 0;
    for (int i = 0; i <= 4; i++)
    {
        x *= 10;
        x += res[i];
        a[i] = res[i] + '0';
    }

    int index = 0;
    for (int j = 5; j < 10; j++, index++)
    {
        y *= 10;
        y += res[j];
        b[index] = res[j] + '0';
    }

    if (x < y)
    {
        return;
    }

    if (target * y == x)
    {
        printf("%s/%s = %d\n", a, b, target);
    }
}

// 生成 0～9 的所有排列
void func(vector<int> res, int depth)
{
    if (depth == 10)
    {
        // 判断条件
        switch_to_int(res);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (selected[i] == 0)
        {
            // 剪枝条件
            if (arr[i] <= 4 && depth == 0)
                continue;
            selected[i] = 1;
            res.push_back(arr[i]);
            func(res, depth + 1);
            selected[i] = 0;
            res.pop_back();
        }
    }
}

int main()
{
    cin >> target;
    vector<int> res;
    func(res, 0);
}