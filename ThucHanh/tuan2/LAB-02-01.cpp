#include <iostream>
#include<unordered_set>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> canteach[11];
unordered_set<int> conflict[31];
int day[31];
int load[11]={0};
int maxload=INFINITY;
int currentmaxload=0;
int n,m,k;

void input(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>k;
        int lop;
        for(int j=0; j<k; j++){
            cin>>lop;
            canteach[i].push_back(lop);
        }
    }
    cin>>k;
    int m1, m2;
    for(int i=1; i<=k; i++){
        cin>>m1>>m2;
        conflict[m1].insert(m2);
        conflict[m2].insert(m1);
    }
}
bool check(int GV, int mon){
    if( find(canteach[GV].begin(), canteach[GV].end(), mon) ==canteach[GV].end() ) return false;
    for( auto i : conflict[mon]){
        if( day[i] ==GV )return false;
    }
    return true;
}

void Try(int mon){
    for(int GV=1; GV<=n; GV++){
        if(check(GV,mon)){
            day[mon]=GV;
            load[GV]++;
            int a=currentmaxload;
            currentmaxload=max(load[GV], currentmaxload);
            if(mon==m){
                if(currentmaxload<maxload)maxload=currentmaxload;
            }
            if(currentmaxload<maxload)Try(mon+1);
            load[GV]--;
            currentmaxload=a;
            day[mon]=0;

        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    input();
    Try(1);
    cout<<maxload;
    return 0;


}
