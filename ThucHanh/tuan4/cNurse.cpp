/*
Đếm sô xâu nhị phân độ dài N 
không chưa 2 số 0 liên tiếp
độ dài đoạn con 1 liên tiếp trong [K1,K2]

chia thành 2 lịai xâu
-bắt đầu từ 0: dp[i][0] = dp[i-1][1]
-bắt đầu từ 1: dp[i][1] = 
*/
#include<iostream>
using namespace std;
const int N = 1e4 + 5;
const int MOD = 1e9 +7;
int n, k1, k2;
int mem[N][2];

int dp(int i, int dig){
    if(i == 0) return 1;
    if(mem[i][dig] != -1) return mem[i][dig];
    int res = 0;
    for (int j = k1; j <= k2; j++)
        if(j<=i) res = (res +mem[i-j][0])%MOD;
    return mem[i][dig]=res;
}

int main(){
    memset(mem,-1,sizeof(mem));
    cin >> n >> k1 >>k2;
    cout << -((dp(n,0) + dp(n,1)) % MOD) << endl;
    return 0;
}