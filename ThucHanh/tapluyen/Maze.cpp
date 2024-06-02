#include<iostream>
#include<queue>

using namespace std;

int n,m,r,c;
int a[1000][1000];
int mx[4]={0, 0, 1, -1};
int my[4]={1, -1, 0, 0};
bool visited[1000][1000];

bool check(int x, int y){
    if(visited[x][y]==true)return false;
    if(a[x][y]==1)return false;
    return true;
}
bool isBorder(int a, int b){
    if( a==1 ||a==n ||b==1 || b==m ) return true;
    return false;
}
int solve(int r, int c){
    visited[r][c]=true;
    queue<pair<int,int>> qu;
    qu.push(make_pair(r,c));
    int d[1000][1000];
    d[r][c]=0;
    while(!qu.empty()){
        int a=qu.front().first;
        int b=qu.front().second;
        qu.pop();
        if(isBorder(a,b)) {
            cout<<d[a][b]+1;
            return 1 ;}
        for(int i=0; i<4; i++){
            int x=a+my[i];
            int y=b+mx[i];
            if(check(x,y)){
                qu.push(make_pair(x,y));
                visited[x][y]=true;
                d[x][y]=d[a][b]+1;
            }
    }
    }
    return 0;

}

void input(){
    cin>>n>>m>>r>>c;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++){
            visited[i][j]=false;
        }
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    input();
    if(!solve(r,c))cout<<-1;;
    return 0;
}