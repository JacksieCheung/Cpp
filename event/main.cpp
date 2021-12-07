#include <iostream>

using namespace std;

int ActiveManage(int s[], int f[], int B[], int n)
{
    int i, j, count;
    B[0] = 1;
    j = 0;
    count = 1;
    for (i = 1; i < n; i++)
    {
        if (s[i] >= f[j])
        {
            B[i] = 1;
            j = i;
            count++;
        }
        else
            B[i] = 0;
    }
    return count;
}

int main()
{
    int s[] = {1, 2, 3, 4, 5};
    int f[] = {5, 4, 2, 3, 1};
    int B[5] = {0};
    cout << ActiveManage(s, f, B, 5) << endl;
}