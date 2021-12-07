#ifndef _PAGE_UTIL
#define _PAGE_UTIL

#define MAX_CAP 3 // 空闲内存块

int read_file();
int if_exist(int num); // 遍历，判断页面是否已存在
int handle_page_list(int num);
int print_int_vector(std::vector<int> num);
int calculate_rate();

#endif