#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=1e6;
int T, N, C;
int x[MAX];
int mid;

bool canPlace(int d){
    int last=x[0];
    int c=1;
    for(int i=1; i<N; i++){
        if(x[i]-last >=d ){
            last=x[i];
            c++;
        }
        if(c==C)return true;
    }
    return false;

}

void solve(){
    sort(x,x+N);
    int hi=x[N-1]-x[0];
    int lo=0;
    int maxd=0;
    while(lo<=hi){
        mid= (hi+lo)/2;
        // cout<<lo<<' '<<hi<<' '<<mid<<' ';
        if(canPlace(mid)){
            lo=mid+1;
            maxd=mid;}
        else hi=mid-1;
    }
    cout<<maxd<<endl;
    return;
}
int main(){
    freopen("input.txt","r", stdin);
    cin>>T;
    while(T--){
        cin>>N>>C;
        for(int i=0; i<N; i++){
            cin>>x[i];
        }
        solve();

    }
    return 0;
}