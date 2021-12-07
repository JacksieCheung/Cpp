#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Status int
#define Error -1
#define OK 1

typedef struct tree{
    char Name[20];
    char IP[20];
    struct tree* Left;  // 左孩子
    struct tree* Right; // 右兄弟
}Tree;

Status InitTree();
Status ResolveHost(char* host,int len,char** result);
Status CompareHost(char** result,int depth,char* IP);
Status AddHost(char** result,int depth,char* IP);
Status ShowAllHost();
Status SaveData();
Status ReadData(char** result);
Status FreeTree();