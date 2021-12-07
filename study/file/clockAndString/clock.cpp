#include<iostream>

using namespace std;

class Clock {
	private:
		int H,M,S;
	public:
		Clock(int h=0,int m=0,int s=0){  // 构造函数无返回值，不用写void
			H=(h>=0&&h<24)?h:0;
			M=(m>=0&&m<60)?m:0;
			S=(s>=0&&s<60)?s:0;
		}

		void SetTime(int h,int m,int s){
			H=(h>=0&&h<24)?h:0;
			M=(m>=0&&m<60)?m:0;
			S=(s>=0&&s<60)?s:0;
		}

		void ShowTime(){  // 不一定要大写
			cout<<H<<" "<<M<<" "<<S<<endl;
		}

		~Clock(){
			cout<<"destructor:"<<H<<":"<<M<<":"<<S<<endl;
		}

		Clock(Clock &p){ // 拷贝函数 若为空则不拷贝。没有默认全拷贝。
			H=p.H; // 拷贝多少个自定义。
		} // 拷贝和赋值不一样。拷贝函数只在建立一个新对象时被调用。
};        // 而赋值是发生在两个对象已经存在的情况下，这时不调用。
          // 另外函数的传参，返回，都会调用拷贝函数。
		  // 注意这是浅拷贝，只赋值，不给变量分配空间。若有指针，会出错。

int main(){
	Clock MyClock;
	MyClock.ShowTime();
	MyClock.SetTime(8,30,45);
	MyClock.ShowTime();
	Clock YourClock(MyClock);
	YourClock.ShowTime();
	return 0;
}
