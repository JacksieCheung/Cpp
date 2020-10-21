#include<iostream>
#define Status int
#define OK 1;
#define ERROR 0;

Status InputNum(int* m,int* n);
Status Make2DArray(int*** ptr,int m,int n);
Status Print2DArray(int** ptr,int m,int n);
Status Make2DArray(float*** ptr,int m,int n);
Status Print2DArray(float** ptr,int m,int n);
Status Delete2DArray(int*** ptr,int m);
Status Delete2DArray(float*** ptr,int m);

int main(){
	int n=0,m=0;
	InputNum(&m,&n);

	int** ptrInt;
	Make2DArray(&ptrInt,m,n);
	Print2DArray(ptrInt,m,n);
	Delete2DArray(&ptrInt,m);
	std::cout<<ptrInt<<std::endl;

	float** ptrFloat;
	Make2DArray(&ptrFloat,m,n);
	Print2DArray(ptrFloat,m,n);
	Delete2DArray(&ptrFloat,m);
	std::cout<<ptrFloat<<std::endl;
	
	return 0;
}

Status Delete2DArray(int*** ptr,int m){
	for (int i=0;i<m;i++){
		free(*(*ptr+i));
	}
	free(*ptr);
	*ptr = NULL;
	return OK;
}

Status Delete2DArray(float*** ptr,int m){
	for (int i=0;i<m;i++){
		free(*(*ptr+i));
	}
	free(*ptr);
	*ptr = NULL;
	return OK;
}

Status InputNum(int* m,int* n){
	std::cout<<"please input m*n as array's length:(m n):"<<std::endl;
	std::cin>>*m>>*n;
	if (*m<=0||*n<=0) return ERROR;
	return OK;
}

Status Make2DArray(int*** ptr,int m,int n){
	*ptr = (int**)malloc(sizeof(int*)*m);
	if (!*ptr) return ERROR;
	// initalized to 0
	for (int i=0;i<m;i++){
		*(*ptr+m) = (int*)malloc(sizeof(int)*n);
		if (!*(*ptr+m)) return ERROR;
		*(*(*ptr+m)+n) = 0;
	}
	return OK;
}

Status Make2DArray(float*** ptr,int m,int n){
	*ptr = (float**)malloc(sizeof(float*)*m);
	if (!*ptr) return ERROR;
	// initalized to 0
	for (int i=0;i<m;i++){
		*(*ptr+m) = (float*)malloc(sizeof(float)*n);
		if (!*(*ptr+m)) return ERROR;
		*(*(*ptr+m)+n) = 0;
	}
	return OK;
}

Status Print2DArray(int** ptr,int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			std::cout<<*(*(ptr+m)+n)<<" ";
		}
		std::cout<<std::endl;
	}
	return OK;
}

Status Print2DArray(float** ptr,int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			std::cout<<*(*(ptr+m)+n)<<" ";
		}
		std::cout<<std::endl;
	}
	return OK;
}
