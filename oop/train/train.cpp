// p5_8
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

		int GetH(){
			return H;
		}

		int GetM(){
			return M;
		}

		int GetS(){
			return S;
		}
};

class TrainTrip{
	private:
		char* TrainNo;
		Clock StartTime;
		Clock EndTime;
	public:
		TrainTrip(char* TrainNo,Clock S,Clock E):StartTime(S),EndTime(E){ // 方法很多，这里不加：那一段也可以。但下面两个this要有
			// this->TrainNo=TrainNo;
			// this->StartTime=S;
			this->EndTime=E;
		}

		Clock TripTime(){
			int tH,tM,tS;
			int carry = 0;
			Clock tTime;
			(tS=EndTime.GetS()-StartTime.GetS())>0?carry=0:tS+=60,carry=1;
			(tM=EndTime.GetM()-StartTime.GetM()-carry)>0?carry=0:tM+=60,carry=1;
			(tH=EndTime.GetH()-StartTime.GetH()-carry)>0?carry=0:tH+=24;

			tTime.SetTime(tH,tM,tS);
			return tTime;
		}
};

int main(){
	Clock C3;
	TrainTrip T1((char*)"k16",Clock(8,10,10),Clock(6,1,2));
	C3=T1.TripTime();
	C3.ShowTime();
	return 0;
}


