#include<stdlib.h>
#include<stdio.h>
#include "seat.h"

// 初始化座椅
Seat seat[7]; 
// 初始化队列
Customer* queue1;
Customer* queue2;
Customer* queue3;

void PrintfQueueInfo(){
    Customer* tmp;
    int count = 0;
    
    printf("等侯人数：\n");
    
    printf("一级理发师：");
    tmp = queue1;
    while(tmp!=NULL) {
        count++;
        tmp = tmp->Next;
    }
    printf("%d\n",count);
    
    printf("二级理发师：");
    count = 0;
    tmp = queue2;
    while(tmp!=NULL) {
        count++;
        tmp = tmp->Next;
    }
    printf("%d\n",count);

    printf("三级理发师：");
    count = 0;
    tmp = queue3;
    while(tmp!=NULL) {
        count++;
        tmp = tmp->Next;
    }
    printf("%d\n",count);
}

void InitQueue(){
    queue1 = (Customer*)malloc(sizeof(Customer));
    queue2 = (Customer*)malloc(sizeof(Customer));
    queue3 = (Customer*)malloc(sizeof(Customer));
}

void InsertQueue(Customer* cus){
    Customer* tmp = NULL;
    switch(cus->Select){
        case 1:
            tmp = queue1;
            break;
        case 2:
            tmp = queue2;
            break;
        case 3:
            tmp = queue3;
            break;
    }
    
    if (tmp==NULL) {
        tmp = cus;
        return;
    }

    while(tmp->Next!=NULL) tmp = tmp->Next;
    tmp->Next = cus; // cus 插入到队尾
    PrintfQueueInfo();
    return;
}

void insertSeat(Customer* cus,int index){
    printf("有座位\n");
    seat[index].IsFree = 0;
    seat[index].LeaveAt = time(NULL) + cus->Durtime;
    seat[index].Durtime = cus->Durtime;
    free(cus);
    return;
}

int InsertSeatIfFree(Customer* cus){
    switch (cus->Select)
    {
    case 1:
        for (int i=0;i<2;i++){
            if (seat[i].IsFree) {
                // 写入 cus
                insertSeat(cus,i);
                return 1;
            }
        }
        break;
    case 2:
        for (int i=2;i<4;i++){
            if (seat[i].IsFree) {
                insertSeat(cus,i);
                return 1;
            }
        }
        break;
    case 3:
        for (int i=4;i<7;i++){
            if (seat[i].IsFree) {
                insertSeat(cus,i);
                return 1;
            }
        }
        break;
    }
    return 0;
}


void InsertSeatFromQueue(){
    // 0,1 看 seat 有无空位
    for (int i=0;i<2;i++){
        if(seat[i].IsFree){
            Customer* tmp = queue1;
            if (tmp==NULL) break;
            queue1 = queue1->Next;
            insertSeat(tmp,i);
        }
    }

    // 2,3
    for (int i=2;i<4;i++){
        if(seat[i].IsFree){
            Customer* tmp = queue2;
            if (tmp==NULL) break;
            queue2 = queue2->Next;
            insertSeat(tmp,i);
        }
    }

    // 4,5,6
    for (int i=4;i<7;i++){
        if(seat[i].IsFree){
            Customer* tmp = queue3;
            if (tmp==NULL) break;
            queue3 = queue3->Next;
            insertSeat(tmp,i);
        }
    }
}

void CheckSeatLeaveAt(double* income){
    time_t now = time(NULL);
    for(int i=0;i<7;i++){
        if (seat[i].IsFree==0&&now>=seat[i].LeaveAt){
            // 清算工资 和 设置空闲
            if (i<2) {
                income[0] += seat[i].Durtime*3*0.4;
            } else if (i<4){
                income[1] += seat[i].Durtime*2*0.4;
            } else {
                income[2] += seat[i].Durtime*0.4;
            }

            seat[i].IsFree = 1;
            seat[i].LeaveAt = 0;
        }
    }
}

Customer* NewCustomer(){
    Customer* cus = (Customer*)malloc(sizeof(Customer));
    cus->Select = rand()%3+1; // 限定只能是 1-3
    cus->Durtime = rand()%5+1;   // 理发时间为 5 - 20 分钟
    return cus;
}