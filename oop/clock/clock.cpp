#include<iostream>

using namespace std;

// 不太需要析构函数，没有分配内存
class Clock{
	private:
		int H,M,S;
	public:
		Clock(int h=0,int m=0,int s=0){
			H=h,M=m,S=s;
		}

		// 拷贝函数
		Clock(Clock& c){
			H=c.H,M=c.M,S=c.S;
			// this->H=c.H,this->M=c.M,this->S=c.S;
			// (*this).H=c.H,(*this).M=c.M,(*this).S=c.S;
		}

		void SetTime(int h,int m,int s){
			H=h;M=m;S=s;
		}

		void ShowTime(){
			cout<<H<<":"<<M<<":"<<S<<endl;
		}

		void TimeAdd(Clock* c);
		void TimeAdd(int h,int m,int s);
		void TimeAdd(int s);
};

void Clock::TimeAdd(Clock* c){
	H=(c->H+H+(c->M+M+(c->S+S)/60)/60)%24;
	M=(c->M+M+(c->S+S)/60)%60;
	S=(c->S+S)%60;
}

void Clock::TimeAdd(int h,int m,int s){
	H=(h+H+(m+M+(s+S)/60)/60)%24;
	M=(m+M+(s+S)/60)%60;
	S=(s+S)%60;
}

void Clock::TimeAdd(int s){
	H=(H+(M+(S+s)/60)/60)%24;
	M=(M+(S+s)/60)%60;
	S=(S+s)%60;
}

int main(){
	Clock* ptr = NULL; // 声明指针没有声明对象，不调用构造函数
	Clock C1;
	Clock C2(8,20,20);
	C1.TimeAdd(4000);
	C1.ShowTime();
	C2.TimeAdd(&C1);
	C2.ShowTime();
	ptr=&C2;
	ptr->ShowTime();

	// 对象引用，在初始化时必须定义。
	Clock& Cr = C1;
	Cr.ShowTime();
	return 0;
}
