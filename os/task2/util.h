#ifndef _MEM_UTIL
#define _MEM_UTIL

typedef struct memory
{
    int BeginAddress;
    int Capacity;
} MEM;

int read_data_now();
int read_data_malloc();
int print_mel_list();
int print_mem_list();
int print_wait_list();
// 排序
bool ASCSort(MEM a, MEM b);
bool DESCSort(MEM a, MEM b);

#endif