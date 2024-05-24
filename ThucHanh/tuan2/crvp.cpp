#include<iostream>
#include<algorithm>
using namespace std;

const int MAX=1e5;
int segment=0, f_min=MAX, cmin=MAX, nbr;
int d[11];
int c[31][31];
int y[6]={0},x[14]={0};
int load[6]={0};
int f=0;
int n, K, Q;
bool visited[14];
void updateSol(){
    if(f<f_min)f_min=f;
}
bool checkX(int v, int k){
    if(v>0 && visited[v]==true) return false;
    if((load[k]+d[v])>Q)return false;
    return true;
}
void TRY_X(int s, int k){
    if(s==0){
        if(k<K) TRY_X(y[k+1], k+1);
        return;
    }
    for(int v=0; v<=n; v++){
        if(checkX(v,k)){
            x[s]=v;
            load[k]+=d[v];
            f+=c[s][v];
            segment++;
            if(v>0){
                if((f+(n+nbr-segment)*cmin )<f_min) TRY_X(v,k);
                else if(k==K){
                    if(segment==(n+nbr))updateSol();
                }else if((f+(n+nbr-segment)*cmin )<f_min) TRY_X(y[k+1],k+1);
            }
            load[k]-=d[v];
            f-=c[s][v];
            segment--;
        }
    }
}
bool checkY(int v, int k){
    if(v==0) return true;
    if((load[k] + d[v]) >Q) return false;
    if(visited[v])return false;
    return true;
}
void TRY_Y(int k){
    int s=0;
    if(y[k-1]>0) s=y[k-1]+1;
    for(int v=s;v<=n;v++){
        if(checkY(v,k)){
            y[k]=v;
            if(v>00){
                segment++;
                load[k]+=d[v];
                visited[v]=true;
                f+=c[0][v];
            }
            if(k==K){
                nbr=segment;
                TRY_X(y[1],1);
            }
            else TRY_Y(k+1);
            if(v!=0){
                segment--;
                load[k]-=d[v];
                visited[v]=false;
                f-=c[0][v];
            }
        }
    }
}
void input(){
    cin>>n>>K>>Q;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    for(int i =0; i<=n; i++){
        for(int j =0; j<=n; j++){
            cin>>c[i][j];
            if(c[i][j]<cmin)cmin=c[i][j];
    }
    }
}

int main(){
    fill(visited,visited+14,false);
    freopen("input.txt", "r", stdin);
    input();
    cout<<f_min;
    return 0;

}