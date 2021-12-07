#include <iostream>

using namespace std;

int x[8]; // 第 k 个皇后放在第 k 行，第 x[k] 列

int Place(int k)
{
    for (int i = 0; i < k; i++)
    {
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))
            return 1;
    }
    return 0;
}

void Queen(int n)
{
    int k = 0;
    while (k >= 0)
    {
        x[k]++;
        while (x[k] < n && Place(k) == 1)
        {
            x[k]++;
        }

        if (x[k] < n && k == n - 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << x[i] + 1 << " ";
            }
            cout << endl;
            //return;
        }
        if (x[k] < n && k < n - 1)
            k = k + 1;
        else
            x[k--] = -1;
    }
    // cout << "无解" << endl;
}

int main()
{
    Queen(8);
}