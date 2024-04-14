#include<iostream>
#include<map>
using namespace std;
map<string,int> numcall;
bool checknum(string fromnum){
    if(fromnum.length() != 10)return false;
    for (char ch :fromnum){
        int b=ch-'0';
        if(b<0||b>9)return false;
    }

    return true;
}
int main(){
    string fromnum;
    cin>>fromnum;
    if ( checknum(fromnum) )cout<<1;
    return 0;
}
