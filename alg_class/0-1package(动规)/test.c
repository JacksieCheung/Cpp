#include <stdio.h>

int V[100][100];
int x[100];

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
    int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int v[] = {3, 4, 5, 1, 2, 3, 4, 5, 6, 1};
    printf("result: %d\n", KnapSack(w, v, 10, 5));
}