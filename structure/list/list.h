#ifndef list_H_
#define list_H_
#define ElemType int
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define Status int

typedef struct {
	ElemType *elem;
    int length;
  	int listsize;
}SqList;

Status InitList(SqList* L);
Status TurnList(SqList* L);
Status PrintList(SqList* L);
Status SetList(SqList* L);
Status DestoryList(SqList* L);
Status ClearList(SqList* L);
Status ListEmpty(SqList* L);
Status ListLength(SqList* L);
Status GetElem(SqList* L);
Status Compare(ElemType a,ElemType b);
Status LocateElem(SqList* L,ElemType e,Status(*compare)(ElemType,ElemType));
#endif
