#include<iostream>

using namespace std;

const int MaxN  = 100;

const double Rate = 0.6;

class Score {
	private:
		long No;
		char* Name;
		int Peace;
		int Final;
		int Total;
	public:
		Score(long = 0,char* = NULL,int =0,int =0,int =0);
		void Count();
		void ShowScore();
};

Score::Score(long no,char *name,int peace,int final,int total){
	No=no;
	Name=name;
	Peace=peace;
	Final=final;
	Total=total;
}

void Score::Count(){
	Total = Peace*Rate+Final;
}

void Score::ShowScore(){
	cout<<No<<"\t"<<Name<<"\t"<<Peace<<"\t"<<Final<<"\t"<<Total<<endl;
}

int main(){
	// Score ClassScore[3];
	// 调用三次构造函数
	Score ClassScore2[3]={
		Score(2019214228,(char*)"jacksie",80,79),
		Score(2019220114,(char*)"red",87,45),
		Score(2014521212,(char*)"id",45,78)};

	for (int i=0;i<3;i++){
		//ClassScore[i].Count();
		ClassScore2[i].Count();
	}

	for (int i=0;i<3;i++){
		//ClassScore[i].ShowScore();
		ClassScore2[i].ShowScore();
	}

	return 0;
}
