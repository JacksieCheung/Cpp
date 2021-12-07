#include <iostream>
#include <math.h>

using namespace std;

struct point
{
    int x, y;
};

void quick_sort(point *s, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l].y;
        while (i < j)
        {
            while (i < j && s[j].y >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i++].y = s[j].y;
            while (i < j && s[i].y < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j--].y = s[i].y;
        }
        s[i].y = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}

double Distance(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Closest(point S[], int low, int high)
{
    double d1, d2, d3, d;
    int mid, i, j, index;
    point P[100];
    if (high - low == 1)
    {
        return Distance(S[low], S[high]);
    }

    if (high - low == 2)
    {
        d1 = Distance(S[low], S[low + 1]);
        d2 = Distance(S[low + 1], S[high]);
        d3 = Distance(S[low], S[high]);
        if (d1 < d2 && d1 < d3)
            return d1;
        else if (d2 < d3)
            return d2;
        else
            return d3;
    }

    mid = (low + high) / 2;
    d1 = Closest(S, low, mid);
    d2 = Closest(S, mid + 1, high);
    if (d1 < d2)
        d = d1;
    else
        d = d2;

    index = 0;
    for (i = mid; (i >= low) && (S[mid].x - S[i].x < d); i--)
    {
        P[index++] = S[i];
    }
    for (i = mid + 1; (i <= high) && (S[i].x - S[mid].x < d); i++)
    {
        P[index++] = S[i];
    }

    quick_sort(P, 0, index - 1);
    for (i = 0; i < index; i++)
    {
        for (j = i + 1; j < index; j++)
        {
            if (P[j].y - P[i].y >= d)
            {
                break;
            }
            else
            {
                d3 = Distance(P[i], P[j]);
                if (d3 < d)
                    d = d3;
            }
        }
    }

    return d;
}

int main()
{
    point P[5];
    P[0].x = 2, P[0].y = 3;
    P[1].x = 8, P[1].y = 9;
    P[2].x = 6, P[2].y = 0;
    P[3].x = 2, P[3].y = 8;
    P[4].x = 7, P[4].y = 3;

    int d = Closest(P, 0, 4);
    printf("Closest: %d\n", d);
}