#include "tree.h"

Tree* Root;

Status InitTree(){
    Root = (Tree*)malloc(sizeof(Tree));
    if (Root==NULL) return Error;
    strcpy(Root->Name,"root");
    return OK;
}

// 解析域名，切分为多维数组
// result 为已分配固定内存数组
Status ResolveHost(char* host,int len,char** result){
    int index=0,j=0,k=0;
    for (int i=0;i<len;i++){
        if (host[i]=='.') {
            // 写入节点到result
            while(j<i){
                result[index][k]=host[j];
                j++;
                k++;
            }
            result[index][k]='\0';
            index++; // 指向下一个数组
            k=0;     // k 归 0
            j++;     // 跳过 '.'
        }
    }
    while(j<len){
        result[index][k]=host[j];
        k++;
        j++;
    }
    result[index][k]='\0';
    index++;

    return index;
}

Status searchNode(Tree* fatherNode,Tree* node,char** result,int depth,char* IP){
    if (depth==-1) {
        if (node==NULL){
            strcpy(IP,fatherNode->IP);
            return OK; // result 走完并且 node 到尽头，匹配成功
        }
        return Error;
    }
    if (node==NULL) return Error; // 说明遍历完了还没找到
    
    if (strlen(node->Name)==strlen(result[depth])
    &&!strcmp(node->Name,result[depth])){
        searchNode(node,node->Left,result,depth-1,IP);
    } else {
        searchNode(node,node->Right,result,depth,IP);
    }
}

// 将域名匹配当前树
// depth 为深度，实际是 result 的字符串元素个数。从其后头遍历，
// depth-- 当 depth==-1 则到底层，不再递归
Status CompareHost(char** result,int depth,char* IP){
    if(Root->Left==NULL) return Error;

    Tree* tmp = Root;
    if(searchNode(tmp,tmp->Left,result,depth,IP)==Error) return Error;
    return OK;
}

Tree* insertOnLeft(Tree* fatherNode,char** result,int depth,char* IP){
    Tree* tmp = (Tree*)malloc(sizeof(Tree));

    strcpy(tmp->Name,result[depth]);
    
    fatherNode->Left = tmp;
    
    if(depth==0){
        strcpy(tmp->IP,IP);
    }

    return fatherNode->Left;
}

Tree* insertOnRight(Tree* fatherNode,char** result,int depth,char* IP){
    Tree* tmp = (Tree*)malloc(sizeof(Tree));
    
    strcpy(tmp->Name,result[depth]);

    fatherNode->Right = tmp;
    
    if(depth==0){
        strcpy(tmp->IP,IP);
    }

    return fatherNode->Right;
}

Status addNodeIfNotExist(Tree* fatherNode,Tree* node,char** result,int depth,char* IP){
    if (depth==-1) return Error;
    if (node==NULL) {
        // 一路增加新节点
        // 先增加兄弟节点，后循环增加孩子节点
        if (strlen(fatherNode->Name)==strlen("root")
        &&!strcmp(fatherNode->Name,"root")){
            fatherNode = insertOnLeft(fatherNode,result,depth,IP);
        } else {
            fatherNode = insertOnRight(fatherNode,result,depth,IP);
        }

        for(int i=depth-1;i>=0;i--){
            fatherNode = insertOnLeft(fatherNode,result,i,IP);
        }

        return OK;
    }
    
    if (strlen(node->Name)==strlen(result[depth])
    &&!strcmp(node->Name,result[depth])){
        addNodeIfNotExist(node,node->Left,result,depth-1,IP);
    } else {
        addNodeIfNotExist(node,node->Right,result,depth,IP);
    }
}

Status AddHost(char** result,int depth,char* IP){
    Tree* tmp = Root;
    if (addNodeIfNotExist(tmp,tmp->Left,result,depth,IP)==-1)
        return Error;
    return OK;
}

