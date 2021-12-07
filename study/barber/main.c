#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "seat.h"
#define NEXT_TIME 10 // 一分钟
#define LAST_TIME 60 // 8 小时 28800

// 顾客初始生成三个随机数
// 分别是 durtime(剪发时间 intertime（到达时间 select（选择理发师
// 下个顾客到来的时间也是随机生成的，也就是到达时间
// 每分钟轮询一次，看座位是否为空，是否有顾客剪完，剪完就离开，清算收入。
// 座椅由数组存储

int main(){
	srand((unsigned)(time(NULL)));
	
	// 初始化队列
	// InitQueue();
	
	// 下一个来的时间 假定5-20分钟来一个 300-1200
	time_t intertime = time(NULL)+rand()%5+1;

	// 下次检查时间
	time_t checkAt = time(NULL);
	time_t now = time(NULL);
	time_t EndAt = now + LAST_TIME;

	// 收入
	double income[3];

	// 新客人
	Customer* newCus = NULL;

	while(now<=EndAt){
		now = time(NULL);

		if (now>=checkAt){
			printf("定时轮询:\n");
			// 检查座位上的顾客是否要离开,离开计算收入
			CheckSeatLeaveAt(income);

			// 检查队列顾客是否能就座，能就弹出队首元素
			InsertSeatFromQueue();

			checkAt = time(NULL)+NEXT_TIME;
			printf("轮询结束\n");
		}

		if (now>=intertime){
			printf("新客人来了：\n");
			// 下一位客人到来时间到了
			// 随即生成客人属性，select 和 durtime
			newCus = NewCustomer();
			printf("选了%d级别理发师\n",newCus->Select);
			printf("需要剪%ld时间\n",newCus->Durtime);
			// 检查是否有空位
			if(InsertSeatIfFree(newCus)==0){
				// 无则插入队列
				printf("没有座位，只能排队\n");
				InsertQueue(newCus);
			}

			// 生成下个intertime
			time_t time = rand()%5+1;
			printf("下一位客人还要%ld时间到来\n",time);
			intertime += time;
			printf("将等待下一位客人\n");
		}
	}

	for (int i=0;i<3;i++){
		printf("第%d级理发师收入：%lf",i+1,income[i]);
	}
}
