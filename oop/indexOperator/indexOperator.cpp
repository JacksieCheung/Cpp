#include<iostream>
#include<cstring>

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
                len = strlen(p);
                Str = new char[len+1];
                strcpy(Str,p);
            } else {
                len = 0;
                Str = NULL;
            }
        }

        ~String(){
            if (Str!=NULL) delete[] Str;
        }

        char &operator[](int n){ // 不重载要访问 str 成员
            return *(Str+n);
        }

        const char &operator[](int n)const{ // 处理 const 对象
            return *(Str+n);
        }
};

int main(){
    String S1("0123456789zbcdef");
    S1.ShowStr();
    S1[10] = 'A';
    S1.ShowStr();
    const String S2("ABCDEFGH");
    cout<<S2[10]<<endl;
    return 0;
}