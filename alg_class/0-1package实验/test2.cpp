#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100; // N 个物品
const int C = 10;  // C 个被包容量

int w[N];
int v[N];

int V[N + 1][N + 1];
int x[N];

int Random(int a, int b)
{
    return (rand() % (b - a) + a);
}

// 初始化 w 和 v
void init()
{
    for (int i = 0; i < N; i++)
    {
        w[i] = Random(1, 5);
        v[i] = Random(1, 2 * N);
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << "weight:" << w[i] << ":";
    //     cout << "value:" << v[i];
    //     cout << endl;
    // }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int KnapSack(int w[], int v[], int n, int C)
{
    int i, j;
    for (i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }

    for (j = 0; j <= C; j++)
    {
        V[0][j] = 0;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= C; j++)
        {
            if (j < w[i])
            {
                V[i][j] = V[i - 1][j];
            }
            else
            {
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    // 返回找结果
    for (j = C, i = n; i > 0; i--)
    {
        if (V[i][j] > V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
        {
            x[i] = 0;
        }
    }

    return V[n][C];
}

int main()
{
    clock_t start, finish;
    double duration;

    init();

    start = clock();
    int res = KnapSack(w, v, N, C);
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;

    printf("result: %d\n", res);

    for (int i = 0; i < N; i++)
        cout << x[i];
    cout << endl;

    printf("running time:%f s\n", duration);
}