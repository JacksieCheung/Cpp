#include <iostream>

using namespace std;

// 交换函数
void swap(int *m, int *n)
{
    int tmp = *m;
    *m = *n;
    *n = tmp;
}

int partition(int r[], int low, int high)
{
    int i = low, j = high;
    while (i < j)
    {
        while (i < j && r[i] <= r[j])
            j--;
        if (i < j)
        {
            swap(&r[i], &r[j]);
            i++;
        }

        while (i < j && r[i] <= r[j])
            i++;
        if (i < j)
        {
            swap(&r[i], &r[j]);
            j--;
        }
    }
    return i;
}

int selectmink(int r[], int low, int high, int k)
{
    int s;
    s = partition(r, low, high);
    if (s == k)
        return r[s];
    if (s > k)
        return selectmink(r, low, s - 1, k);
    if (s < k)
        return selectmink(r, s + 1, high, k);
    return 0;
}

int main()
{
    int r[] = {1, 2, 3, 7, 4, 9, 6};
    cout << selectmink(r, 0, 6, 4) << endl;
}