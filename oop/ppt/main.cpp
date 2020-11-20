#include "CPPage.h"

int main(){
	static int count = 1;

	CRect one(10,12,5,6,(char*)"hello world");
	one.ShowMsg();

	CEllipse two(30,50,6,(char*)"hello muxi");
	two.ShowMsg();

	CPPage page;
	page.Show();

	page.InsertCR(one);
	page.InsertCR(one);
	page.InsertCR(one);
	page.InsertCE(two);
	page.Show();

	// std::cout<<a<<b<<std::endl;
	
	return 0;
}
