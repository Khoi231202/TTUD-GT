#include <bits/stdc++.h>
using namespace std;
bool checksdt(string sdt){
    if(sdt.length!=10)return false;
    for(int i=0;i<10;i++){if(sdt[i]-'0'<0 || sdt[i]-'0'>10)return false;}
    return true;
}
int main(){
    string cmd,date,sdt1,sdt2,ftime,etime;
    int check=1,total=0;
    unordered_map<string,int> number;
    while(cmd!='#'){
        cin>>cmd>>date>>sdt1>>sdt2>>ftime>>etime;
        if(!(checksdt(sdt1)||checksdt(sdt2)))check=0;
        number["sdt1"]++;
        total++;

    }




    return 0;
}
