// 未实现
#include "CPPage.h"
#include "printStart.cpp"
#define INITIAL_SIZE 10

// 修改时的请求，用于定位和确定动作
typedef struct request{
	int action;    // 0->删除 1->改变大小 2->改变文本
	int Code;      // 判断类型 1->矩形，2->圆形
	int Index;     // 一个页面中的索引，是这个图形的唯一标识符
    int PageIndex; // 页面索引
} ModifyRequest;

// ppt 运行过程页面存储
CPPage* Page;

// ppt 运行过程标志页面选择
int IndexNow;

// 程序初始化函数
Status PPtInit(){
    Page = new CPPage[INITIAL_SIZE];
    IndexNow = -1;
    return 1;
}