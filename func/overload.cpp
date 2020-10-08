#include<iostream>
#include<iomanip>

void hello(int,int);
void hello(char);

int main()
{
	hello(1,2);
	hello('a');
	return 0;
}

void hello(int x,int y)
{
	std::cout<<x<<std::setw(4)<<y<<std::endl;
}

void hello(char x)
{
	std::cout<<x<<std::endl;
}
