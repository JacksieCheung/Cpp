#include <iostream>

using namespace std;

int res = 0;

void func(int x, int y)
{
    // 如果走到了最右上角，结束返回
    if (x < 0 || y > 10)
    {
        return;
    }

    if (x == 0 && y == 10)
    {
        res += 1;
        return;
    }

    if (x - 1 >= 0)
    {
        func(x - 1, y);
    }

    if (y + 1 <= 10)
    {
        func(x, y + 1);
    }
}

int main()
{
    func(10, 0);
    cout << res << endl;
}