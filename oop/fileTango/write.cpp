#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Tango{
    private:
        int AddX;
        int AddY;
        char Message[100];
    public:
        Tango(int x=0,int y=0,char* Message=""){
            this->AddX = x;
            this->AddY = y;
            strcpy(this->Message,Message);
        }
        int GetX(){
            return this->AddX;
        }
        int GetY(){
            return this->AddY;
        }
        char* GetMessage(){
            return this->Message;
        }
};

void writeBin(Tango* t){
    fstream binfile;
    binfile.open("./data/data.dat",ios::binary|ios::out|ios::trunc);
    if(!binfile){
        cerr<<"open file error"<<endl;
        exit(1);
    }
    int x = t->GetX(),y = t->GetY();
    char* message = t->GetMessage();
    binfile.write((char*)&x,sizeof(int));
    binfile.write((char*)&y,sizeof(int));
    binfile.write(message,sizeof(char)*100);
    binfile.close();
}

void write(Tango* t){
    fstream myfile;
    myfile.open("./data/data.txt",ios::out|ios::trunc);
    if(!myfile){
        cerr<<"File open error."<<endl;
        exit(1);
    }
    myfile<<t->GetX()<<'\t'<<t->GetY()<<'\t'<<t->GetMessage()<<'\n';
    myfile.close();
    return;
}

Tango* readBin(){
    ifstream binfile;
    binfile.open("./data/data.dat",ios::binary);
    if (!binfile){
        cerr<<"open file error"<<endl;
        exit(1);
    }
    int x,y;
    char message[100];
    while(!binfile.eof()){
        binfile.read(reinterpret_cast<char *>(&x),sizeof(int));
        binfile.read(reinterpret_cast<char *>(&y),sizeof(int));
        binfile.read(reinterpret_cast<char *>(message),100*sizeof(char));
    }

    Tango* ptr = new Tango(x,y,message);
    return ptr;
}

Tango* read(){
    ifstream myfile;
    myfile.open("./data/data.txt");
    if(!myfile){
        cerr<<"file open error!"<<endl;
        exit(1);
    }
    int x=0;
    int y=0;
    char message[100];
    while(!myfile.eof()){
        myfile>>x>>y>>message;
    }
    Tango* p = new Tango(x,y,message);
    return p;
}

int main(){
    Tango t(1,2,"hello,world");
    // write(&t);
    // writeBin(&t);

    Tango* p = readBin();
    // Tango* p = read();
    cout<<p->GetX()<<p->GetY()<<p->GetMessage()<<endl;
    return 0;
}