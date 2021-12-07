#include<iostream>

long int func(long int sum,int *n){
	if (*n==1){
		return sum;
	}
	sum *= *n;
	long int nextSum = sum*((*n)-1);
	if (nextSum<sum||nextSum/((*n)-1)!=sum) return sum;
	(*n)-=1;
	return func(sum,n);
}

int func(int sum,int *n){
	if (*n==1){
		return sum;
	}
	sum *= *n;
	int nextSum = sum*((*n)-1);
	if (nextSum<sum||nextSum/((*n)-1)!=sum) return sum;
	(*n)-=1;
	return func(sum,n);
}

double func(double sum,int *n){
	if (*n==1){
		return sum;
	}
	sum *= *n;
	double nextSum = sum*((*n)-1);
	if (nextSum<sum||nextSum/((*n)-1)!=sum) return sum;
	(*n)-=1;
	return func(sum,n);
}

void modeLongInt(){
	int n;
	long int sum = 1;
	std::cout<<"input an number n (long int) to calculate n!>";
	std::cin>>n;
	std::cout<<"Here is result:"<<std::endl;
	std::cout<<func(sum,&n)<<std::endl;
	if (n!=1) std::cout<<"sum is overflow"<<std::endl;
	std::cout<<"n is "<<n<<std::endl;
}

void modeInt(){
	int n;
	int sum = 1;
	std::cout<<"input an number n (int) to calculate n!>";
	std::cin>>n;
	std::cout<<"Here is result:"<<std::endl;
	std::cout<<func(sum,&n)<<std::endl;
	if (n!=1) std::cout<<"sum is overflow"<<std::endl;
	std::cout<<"n is "<<n<<std::endl;
}

void modeDouble(){
	int n;
	double sum = 1;
	std::cout<<"input an number n (double) to calculate n!>";
	std::cin>>n;
	std::cout<<"Here is result:"<<std::endl;
	std::cout<<func(sum,&n)<<std::endl;
	if (n!=1) std::cout<<"sum is overflow"<<std::endl;
	std::cout<<"n is "<<n<<std::endl;
}

int main(){
	modeLongInt();
	modeInt();
	modeDouble();
	return 0;
}
