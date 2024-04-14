#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int b[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+b[i][j];
        }
    }
    int r1, c1, r2, c2,Q;
    cin>>Q;
    for (int i=0;i<Q;i++){
        cin>>r1>>c1>>r2>>c2;
        cout<<b[r2][c2]-b[r1-1][c2]-b[r2][c1-1]+b[r1-1][c1-1]<<endl;
    }
    return 0;
}
