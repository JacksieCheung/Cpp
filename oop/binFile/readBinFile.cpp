// p10_13
#include<fstream>
#include<iostream>
using namespace std;

int main(){
    char name[8];
    float score;
    ifstream binfile;
    binfile.open("./data/data.dat",ios::binary);
    if(!binfile){
        cerr<<"open file error!"<<endl;
        exit(1);
    }
    while(!binfile.eof()){
        binfile.read(reinterpret_cast<char *>(name),8*sizeof(char));
        binfile.read(reinterpret_cast<char *>(&score),sizeof(float));
        cout<<name<<'\t'<<score<<endl;
    }
    binfile.close();
    return 0;
}