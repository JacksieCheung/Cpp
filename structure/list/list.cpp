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