// 颠倒字符串
char* changeStr(char* target){
    int i=0,j=strlen(target)-1;
    char* new = (char*)malloc(sizeof(char)*strlen(target));
    strcpy(new,target);
    char tmp;
    while(i<j){
        tmp = new[i];
        new[i]=new[j];
        new[j]=tmp;
        i++;
        j--;
    }
    return new;
}

// 深度优先遍历
Status dfs(Tree* node,int index,char* strHost){
    if (node->Left==NULL&&node->Right==NULL){
        int len = strlen(node->Name);
        for (int i=len-1;i>=0;i--,index++){
            strHost[index] = node->Name[i];
        }
        strHost[index] = '\0';
        char* newStr = changeStr(strHost);
        printf("%s,%s\n",newStr,node->IP);
        free(newStr);
        return OK;
    }

    int len = strlen(node->Name);
    for (int i=len-1;i>=0;i--,index++){
        strHost[index] = node->Name[i];
    }
    strHost[index] = '.';
    index++;

    if (node->Left!=NULL){
        dfs(node->Left,index,strHost);
    }
    index = index - len - 1; 
    if (node->Right!=NULL){
        dfs(node->Right,index,strHost);
    }
}

Status ShowAllHost(){
    Tree* tmp = Root->Left;
    if (tmp==NULL) return Error;
    char strHost[20];
    int index = 0; // 用于回溯
    dfs(tmp,index,strHost);
    return OK;
}

Status dfsSave(Tree* node,int index,char* strHost,FILE* fp){
    if (node->Left==NULL&&node->Right==NULL){
        int len = strlen(node->Name);
        for (int i=len-1;i>=0;i--,index++){
            strHost[index] = node->Name[i];
        }
        strHost[index] = '\0';
        char* newStr = changeStr(strHost);
        // write
        fwrite(newStr,1,strlen(newStr),fp);
        fwrite(",",1,1,fp);
        fwrite(node->IP,1,strlen(node->IP),fp);
        fwrite(",\n",1,2,fp);
        free(newStr);
        return OK;
    }

    int len = strlen(node->Name);
    for (int i=len-1;i>=0;i--,index++){
        strHost[index] = node->Name[i];
    }
    strHost[index] = '.';
    index++;

    if (node->Left!=NULL){
        dfsSave(node->Left,index,strHost,fp);
    }
    index = index - len - 1; 
    if (node->Right!=NULL){
        dfsSave(node->Right,index,strHost,fp);
    }
}

Status SaveData(){
    FILE* fp = NULL;                                                        
    fp = fopen("./database/data.csv","w+");
    if (fp==NULL) return Error; // error

    Tree* tmp = Root->Left;
    if (tmp==NULL) return Error;
    
    char strHost[20];
    int index = 0; // 用于回溯
    
    dfsSave(tmp,index,strHost,fp);
    fclose(fp);
    return OK;
}

Status ReadData(char** result){
    FILE *fp = NULL;
    char *line;
    char *record;
    char buffer[1024];
    fp = fopen("./database/data.csv", "at+");
    if (fp== NULL) return -1;                                                          
 
    char* host;
    char* IP;
    int depth;
    while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL){
        record = strtok(line, ",");
        // set host
        host = record;
        // set ip
        record = strtok(NULL, ",");
        IP = record;
        // set tree
        depth = ResolveHost(host,strlen(host),result);
        AddHost(result,depth-1,IP);
    }
    fclose(fp);
}

Status dfsFree(Tree* node){
   if (node->Left==NULL&&node->Right==NULL){
        free(node);
        return OK;
    }

    if (node->Left!=NULL){
        dfsFree(node->Left);
    }
    if (node->Right!=NULL){
        dfsFree(node->Right);
    }
    free(node); 
}

Status FreeTree(){
    Tree* tmp = Root->Left;
    if (tmp==NULL) {
        free(Root);
        return OK;
    }

    dfsFree(tmp);
    free(Root);
    return OK; 
}