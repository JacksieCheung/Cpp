#include <iostream>
#include <cstdio>

using namespace std;

int res = 0;
int step[] = {1, 2};
int step_total = 40;

void func(int step_now)
{
    if (step_now == step_total)
    {
        res++;
        return;
    }
    if (step_now < step_total)
    {
        for (int i = 0; i < 2; i++)
        {
            func(step_now + step[i]);
        }
    }
}

int main()
{
    func(0);
    cout << res << endl;
}