#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

extern vector<MEM> mem_list;
extern vector<int> mel_list;
extern vector<int> wait_list;

// 首次适应算法
int handle_first_fit()
{
    int flag = 0;
    for (size_t i = 0; i < mel_list.size(); i++)
    {
        for (size_t j = 0; j < mem_list.size(); j++)
        {
            if (mem_list[j].Capacity >= mel_list[i])
            {
                // 找到了第一个比它大的块
                mem_list[j].BeginAddress += mel_list[i];
                mem_list[j].Capacity -= mel_list[i];
                flag = 1;
                break;
            }
        }
        // 遍历完了，也未能找到
        if (!flag)
        {
            wait_list.push_back(mel_list[i]);
        }
        flag = 0;
    }

    return 0;
}

int main()
{
    read_data_now();
    read_data_malloc();

    handle_first_fit();

    // print
    cout << "<====final result====>" << endl;
    print_mem_list();
    print_wait_list();

    return 0;
}