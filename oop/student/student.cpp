// p5_9
#include<iostream>
#include<cstring>

using namespace std;

class Student {
	private:
		char* Name;
		int No;
		static int countS;
	public:
		static int GetCount(){
			return countS;
		}

		Student(char* =(char*)"",int=0);
		Student(Student&);
		~Student();
};

int Student::countS=0;

Student::Student(char* c,int n){ // 初始化的只能在函数里面或者类声明里面。但是不能同时有。
	Name=new char[strlen(c)+1];
	strcpy(Name,c);
	No=n;
	++countS;
}

Student::Student(Student& S){
	Name=new char[strlen(S.Name)+1];
	strcpy(Name,S.Name);
	No=S.No;
	++countS;
}

Student::~Student(){
	delete []Name;
	--countS;
}

int main(){
	cout<<Student::GetCount()<<endl;
	Student s1((char*)"Antony");
	cout<<s1.GetCount<<endl;
	Student s2(s1);
	cout<<s1.GetCount()<<endl;
	Student S3[2];
	cout<<Student::GetCount()<<endl;
	Student* s4 = new Student[3];
	cout<<Student::GetCount()<<endl;
	delete[] s4;
	cout<<Student::GetCount()<<endl;
	return 0;
}
