// p6_5
// 这是继承的二异性的问题。
#include<iostream>

using namespace std;

class Car {
	private:
		int power;
		int seat;
	public:
		Car(int power,int seat){
			this->power = power,this->seat = seat;
		}

		void show(){
			cout<<"car power:"<<power<<" seat:"<<seat<<endl;
		}
};

class Wagon {
	private:
		int power;
		int load;
	public:
		Wagon(int power,int load){
			this->power = power,this->load = load;
		}
		void show(){
			cout<<"wegon pwoer:"<<power<<" load:"<<load<<endl;
		}
};

class StationWagon: public Car,public Wagon{
	public:
		StationWagon(int powerA,int powerB,int seat,int load):Car(powerA,load),Wagon(powerB,seat){}
		
		void ShowSW(){
			cout<<"StationWagon:"<<endl;
			Car::show();  // 同名的通过成员名限定或者把这个派生类的这个成员改成同名覆盖解决二异性
			Wagon::show();
		}
};

int main(){
	StationWagon SW(105,106,3,8);
	SW.ShowSW();
	return 0;
}
