#include<string>
#include<iostream>
using namespace std;

int main(){
    const string string1 = ("ABCDEFGHI");
    string string2(string1);
    int length = string1.length();
    cout<<string1<<endl;
    cout<<string2<<endl;
    string::const_reverse_iterator itr1 = string1.rbegin();
    string::iterator itr2 = string2.begin();
    for (int i=0;i<length;i++) itr2[i] = itr1[i];
    cout<<string2<<endl;
    return 0;
}