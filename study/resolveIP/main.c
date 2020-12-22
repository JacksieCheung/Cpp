#include "tree.h"
#include<string.h>

void showMenu(){
    printf("输入：\n");
    printf("1.新增域名\n");
    printf("2.解析域名\n");
    printf("3.查看全部域名\n");
    printf("4.保存\n");
    printf("5.退出\n");
}

int main(){
    // init reslove host result
    char** result;
    result = (char**)malloc(sizeof(char*)*20);
    for (int i=0;i<20;i++){
        result[i]=(char*)malloc(sizeof(char)*20);
    }

    char host[20]; // host
    char IP[20];   // ip

    char str[10];
    int select = 0;
    int status = 0;
    int depth = 0;
    int ifExist = 0;

    InitTree();
    ReadData(result);

    while(1){
        if (ifExist) break;
        showMenu();
        scanf("%s",str);
        select = str[0]-'0';
        if (select<=0||select>10){
            printf("System:Command error.\n");
            continue;
        }

        switch(select){
            case 1:
                printf("输入域名：\n");
                scanf("%s",host);
                printf("输入ip地址：\n");
                scanf("%s",IP);

                depth = ResolveHost(host,strlen(host),result);
                if (depth==Error) {
                    printf("System:reslove failed.\n");
                    break;
                }

                status = AddHost(result,depth-1,IP);

                if(status==Error){
                    printf("System:This host is existed\n");
                } else {
                    printf("System:Add host successfully.\n");
                }
                status = 0;
                printf("finished\n");
                break;
            case 2:
                printf("输入域名：\n");
                scanf("%s",host);
                
                depth = ResolveHost(host,strlen(host),result);
                if (depth==Error) {
                    printf("System:Reslove failed.\n");
                    break;
                } 

                status = CompareHost(result,depth-1,IP);

                if (status==Error){
                    printf("System:DNS resolve error.\n");
                } else {
                    printf("IP_Address:%s\n",IP);
                }

                status = 0;
                break;
            case 3:
                if(ShowAllHost()==Error) printf("System:Empty.\n");
                break;
            case 4:
                if(SaveData()==Error) printf("System:Save failed.\n");
                printf("System:Save successfully.\n");
                break;
            case 5:
                ifExist = 1;
                break;
            default:break;
        }
    }
    FreeTree();
    exit(0);
}