// 采用邻接矩阵方式表示
#include<iostream>
#include<limits.h>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define VRType int
#define InfoType char
#define VertexType int
#define Status int

typedef enum {DG,DN,UDG,UDN} GraphKind;

typedef struct ArcCell {
    VRType adj;     // 权
    InfoType *info; // 弧的相关信息
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点数组
    AdjMatrix arcs;                  // 弧的二维数组
    int vexnum,arcnum;               // 顶点和弧数
    GraphKind kind;                  // 图类型
}MGraph;

int LocateVex(MGraph& G,VertexType v){
    for (int i=0;i<G.vexnum;i++){
        if (G.vexs[i] == v){
            return i;
        }
    }
    return -1;
}

// 无向图
Status CreateUDN(MGraph& G){
    char IncInfo[100];
    printf("input two nums:\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    printf("input vexs:\n");
    for (int i=0;i<G.vexnum;i++) scanf("%d",&G.vexs[i]);

    for (int i=0;i<G.vexnum;i++){
        for (int j=0;j<G.vexnum;j++){
            G.arcs[i][j] = {0,NULL};
        }
    }

    int v1=0,v2=0,w=0;

    printf("input arcs:(节点，节点，权）\n");
    for (int k=0;k<G.arcnum;k++){
        scanf("%d %d %d",&v1,&v2,&w);
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        if (i==-1||j==-1){
            return -1;
        }
        
        G.arcs[i][j].adj = w;
    }
    return 1;
}

void PrintUDN(MGraph& G){
    printf("Here is result:\n");
    printf("\n  ");
    for (int i=0;i<G.vexnum;i++){
        printf("%2d",G.vexs[i]);
    }
    printf("\n");
    for (int i=0;i<G.vexnum;i++){
        printf("%2d",G.vexs[i]);
        for (int j=0;j<G.vexnum;j++){
            printf("%2d",G.arcs[i][j].adj);
        }
        printf("\n");
    }
}

int main(){
    MGraph* G = (MGraph*)malloc(sizeof(MGraph));
    CreateUDN(*G);
    PrintUDN(*G);
    return 0;
}