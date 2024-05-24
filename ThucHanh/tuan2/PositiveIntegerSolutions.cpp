#include<iostream>
using namespace std;

const int MAX = 1e5;
int n, M;
int a[MAX];
int x[MAX];
int f=0;
int countans=0;
void TRY(int k){
    for(int i=1;i<=(M/a[k]) ; i++){
        x[k]=i;
        f=f+(i*a[k]);
        if(k==n){
            if(f == M) countans++;
        }else{
            if(f<M)TRY(k+1);
        }
        f=f-(i*a[k]);
    }
}
int main(){
    cin>>n>>M;
    for ( int i=1; i<=n; i++){
        cin>>a[i];
    }
    TRY(1);
    cout<<countans;
    return 0;
}