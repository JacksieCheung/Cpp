#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int number;
    int isOpen;
};

struct node * tree;

int initTree(int depth)
{
    int length;
    for (int i = 1; i <= depth; i++)
    {
        length += pow(2, i - 1);
    }
    tree = malloc(sizeof(struct node) * length);

    for (int i = 0; i < length; i++)
    {
        tree[i].number = i + 1;
        tree[i].isOpen = 0;
    }

    return length;
}

int action(int ballSum,int length){
    int index=0;
    for (int ball=0;ball<ballSum;ball++){
        index = 0;
        // 每一次球重现
        for (;index<length-1;){
            if (tree[index].isOpen){
                // 开关开了，往右走
                tree[index].isOpen = 0;
                int tmp =  2*tree[index].number; // 本来是 2n+1 现在需要减 1 做索引
                if (tmp>length-1) break;
                index = tmp;
            } else {
                tree[index].isOpen = 1;
                int tmp = 2*tree[index].number-1;
                if (tmp>length-1) break;
                index = tmp;
            }
        }
    }
    return index+1;
}

int main()
{
    int length;
    int depth;
    int ballSum;
    scanf("%d %d", &depth, &ballSum);
    length = initTree(depth);
    // printf("length:%d\n", length);
    printf("%d\n",action(ballSum,length));
    return 0;
}