// p10_1
#include<iostream>
#include<complex>
#include<string>

using namespace std;

int main(){
    char *s1 = "a c string";
    string s2("a c++ string");
    complex<double>c(3.14159,-1.234);
    int i(10);
    int *pi = &i;
    cout<<s1<<endl<<s2<<endl;
    cout<<c<<endl;
    cout<<i++<<'\t'<<i++<<'\t'<<i++<<endl;
    cout<<"&i:"<<'\t'<<"pi:"<<pi<<endl;
    cout<<"&s1:"<<&s1<<'\t'
    <<'s1:'<<(void*)s1<<endl;
    return 0;
}