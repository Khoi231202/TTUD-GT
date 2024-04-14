#include<iostream>
#include <queue>
using namespace std;

const int MN = 1000;
int d[MN][MN];
int maze[MN][MN];
int movex[] = {0,0,-1,1};
int movey[] = {1,-1,0,0};
int n,m, sx, sy, step=0;
queue <pair<int,int> > q;
int visited[MN][MN];


void input(){
    cin>> n >> m >> sx >> sy;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m; j++){
            cin>>maze[i][j];
        }
    }
    return;
}
bool check(int x, int y){
     if(visited[x][y]==1)return false;
     if (x<0 || x>n || y<0 || y>m){// neighbor nam ngoai maze
         return false;
     }
     if (maze[x][y] == 1){ //neighbor la hang rao
         return false;
     }
    return true;
}
bool isBorder(int x, int y){
    if( y==1 ||y==m ||x==1 || x==n ) return true;
    return false;
}
void bfs(){
    q.push(make_pair(sx,sy));
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(isBorder(x,y)){
            cout<<d[x][y]+1;
            return;
        }
        else{
            if(check(x,y)){
                visited[x][y]=1;
                for(int i=0;i<4;i++){
                    int u=x+movex[i];
                    int v=y+movey[i];
                    if(check(u,v)){
                    d[u][v]=d[x][y]+1;
                    q.push(make_pair(u,v));}
                }
            }
        }
    }
    cout<<-1;
    return;
}

int main(){
    input();
    bfs();
    return 0;
}