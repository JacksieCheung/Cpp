#include<iostream>

int main(){
	int m,n;
	int **dm;
	std::cout<<"input matrix size m,n:";
	std::cin>>m>>n;
	dm=new int*[m];
	for (int i=0;i<m;i++)
		if ((dm[i]=new int [n])==NULL)
			exit(0);
	
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			std::cin>>dm[i][j];
		}
	}
	
	for (int i=0;i<m;i++)
		delete[]dm[i];
	delete[]dm;
	return 0;
}
