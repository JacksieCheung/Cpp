#include<iostream>
#include<cstring>

using namespace std;

class String{
	private:
		char *Str;
		int len;
	public:
		String(){
			len=0;
			Str=NULL;
		}

		String(char *p){
			len=strlen(p);
			Str = new char[len+1];// 构造函数用 new 申请了空间
			strcpy(Str,p);
		}

		void ShowStr(){
			cout<<"string:"<<Str<<", length:"<<len<<endl;
		}

		~String(){ // 没有参数，不被重载，无返回值
			if (Str!=NULL){
				delete []Str; // 析构函数必须用delete清楚。
				Str=NULL;
			}
		}

		// 这是深拷贝,深拷贝还会分配内存，防止出现错误。
		String(String &p){
			len = p.len;
			if (len!=0){
				Str=new char[len+1];
				strcpy(Str,p.Str);
			}
		}
};

int main(){
	char s[]="ABCDE";
	String s1(s);
	String s2(s1);// “”这种类型在cpp里面是const char*类型
	s1.ShowStr();
	s2.ShowStr();
	return 0;
}
