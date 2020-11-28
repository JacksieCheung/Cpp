#include<iostream>

using namespace std;

class String{
    private:
        char *Str;
        int len;
    public:
        void ShowStr(){
            cout<<"string:"<<Str<<",length:"<<len<<endl;
        }

        String(const char* p = NULL){
            if (p){
                delete []Str;
            }
        }
};