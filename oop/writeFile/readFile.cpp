// p10_12
#include<fstream>
#include<iostream>
using namespace std;

int main(){
    char name[8],score[6];
    ifstream txtfile;
    txtfile.open("./data/data.txt");
    if(!txtfile){
        cerr<<"file open error!"<<endl;
        exit(1);
    }
    while(!txtfile.eof()){
        txtfile>>name>>score;
        cout<<name<<'\n'<<score<<endl;
    }
    txtfile.close();
    return 0;
}