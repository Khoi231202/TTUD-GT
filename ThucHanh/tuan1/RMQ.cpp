#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
// #include<algorithm>
using namespace std;

const int MAX = 1e6;
int a[MAX];
int M[30][MAX];
int n,m,l,r;
int res=0;


void preprocessing(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        M[0][i]=i;
    }

    for(int i=1;(1<<i) <= n;i++){
        for (int j=0; j<(n-(1<<i)+1); j++){
            if( a[M[i-1][j]] < a[M[i-1][j+(1<<(i-1))]] ) M[i][j] = M[i-1][j];
            else M[i][j] = M[i-1][j+(1<<(i-1))];
        }
    }
}

int RMQ(int i, int j)
{
    int k = log2(j - i + 1);
    int b = j - pow(2, k) + 1;
    if (a[M[k][i]] <= a[M[k][b]])
        return M[k][i];
    else
    {
        return M[k][b];
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    preprocessing();
    cin>>m;
    for( int i=0; i<m; i++){
        cin>>l>>r;
        res+=a[RMQ(l,r)];
    }
    cout<<res;
    
    return 0;
}
