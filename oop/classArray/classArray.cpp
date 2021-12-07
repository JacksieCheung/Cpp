// p7_10
#include<iostream>
#include<cstring>

using namespace std;

class Person{
    protected:
        char name[20];
    public:
        Person(char* iname){
            strcpy(name,iname);
        }

        virtual void who_am_I()=0; // 纯虚函数，在虚函数的基础上后面=0，且有virtual。因为这个，这个类才是抽象类
        
        virtual ~Person(){
            cout<<"~Person() called."<<endl;
        }
};

class Student:public Person{ // 从抽象类派生不用加 virtual, 加 virutal 是虚基类。解决二异性用的。
    private:
        char major[20];
    public:
        Student(char* iname,char* imajor):Person(iname){
            strcpy(major,imajor);
        }
        void who_am_I(){ // 定义虚函数不用加 virtual, 只要写函数实体就行了。
            cout<<"My name is "<<name<<", I major in "<<major<<endl;
        }
        ~Student(){
            cout<<"~Student() called."<<endl;
        }
};

class Teacher:public Person{
    private:
        char teach[20];
    public:
        Teacher(char* iname,char* iteach):Person(iname){
            strcpy(teach,iteach);
        }
        void who_am_I(){
            cout<<"My name is "<<name<<", I teach "<<teach<<endl;
        }
        ~Teacher(){
            cout<<"~Teacher() called."<<endl;
        }
};

int main(){
    Person* PersonArr[5];
    PersonArr[0] = new Student("Joe","computer");
    PersonArr[1] = new Teacher("Mary","mathmatics");
    PersonArr[2] = new Student("Jasmine","physics");
    PersonArr[3] = new Teacher("Antony","chemical");
    PersonArr[4] = new Student("Jayden","biology");
    for (int i=0;i<5;i++){
        PersonArr[i]->who_am_I();
        delete PersonArr[i];
	}

    return 0;
}