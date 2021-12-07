#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int set[] = {1, 2, 3, 4, 5, 6, 7, 8};
int used[] = {0, 0, 0, 0, 0, 0, 0, 0};
vector<int> res;
int y = 8;

void func(int sum)
{
    if (sum < y)
    {
        // 找一点，继续往下迭代
        for (int i = 0; i < 9; i++)
        {
            if (used[i] == 0)
            {
                used[i] = 1;
                res.push_back(set[i]);
                func(sum + set[i]);
                res.pop_back();
                used[i] = 0;
            }
        }
    }
    else if (sum == y)
    {
        cout << "ans:";
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i];
        }
        cout << endl;
    }
}

int main()
{
    func(0);
}