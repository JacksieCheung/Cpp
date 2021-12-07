#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

extern vector<int> page_list;
extern vector<int> request_list;
extern vector<int> out_list;
extern int sum;
extern double rate;

int handleFIFO()
{
    for (size_t i = 0; i < request_list.size(); i++)
    {
        int index = if_exist(request_list[i]);
        // 判断是否命中
        if (index != -1)
        {
            // swap(page_list[index], page_list[MAX_CAP - 1]);
            iter_swap(page_list.begin() + index, page_list.end() - 1); // end 指向最后一个元素的下一个元素
            continue;                                                  // 跳过
        }

        handle_page_list(request_list[i]);
    }

    return 0;
}

int main()
{
    read_file();

    handleFIFO();

    calculate_rate();
    print_int_vector(out_list);
    cout << sum << " " << rate << endl;

    return 0;
}