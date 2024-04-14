#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e5 +5;
int x[N];
int n,C,T;

bool P(int d) {
    int cnt=1;
    int last=x[1];
    for (int i=2;i<=n;i++){
        if(x[i]-last<d) continue;
        last =x[i];
        cnt++;

    }
    return cnt >= C;
}
void solve(){
    cin >> T;
    while (T--) {
        cin >> n >> C;
        for(int i = 1; i <= n;i++)cin >> x[i];
        sort(x+1 , x+n+1);
        int lo = 0, hi = x[n] - x[1];
        while(lo<hi-1){
            int mid= (lo + hi)/2;
            if (P(mid)) lo=mid;
            else hi=mid -1;
        }
        if(hi - lo <= 1) {
            if (P(hi)) cout << hi <<endl;
            else if( P(lo)) cout << lo <<endl;
        }
    }
}

int main(){
    solve();
    return 0;
}