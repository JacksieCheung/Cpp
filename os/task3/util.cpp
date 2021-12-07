#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

vector<int> page_list;
vector<int> request_list;
vector<int> out_list;
int sum = 0;
double rate = 0;

int read_file()
{
    freopen("data.txt", "r", stdin);
    while (1)
    {
        int n;
        if (scanf("%d", &n) == -1)
        {
            break;
        }
        request_list.push_back(n);
    }
    fclose(stdin);

    return 0;
}

int if_exist(int num)
{
    for (size_t i = 0; i < page_list.size(); i++) // 人为限制 page_list 长度小于等于3
    {
        if (page_list[i] == num)
        {
            return i; // 返回索引
        }
    }

    return -1;
}

int handle_page_list(int num)
{
    sum++;
    if (page_list.size() < MAX_CAP)
    {
        page_list.push_back(num);
        return 0;
    }

    // page_list 等于 MAX_CAP
    out_list.push_back(page_list[0]);
    page_list.erase(page_list.begin());
    page_list.push_back(num);

    return 0;
}

int print_int_vector(std::vector<int> num)
{
    for (size_t i = 0; i < num.size(); i++)
    {
        if (i + 1 == num.size())
        {
            cout << num[i] << endl;
        }
        else
        {
            cout << num[i] << " ";
        }
    }

    return 0;
}

int calculate_rate()
{
    // 缺页率 = (页面置换次数+分配给该进程的物理块数)/要访问的页面总数
    rate = double(sum) / request_list.size();
    return 0;
}