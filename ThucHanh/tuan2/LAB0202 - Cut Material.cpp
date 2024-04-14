#include <bits/stdc++.h>
using namespace std;

const int HMAX = 35;
const int WMAX = 35;
const int N = 15;
int H, W;
int h[N], w[N];
int n;
bool mark[WMAX][HMAX];
int ans=0;
bool stop=false;

void fillMark(int x, int y, int height, int width, bool value){
    for(int i= x ; i< x +width;i++)
        for(int j=y; j<y+height;j++)
            mark[i][j]=value;
}
bool check(int x, int y, int k, int rot){
    if(!rot){
        for(int i=x;i<x+w[k];i++)
        for(int j=y;j<j+h[k];j++)
        if(mark[i][j])return false;
        return true;
    }
    else{

    }

}
void TRY(int k){
    if(stop) return;
    for (int x=0; x<= W-w[k]+1;x++)
        for(int y=0;y<=H-h[k]+1;y++){
            if(check(x,y,k)){
                fillMark(x,y,w[k],h[k],true);
                if ( k==n){
                    ans=1;
                    stop=true;
                }
                else TRY(k+1);
                fillMark(x,y,w[k],h[k],false);
            }
        }
}

int main(){
    cin>>H>>W>>n;
    for(int i=0; i<n; i++)
        cin>>h[i]>>w[i];
    TRY(1);
    cout<<ans<<endl;
    return 0;
}
