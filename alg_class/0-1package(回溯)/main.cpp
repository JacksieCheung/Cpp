#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int selected[5] = {0}; // 保存选择
int res[5] = {0};      // 保存结果
int max_v = 0;
int W = 12;
int w[] = {5, 3, 2, 4, 2};
int v[] = {11, 8, 15, 12, 6};

void replace_res(int v)
{
    if (v > max_v)
    {
        max_v = v;
        for (int i = 0; i < 5; i++)
        {
            res[i] = selected[i];
        }
    }
}

void func(int weight, int value, int old_idx)
{
    int flag = 0; // 用来标志全部选完
    if (weight < W)
    {
        for (int i = 0; i < 5; i++)
        {
            if (selected[i] == 0)
            {
                // 选定一个空闲的元素
                flag = 1;
                selected[i] = 1;
                func(weight + w[i], value + v[i], i);
                selected[i] = 0;
            }
        }
        if (!flag)
        {
            replace_res(value);
        }
    }
    else if (weight == W)
    {
        replace_res(value);
    }
    else
    {
        selected[old_idx] = 0;
        value -= v[old_idx];
        replace_res(value);
    }
}

int main()
{
    func(0, 0, 0);

    cout << "ans:";
    for (int i = 0; i < 5; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    cout << "max_value:" << max_v << endl;
}