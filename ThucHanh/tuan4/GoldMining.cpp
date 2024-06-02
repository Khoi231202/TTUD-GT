#include<iostream>
// #include<algorithm>
using namespace std;
const int MAX=1e6;
int n,l1,l2;
int a[MAX];
int x[MAX];

void solve(){
    for(int i=0; i<n; i++){
        if(i<l1)x[i]=a[i];
        else {int m=0;
                for(int l=l1; l<=l2; l++){
                    if(l==l1) m=x[i-l];
                    else m=max(m,x[i-l]);
                }
                x[i]=m+a[i];
             }
    }
}
void input(){
    cin>>n>>l1>>l2;
    for(int i=0; i<n; i++)cin>>a[i];
}
int main(){
    input();
    solve();
    int res=0;
    for(int i=0;i<n;i++)res=max(res,x[i]);
    cout<<res;
    return 0;
}