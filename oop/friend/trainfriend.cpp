// p5_10
#include<iostream>

using namespace std;

class Clock {
	private:
		int H,M,S;
	public:
		void ShowTime(){
			cout<<H<<":"<<M<<":"<<S	<<endl;
		}

		void SetTime(int H=0,int M=0,int S=0){
			this->H=H;
			this->M=M;
			this->S=S;
		}

		// 构造函数
		Clock(int H=0,int M=0,int S=0){
			this->H=H;
			this->M=M;
			this->S=S;
		}

		friend Clock TripTime(Clock& StartTime,Clock& EndTime);
};
		
Clock TripTime(Clock& StartTime,Clock& EndTime){
	int tH,tM,tS;
	int carry = 0;
	Clock tTime;
	(tS=EndTime.S-StartTime.S)>0?carry=0:tS+=60,carry=1;
	(tM=EndTime.M-StartTime.M-carry)>0?carry=0:tM+=60,carry=1;
	(tH=EndTime.H-StartTime.H-carry)>0?carry=0:tH+=24;
	tTime.SetTime(tH,tM,tS);
	return tTime;
}

int main(){
	Clock C1(8,10,10),C2(6,1,2);
	Clock C3;
	C3=TripTime(C1,C2);
	C3.ShowTime();
	return 0;
}


