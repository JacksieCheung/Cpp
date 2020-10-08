#include<iostream>
#include "list.h"
#include<iomanip>

// 对线性表初始化并赋值，长度为10
Status InitList(SqList* L) {
	if (L){
		L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
		if (!L->elem) return ERROR;
		L->listsize = 10;
		L->length=0;

		// 默认赋值 0-9
		SetList(L);
		return OK;
	}
	return 0;
}

// 倒转线性表
Status TurnList(SqList* L) {
	if (L){
		ElemType* head=L->elem;
		ElemType* tail=head+L->length-1;
		int tmp=0;
		for (int i=0;i<L->length/2;i++){
			tmp=*head;
			*head=*tail;
			*tail=tmp;
			head++;
			tail--;
		}
		return OK;
	}
	return ERROR;
}

// 打印线性表
Status PrintList(SqList* L) {
	if (L){
		ElemType* ptr = L->elem;
		for (int i=0;i<L->length;i++){
			std::cout<<std::setw(4)<<*ptr;
			ptr++;
		}
		std::cout<<std::endl;
		return OK;
	}
	return ERROR;
}

// 为线性表赋值
Status SetList(SqList* L){
	if (L){
		ElemType* ptr=L->elem;
		for (int i=0;i<L->listsize;i++)	{
			*ptr=i;
			ptr++;
			L->length++;
		}
		return OK;
	}
	return ERROR;
}

// 销毁线性表
Status DestoryList(SqList* L){
	if (L){
		free(L->elem);
		L=NULL;
		return OK;
	} else {
		return ERROR;
	}
}

// 线性表清零
Status ClearList(SqList* L) {
	if (L){
		L->length=0;
		return OK;
	}
	return ERROR;
}

// 判断空表
Status ListEmpty(SqList* L){
	if (L){
		if (L->length==0) return OK;
	}
	return ERROR;
}

// 获取线性表长度
Status ListLength(SqList* L){
	if (L){
		return L->length;
	}
	return ERROR;
}

// 获取线性表指定第 n 个元素
Status GetElem(SqList* L,int i,ElemType* e){
	if (L&&i<L->length){
		ElemType* ptr=L->elem;
		*e=*(ptr+i);
		return OK;
	}
	return ERROR;
}

// 比较相等
Status Compare(ElemType a,ElemType b){
	if (a==b){
		return OK;
	}
	return ERROR;
}

// 指定元素和线性表比较，返回第一个相等的索引。
Status LocateElem(SqList* L,ElemType e,Status(*compare)(ElemType,ElemType)){
	if (L){
		int count=0;
		ElemType* ptr=L->elem;
		for (int i=0;i<L->length;i++){
			if (Compare(*ptr,e)){
				return count+1;
			}
			count++;
			ptr++;
		}
	}
	return ERROR;
}


