#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

extern vector<MEM> mem_list;
extern vector<int> mel_list;
extern vector<int> wait_list;

// 最坏适应算法
int handle_worst_fit()
{
    if (mem_list.size() == 0)
        return 1;

    // 先按容量降排序
    sort(mem_list.begin(), mem_list.end(), DESCSort);

    for (size_t i = 0; i < mel_list.size(); i++)
    {
        if (mem_list[0].Capacity >= mel_list[i])
        {
            // 判断第一个块是否能分配，如果不行，则无法分配
            mem_list[0].BeginAddress += mel_list[i];
            mem_list[0].Capacity -= mel_list[i];
            sort(mem_list.begin(), mem_list.end(), DESCSort);
        }
        else
        {
            // 遍历完了，也未能找到
            wait_list.push_back(mel_list[i]);
        }
    }

    return 0;
}

int main()
{
    read_data_now();
    read_data_malloc();

    handle_worst_fit();

    // print
    cout << "<====final result====>" << endl;
    print_mem_list();
    print_wait_list();

    return 0;
}