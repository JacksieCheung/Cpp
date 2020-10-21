#include<iostream>

int main(){
	int* p=(int*)malloc(sizeof(int)*5);
	int* tmp=p;
	for (int i=0;i<5;i++){
		*tmp=i;
		tmp++;
	}	
	std::cout<<&p<<" "<<*p<<std::endl<<p+1<<" "<<*(p+1)<<std::endl;
}
