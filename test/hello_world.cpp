#include <iostream> //包含标准输入输出流的头文件，C++中的输入输出用流表示
using namespace std; //C++大部分的函数接口在std命名空间里，写C++程序一般都要包含std命名空间

int main()
{
    /*cout是c out，表示打印输出，endl表示回车换行，如果没有包含命名空间std，则应该写成std::cout << "Hello world" << endl; ,cout函数支持连续的<<输出，例如：cout << "Hello" << " world" << endl; 输出效果相同*/
    cout << "Hello world" << endl; 
    return 0;
}
