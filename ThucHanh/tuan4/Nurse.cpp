#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 1e6;
const int MOD = 1e9+7;
int n,k1,k2;
int x[MAX]={0};

int dp(){
    x[0]=1;
    for(int i=1; i<=n; i++){
        for(int l=k1;l<=k2; l++){
            if(i-l==0)x[i]=(x[i]+x[0])%MOD;
            if(i-l>0){
                x[i]=(x[i]+x[i-l-1])%MOD;
            }
        }
    }
    return x[n]+x[n-1];
}

void input(){
    cin>>n>>k1>>k2;
}
int main(){
    input();
    cout<<dp();
    return 0;

}