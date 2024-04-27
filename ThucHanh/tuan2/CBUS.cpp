#include<iostream>
#include<algorithm>
#include <time.h>
using namespace std;

clock_t start, endtime;
double duration;
int n,max_load,load=0;
int d[23][23];
int dmin=1e9;
int f=0, f_min=1e5;
bool visited[22]={false};
int x[23]={0};

void input()
{
    cin >> n >> max_load;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> d[i][j];
            if(d[i][j]!=0)dmin = min(dmin, d[i][j]);
        }
    }
}
bool check(int v, int k){
    if(visited[v])return false;
    if(v<=n && load==max_load )return false;
    if(v>n && visited[v-n]==false) return false;
    return true;
}
void updateAns(){
    if( (f+d[x[2*n]][0]) < f_min) f_min=f+d[x[2*n]][0];
    return;
}

void TRY(int k){
    for(int v=1;v<=2*n ; v++){
        if(check(v,k)) {
            visited[v]=true;
            x[k]=v;
            f=f+d[x[k-1]][v];
            if(v<=n)load++;
            else load--;
            if(k==2*n)updateAns();
            else if((f+dmin*(2*n-k+1))<f_min) TRY(k+1);
            f=f-d[x[k-1]][v];
            visited[v]=false;
            if(v<=n)load--;
            else load++;
        }
    }
}

int main(){
    start=clock();
    freopen("input.txt","r", stdin);
    input();
    TRY(1);
    cout<<f_min;
    endtime = clock();
    duration = (double)(endtime - start) / CLOCKS_PER_SEC;
    cout<<duration;
    return 0;
}
