#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 10; // N 个物品
const int C = 10; // C 个被包容量

int w[N];
int v[N];

int selected[N] = {0}; // 保存选择
int res[N] = {0};      // 保存结果
int max_v = 0;

int Random(int a, int b)
{
    return (rand() % (b - a) + a);
}

// 初始化 w 和 v
void init()
{
    for (int i = 0; i < N; i++)
    {
        w[i] = Random(1, 2 * C);
        v[i] = Random(1, 2 * N);
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << "weight:" << w[i] << ":";
    //     cout << "value:" << v[i];
    //     cout << endl;
    // }
}

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
    if (weight < C)
    {
        for (int i = 0; i < N; i++)
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
    else if (weight == C)
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
    clock_t start, finish;
    double duration;

    init();

    start = clock();
    func(0, 0, 0);
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;

    cout << "ans:";
    for (int i = 0; i < N; i++)
    {
        cout << res[i];
    }
    cout << endl;
    cout << "max_value:" << max_v << endl;

    printf("running time:%f s\n", duration);
}