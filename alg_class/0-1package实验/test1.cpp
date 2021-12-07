#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#define LEN 100

using namespace std;

const int N = 10; // N 个物品
const int C = 10; // C 个被包容量

int w[N];
int v[N];

int maxValue = 0;
int res[LEN];
int len = 0;

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

void func(int *A, int cur)
{
    int value = 0;
    int weight = 0;

    for (int i = 0; i < cur; i++)
    {
        if (weight + w[A[i]] <= C)
        {
            weight += w[A[i]];
            value += v[A[i]];
        }
        else
        {
            return;
        }
    }

    if (value > maxValue)
    {
        memcpy(res, A, LEN);
        len = cur;
        maxValue = value;
    }
}

// 生成子集
void get_subset(int n, int *A, int cur)
{
    if (cur != 0)
    {
        // 执行操作
        func(A, cur);
    }
    int s = cur ? A[cur - 1] + 1 : 0;
    for (int i = s; i < n; i++)
    {
        A[cur] = i;
        get_subset(n, A, cur + 1);
    }
}

int main()
{
    clock_t start, finish;
    double duration;
    int A[LEN];

    init();

    // 开始执行
    start = clock();
    get_subset(N, A, 0);
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;

    cout << maxValue << endl;
    for (int i = 0; i < len; i++)
        cout << res[i] << " ";
    cout << endl;

    printf("running time:%f s\n", duration);
}