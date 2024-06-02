#include<iostream>
using namespace std;

const int MAX= 1e5;
const int MIN=-1e6;
int n=MAX;
int a[MAX];
int dem=1;

void input(){
    a[0]=MIN;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]<a[i-1])dem++;
    }
}
int main(){
    input();
    cout<<dem;
}