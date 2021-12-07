#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    int number;
};

struct node* head;
struct node* tail;

void initList(int length){
    head = malloc(sizeof(struct node));
    head->number = 1;
    head->next = NULL;
    struct node* tool = head;
    for (int i=2;i<=length;i++){
        struct node* tmp = malloc(sizeof(struct node));
        tmp->number = i;
        tmp->next = NULL;
        tool->next = tmp;
        tool = tool->next;
    }

    tail = head;
    while(tail->next!=NULL)
        tail = tail->next;
}

void action(int length){
    while(length>2){
        printf("%d ",head->number);
        head = head->next;
        tail->next = head;
        tail = tail->next;
        head = head->next;
        length--;
    }
    printf("%d %d\n",head->number,tail->number);
}

int main(){
    int length;
    scanf("%d",&length);
    initList(length);
    // printf("%d\n",tail->number);
    action(length);
    return 0;
}