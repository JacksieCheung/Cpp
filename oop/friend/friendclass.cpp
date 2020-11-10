#include<iostream>

using namespace std;

class TrainTrip;

class Clock {
	private:
		int H,M,S;
	public:
		void ShowTime(){
			cout<<H<<":"<<M<<":"<<S<<endl;
		}

		void SetTime(int H=0,int M=0,int S=0){
			this->H=H,this->M=M,this->S=S;	
		}

		Clock(int H=0,int M=0,int S=0){
			this->H=H,this->M=M,this->S=S;
		}

		friend class TrainTrip;
};

class TrainTrip {
	private:
		char* TrainNo;
		Clock StartTime;
		Clock EndTime;
	public:
		TrainTrip(char* TrainNo,Clock S,Clock E){
			this->TrainNo=TrainNo;
			StartTime=S;
			EndTime=E;
		}

		Clock TripTime(){
			int tH,tM,tS;
			int carry = 0;
			Clock tTime;
			// 当作为友元后，不需要再用 getS() 等接口函数访问 clock 类的私有成员。
			(tS=EndTime.S-StartTime.S)>0?carry=0:tS+=60,carry=1;
			(tM=EndTime.M-StartTime.M-carry)>0?carry=0:tM+=60,carry=1;
			(tH=EndTime.H-StartTime.H-carry)>0?carry=0:tH+=24;

			tTime.SetTime(tH,tM,tS);
			return tTime;
		}
};

int main(){
	TrainTrip T1((char*)"k16",Clock(8,10,10),Clock(6,1,2));
	Clock C3=T1.TripTime();
	C3.ShowTime();
	return 0;
}
