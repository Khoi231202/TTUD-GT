#include<iostream>
#include<unordered_map>
#include <sstream>
using namespace std;

string str,fromnum,tonum, date, fromtime, totime;
int check=1,total=0;
unordered_map <string,int> numcall;
unordered_map<string,int> calltime;

bool checknum(string fromnum, string tonum){
    if(fromnum.length() != 10)return false;
    for (char ch :fromnum){
        int b=ch-'0';
        if(b<0||b>9)return false;
    }
    if(tonum.length() != 10)return false;
    for (char ch :tonum){
        int b =ch-'0';
        if(b<0||b>9)return false;
    }  
    return true;
}
int strtoint(string str){
    stringstream ss(str);
    int hh,mm,s;
    char c;
    ss>> hh >> c >> mm >> c >> s;
    return hh*3600+mm*60+s;
}

void inputt(){
    int ft,tt,time;
    while (1)
    {
        cin >> str;
        if(str == "#")break;
        cin >> fromnum >> tonum >> date >> fromtime >> totime;
        if (!checknum(fromnum, tonum)) check = 0;
        numcall[fromnum]+=1;
        total++;
        ft= strtoint(fromtime);
        tt= strtoint(totime);
        time=tt-ft;
        calltime[fromnum]+=time;
    }

    return ;
}
void queryy(){
        while (1)
    {
        cin>>str;
        if(str == "#") break;
        if(str=="?check_phone_number") cout<<check<<endl;
        if(str=="?number_calls_from"){
            cin>>fromnum;
            cout << numcall[fromnum]<<endl;
        }
        if(str=="?number_total_calls")cout<<total<<endl;
        if(str=="?count_time_calls_from"){
            cin>>fromnum;
            cout<< calltime[fromnum]<<endl;
        }
    }
    return ;
}
int main(){
    inputt();
    queryy();
    return 0;
}