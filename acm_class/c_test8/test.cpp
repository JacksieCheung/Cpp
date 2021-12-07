#include <iostream>
#include <vector>
#include <cstdio>
#define LEN 100

using namespace std;

int in[100];             // 存入度
int res[100];            // 结果
vector<int> martix[100]; // 图

void func(int n);

// 图为线，点为点，图中有点，点入度 +1
int main()
{
    // 输入暂存
    int n;
    int xmin[LEN], xmax[LEN], ymin[LEN], ymax[LEN];
    int x[LEN], y[LEN];

    freopen("Slides.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        in[i] = 0; //初始化
    for (int i = 1; i <= n; i++)
        cin >> xmin[i] >> xmax[i] >> ymin[i] >> ymax[i]; //输入每个幻灯片的坐标
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i]; //输入每个数字的坐标

    fclose(stdin);

    for (int i = 1; i <= n; i++)
    { // i 确定 图
        for (int j = 1; j <= n; j++)
        { // j 确定 点
            if (xmin[i] <= x[j] && xmax[i] >= x[j] &&
                ymin[i] <= y[j] && ymax[i] >= y[j])
            {
                // 在区域内，则点的入度 +1 且初始化图
                martix[i].push_back(j);
                in[j]++;
            }
        }
    }

    func(n);
    return 0;
}

void func(int n)
{
    bool flag = true;
    int num = 0;
    while (flag && num < n)
    {
        flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 1)
            { // 取出入度为 1 的点
                for (int x = 1; x <= n; x++)
                {
                    for (int y = 0; y < martix[x].size(); y++)
                    {
                        if (martix[x][y] == i)
                        { // 找到这个点的第一个位置
                            for (int j = 0; j < martix[x].size(); j++)
                            {
                                in[martix[x][j]]--; // 图内点其他点，入度减一
                            }
                            martix[x].clear(); // 删除这个图
                            flag = true;
                            num++;
                            res[x] = i;
                        }
                    }
                }
            }
        }
    }

    // 输出
    freopen("Slides_out.txt", "w", stdout);

    if (num != n)
        cout << "Wrong" << endl;
    else
        for (int i = 1; i <= n; i++)
        {
            char ch;
            ch = i + 64;
            cout << ch << " " << res[i] << endl;
        }

    fclose(stdout);
}