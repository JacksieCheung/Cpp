// p10_10
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    char line[100];
    fstream myfile;
    myfile.open("./data/data.txt",ios::out|ios::trunc);
    if(!myfile){
        cerr<<"File open create error!"<<endl;
        exit(1);
    }
    while(cin>>line) myfile<<line;
    myfile.close();
    return 0;
}