// 这个是两个类继承同一个基类，然后再派生出一个基类时，会出现部分成员的二异性。
#include<iostream>

using namespace std;

class Automobile{
    private:
        int power;
    public:
        Automobile(int power){
            this->power=power;
        }
        void show(){
            cout<<" power:"<<power;
        }
};

class Car:virtual public Automobile{
    private:
        int seat;
    public:
        Car(int power,int seat):Automobile(power){
            this->seat = seat;
        }
        void show(){
            cout<<"car:";
            Automobile::show();
            cout<<" seat:"<<seat<<endl;
        }
};

class Wagon:virtual public Automobile{
    private:
        int load;
    public:
        Wagon(int power,int load):Automobile(power){
            this->load = load;
        }
        void show(){
            cout<<"wagon:";
            Automobile::show();
            cout<<" load:"<<load<<endl;
        }
};

// Car 和 Wagon 的 power 不一样，StationWagon 的 power 究竟是哪一个？
// 就是最远派生类也要调用基类的构造函数，中间的父基类都会被忽略
class StationWagon:public Wagon, public Car{
    public:
        StationWagon(int powerC,int powerW,int load,int seat):Automobile(powerW),Wagon(powerW,load),Car(powerC,load){};
        void show(){
            cout<<"stationWagon:"<<endl;
            Car::show();
            Wagon::show();
        }
};

int main(){
    StationWagon tmp(40,50,50,40);
    tmp.show();
    return 0;
}