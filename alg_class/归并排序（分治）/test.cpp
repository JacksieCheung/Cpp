#include <iostream>

using namespace std;

void merge(int r[], int r1[], int s, int m, int t)
{
    int i = s, j = m + 1, k = s;
    while (i <= m && j <= t)
    {
        if (r[i] <= r[j])
        {
            r1[k++] = r[i++];
        }
        else
        {
            r1[k++] = r[j++];
        }
    }

    while (i <= m)
        r1[k++] = r[i++];
    while (j <= t)
        r1[k++] = r[j++];
}

void mergesort(int r[], int s, int t)
{
    int m, r1[10000];
    if (s == t)
        return;

    m = (s + t) / 2;
    mergesort(r, s, m);
    mergesort(r, m + 1, t);
    merge(r, r1, s, m, t);
    for (int i = s; i <= t; i++)
    {
        r[i] = r1[i];
    }
}

int main()
{
    int m[5] = {1, 2, 6, 4, 3};
    mergesort(m, 0, 4);
}