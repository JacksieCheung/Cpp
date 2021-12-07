#include<iostream>
#define Status int
#define OK 1;
#define ERROR 0;

// 赋值 从键盘输入
template<typename T,typename F> Status InputArray(T*** ptr,F m,F n);

// 输入 m 和 n
Status InputNum(int* m,int* n);

// 对数组的 创建 打印
template<typename T,typename F> Status Make2DArray(T*** ptr,F m,F n);
template<typename T,typename F> Status Print2DArray(T** ptr,F m,F n);

// 删除 int 数组
template<typename T,typename F> Status Delete2DArray(T*** ptr,F m);

// main函数，调用各函数
int main(){
	int n=0,m=0;
	InputNum(&m,&n);

	int** ptrInt;
	Make2DArray(&ptrInt,m,n);
	InputArray(&ptrInt,m,n);
	Print2DArray(ptrInt,m,n);
	Delete2DArray(&ptrInt,m);
	std::cout<<ptrInt<<std::endl;

	float** ptrFloat;
	Make2DArray(&ptrFloat,m,n);
	InputArray(&ptrFloat,m,n);
	Print2DArray(ptrFloat,m,n);
	Delete2DArray(&ptrFloat,m);
	std::cout<<ptrFloat<<std::endl;
	
	return 0;
}

// 从键盘输入赋值
template<typename T,typename F>
Status InputArray(T*** ptr,F m,F n){
	std::cout<<"please input values of your array:"<<std::endl;
	for (int i = 0;i<m;i++){
		for (int j = 0;j<n;j++){
			std::cin>>*(*(*ptr+i)+j);
		}
	}
	return OK;
}

// 删除数组
template<typename T,typename F>
Status Delete2DArray(T*** ptr,F m){
	for (int i=0;i<m;i++){
		delete[] (*(*ptr+i));
	}
	delete[](*ptr);
	*ptr = NULL;
	return OK;
}

// 输入 m n
Status InputNum(int* m,int* n){
	std::cout<<"please input m*n as array's length:(m n):"<<std::endl;
	std::cin>>*m>>*n;
	if (*m<=0||*n<=0) return ERROR;
	return OK;
}

// 建立数组
template<typename T,typename F>
Status Make2DArray(T*** ptr,F m,F n){
	*ptr = new T * [m];
	if (!*ptr) return ERROR;
	for (int i=0;i<m;i++){
		*(*ptr+i) = new T [n];
		if (!*(*ptr+i)) return ERROR;
	}
	return OK;
}

// 打印 int 数组
template<typename T,typename F>
Status Print2DArray(T** ptr,F m,F n){
	std::cout<<"Here is the int array you made:"<<std::endl;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			std::cout<<*(*(ptr+i)+j)<<" ";
		}
		std::cout<<std::endl;
	}
	return OK;
}
