#include<iostream>

int main(){
	char a[4]="he";
	std::cout<<*a<<*(a+1)<<*(a+2)<<*(a+3)<<std::endl<<*(a+4)<<std::endl<<*(a+5)<<std::endl;
}
