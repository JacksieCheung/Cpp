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
        // 判断是否命中
        if (if_exist(request_list[i]) != -1)
            continue; // 跳过

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