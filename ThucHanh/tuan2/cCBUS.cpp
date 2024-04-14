#include <bits/stdc++.h>
using namespace std;

const int N=35;
const int INF = 1e9;
int n, maxCap,cmin;
int x[N];
bool visited[N];
int C[N][N];
int curCost=0,optCost = INF, curLoad=0;

bool check(int i, int k){
    if(visited[i])return false;
    if(i>n&&!visited[i-n]) return false;
    if(i<=n && curLoad == maxCap) return false;
    return true;
}
void updateSol(){
    if(curCost + C[x[2*n]][0]<optCost)
        optCost = curCost+C[x[2*n]][0];
}
void input(){
    cin>>n>>maxCap;
    for(int i=0;i<=2*n;i++){
        for( int j=0;j<=2*n;j++){
            cin>>C[i][j];
            if(i!=j) cmin=min(cmin,C[i][j]);
        }
    }
}

void TRY(int k){
    for(int i =1; i<= 2*n;i++){
        if(check(i,k)){
            x[k]=i;
            visited[i]=true;
            curCost += C[x[k-1]][i];
            if(i<=n) curLoad++;
            else curLoad--;
            if(k==2*n)updateSol();
            else {
                if (curCost + (2*n +1 -k) * cmin<optCost) TRY(k+1);
            }
            visited[i]=false;
            curCost -= C[x[k-1]][i];
            if( i<= n)curLoad--;
            else curLoad++;
        }
    }
}

int main(){
    input();
    x[0]=0;
    TRY(1);
    cout<<optCost;
    return 0;
}
