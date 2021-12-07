#include "CPPage.h"

int CPPage::count = 0;

int main(){
	CRect one(10,12,5,6,(char*)"hello world");
	one.ShowMsg();

	CEllipse two(30,50,6,(char*)"hello muxi");
	two.ShowMsg();

	CPPage page;
	page.count++;
	page.Show();
	std::cout<<page.count<<std::endl;

	// 插入
	std::cout<<"=============insert here=============="<<std::endl;
	page.InsertCRByObj(one);
	Code b = page.InsertCRByObj(one);
	Code c = page.InsertCRByObj(one);

	std::cout<<c.Code<<","<<c.Index<<std::endl;

	// 修改
	std::cout<<"==============modify here=============="<<std::endl;
	page.ModifyCRMsgById(c.Index,"oh my god");
	page.ModifyCRSizeById(c.Index,40,23,51,64);
	page.Show();

	// 删除
	std::cout<<"===============delete here=============="<<std::endl;
	page.DeleteCRByID(b.Index);
	page.Show();

	page.InsertCEByObj(two);
	page.Show();

	return 0;
}
