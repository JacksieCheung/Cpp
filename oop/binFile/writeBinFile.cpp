// p10_11
#include<fstream>
#include<iostream>
using namespace std;

int main(){
    char* name[3] = {"ANtony","John","Tom"};
    float score[3] = {85.5,90,60};
    fstream txtfile,binfile;
    txtfile.open("./data/data.txt",ios::out|ios::trunc);
    binfile.open("./data/data.dat",ios::binary|ios::out|ios::trunc);
    if(!txtfile){
        cerr<<"open file error"<<endl;
        exit(1);
    }
    if(!binfile){
        cerr<<"open file error"<<endl;
        exit(1);
    }
    for(int i=0;i<3;i++){
        txtfile<<name[i]<<'\t'<<score[i]<<endl;
        binfile.write(name[i],8*sizeof(char));
        binfile.write((char*)&score[i],sizeof(float));
    }
    txtfile.close();
    binfile.close();
    return 0;
}