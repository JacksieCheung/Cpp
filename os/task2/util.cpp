#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

// 头文件不要声明变量！
vector<MEM> mem_list;
vector<int> mel_list;  // 分配的申请
vector<int> wait_list; // 等待队列，未能分配

// 第一列为地址，第二列为大小
int read_data_now()
{
    freopen("data_now.txt", "r", stdin);
    // int count = 0;
    while (1)
    {
        int n, m;
        if (scanf("%d %d", &n, &m) == -1)
        {
            break;
        }
        MEM mem;
        mem.BeginAddress = n;
        mem.Capacity = m;
        mem_list.push_back(mem);
    }
    fclose(stdin);
    print_mem_list();
    return 0;
}

int read_data_malloc()
{
    freopen("data_malloc.txt", "r", stdin);
    // int count = 0;
    while (1)
    {
        int n;
        if (scanf("%d", &n) == -1)
        {
            break;
        }
        mel_list.push_back(n);
    }
    fclose(stdin);
    print_mel_list();
    return 0;
}

int print_mem_list()
{
    cout << "the list of the memory:" << endl;
    for (size_t i = 0; i < mem_list.size(); i++)
    {
        if (i + 1 == mem_list.size())
        {
            cout << "[" << mem_list[i].BeginAddress << "," << mem_list[i].Capacity << "]" << endl;
        }
        else
        {
            cout << "[" << mem_list[i].BeginAddress << "," << mem_list[i].Capacity << "]->";
        }
    }
    return 0;
}

int print_mel_list()
{
    cout << "the list we need to malloc:" << endl;
    for (size_t i = 0; i < mel_list.size(); i++)
    {
        if (i + 1 == mel_list.size())
        {
            cout << mel_list[i] << endl;
        }
        else
        {
            cout << mel_list[i] << ",";
        }
    }
    return 0;
}

int print_wait_list()
{
    if (wait_list.size() == 0)
    {
        cout << "all request has been malloced" << endl;
        return 1;
    }

    cout << "there is still some request that we can't malloc:" << endl;
    for (size_t i = 0; i < wait_list.size(); i++)
    {
        if (i + 1 == wait_list.size())
        {
            cout << wait_list[i] << endl;
        }
        else
        {
            cout << wait_list[i] << ",";
        }
    }
    return 0;
}

// 排序
bool ASCSort(MEM a, MEM b) { return (a.Capacity < b.Capacity); }  // 升序
bool DESCSort(MEM a, MEM b) { return (a.Capacity > b.Capacity); } // 降序