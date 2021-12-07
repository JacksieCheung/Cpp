#include<iostream>
#include "list.h"

int main(){
	SqList L;
	InitList(&L);
	PrintList(&L);
	{
		TurnList(&L);
		PrintList(&L);
	}
	{
		std::cout<<LocateElem(&L,9,Compare)<<std::endl;
	}
	{
		std::cout<<"priornext begin"<<std::endl;
		Status ok=0;
		ElemType pre_e=0;
		ElemType cur_e1=9;
		ok=PriorElem(&L,cur_e1,&pre_e);
		if (ok) std::cout<<pre_e<<std::endl;
		
		ElemType nex_e=0;
		ElemType cur_e2=0;
		ok=NextElem(&L,cur_e2,&nex_e);
		if (ok) std::cout<<nex_e<<std::endl;
		std::cout<<"priornext end"<<std::endl;
	}
	{
		// 插入
		ListInsert(&L,11,1);
		PrintList(&L);

		// 删除
		ElemType e=0;
		ListDelete(&L,11,&e);
		std::cout<<e<<std::endl;
		PrintList(&L);
	}
	{
		ClearList(&L);
		PrintList(&L);
	}
	{
		std::cout<<ListEmpty(&L)<<std::endl;
		std::cout<<ListLength(&L)<<std::endl;
		PrintList(&L);
	}
	DestoryList(&L);
	return 0;
}
