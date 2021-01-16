#include<time.h>

typedef struct customer{
    int Select;     // 选择理发师
    time_t Durtime; // 剪发需要时间
    struct customer* Next;
}Customer;

typedef struct seat{
    int IsFree;      // 座位是否空
    time_t LeaveAt;  // 过期时间/离开时间
    time_t Durtime;  // 用于计算费用
} Seat;

void InitQueue();
void InsertQueue(Customer* cus);
int InsertSeatIfFree(Customer* cus);
void CheckSeatLeaveAt(double* income);
void InsertSeatFromQueue();
Customer* NewCustomer();
void PrintfQueueInfo();