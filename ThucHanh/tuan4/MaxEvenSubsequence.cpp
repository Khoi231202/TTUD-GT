#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX=1e6;
const int MIN=-1e6;
int n;
int a[MAX];
int h1[MAX];
int h2[MAX];

int solve(){
    h1[0]=MIN;
    h2[0]=a[0];
    int res=MIN;
    for(int i=1; i<n; i++){
        h1[i] = a[i]+h2[i-1];
        h2[i] = max(a[i], a[i]+h1[i-1]);
    }
    for(int i=0; i<n; i++){
        if(res<h1[i])res=h1[i];
    }
    return res;
}
void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
}
int main() {
    input();
    cout<<solve();
    return 0;
}
// -3 2 9

// -  -1 11 
// -3  2 9 