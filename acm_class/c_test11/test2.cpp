#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<string> res;

int sum = 0;

void func(int k)
{
    int y = 0;
    // x 的范围大于 k，小于等于 2k
    for (int x = (k + 1); x <= 2 * k; x++)
    {
        if ((k * x) % (x - k) == 0) // 判断求得尽
        {
            y = (k * x) / (x - k); // 公式求得 y
            char tmp[100] = {'\0'};
            sprintf(tmp, "1/%d = 1/%d + 1/%d\n", k, y, x);
            string str(tmp);
            res.push_back(tmp);
            sum++;
        }
    }
}

int main()
{
    int k = 0;
    cin >> k;
    func(k);
    cout << sum << endl;
    for (int i = 0; i < sum; i++)
    {
        cout << res[i];
    }
}