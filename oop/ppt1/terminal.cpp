// 未实现
#include<iostream>
#include<cstring>

void printNext(){
    std::cout<<">"<<std::endl;
}

void Handler(){
    char code[10];
    for (;;) {
        scanf("%s",&code);
        char tmp[10];
        for (int i=0;i<4;i++) tmp[i]=code[i];
        tmp[5]='\0';

        if (strcmp(tmp,"exit")) break;

        if (strcmp(tmp,"alter")) ;
    }
}
// 退出->"exit" say hello
// 选择页面->"alter [nums]" 只输出文本框 id 列表
// 查看页面信息->"Show [nums]" 输出所有信息
// 以下命令必须在选择后才能执行：
// 创建矩形->"0 [config]" 删除矩形->"1 [index]"
// 创建圆形->""