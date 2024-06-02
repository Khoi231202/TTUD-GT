#include<iostream>
using namespace std;

int T,n;
int h,u,s,t,o,i,c;
int a[7]={0};//0:h 1:u 2:s 3:t 4:o 5:i 6:c
int f=0;
int D[30];
bool visited[12]={false};
int res[30]={0};

bool check(int k, int i){
    if(visited[i]==true)return false;
    if(k==0 && i==0)return false;
    if(k==2 && i==0)return false;
    return true;
}
void update(){
    int sum = a[0]*1000+a[1]*100+a[2]*10+a[3] + a[2]*10000+a[4]*1000+a[5]*100+a[6]*10+a[3];
    for(int i=0;i<T;i++){
        if(sum==D[i])res[i]++;
    }
    return;
}
void solve(int k){
    for(int i=0; i<10; i++){
        if(check(k,i)){
            a[k]=i;
            visited[i]=true;
            if(k==6) update();
            else solve(k+1);
            visited[i]=false;
        }
    }
}

int main(){
    cin>>T;
    for(int i=0; i<T; i++)cin>>D[i];
    solve(0);
    for(int i=0; i<T; i++)cout<<res[i]<<endl;
    return 0;
}