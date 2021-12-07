#include <iostream>
#include <cstdio>

using namespace std;

bool test_su(int num)
{
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int func(int m)
{
    for (int i = m;;)
    {
        if (test_su(m) && test_su(m + 2))
        {
            return m;
        }
        m++;
    }
}

int main()
{
    int m;
    cin >> m;
    int res = func(m);
    cout << res << "," << res + 2 << endl;
}