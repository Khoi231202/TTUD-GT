#include<iostream>
using namespace std;
int main(){
    int n,b;
    cin>>n;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>b;
        a[i]=a[i-1]+b;
    }

    int Q;
    cin>>Q;
    int i,j;
    for(int k=0;k<Q;k++){
        cin>>i>>j;
        cout<<a[j]-a[i-1]<<endl;
    }

    return 0;
}
