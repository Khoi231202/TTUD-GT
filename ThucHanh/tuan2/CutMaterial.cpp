#include<iostream>
#include<vector>
#include <utility>
using namespace std;

int H,W,n;
int h,w;
vector< pair<int,int> > rec,sol;
int a[20]={0};
bool state=false;

void input(){
    cin>>H>>W>>n;
    for(int i=0; i<n; i++){
        cin>>h>>w;
        rec.push_back(make_pair(h,w));
    }
}
bool check(int x, int y, int k){
    if((x+rec[k].first-1>H-1)||(y+rec[k].second-1>W-1))return false;
    if(k==0)return true;
    else{
        for(int i=0;i<k-1;i++){
            if((sol[i].first>x+rec[k].first-1)||(sol[i].second>y+rec[k].second-1)
            ||(rec[k].first>sol[i].first+rec[i].first-1)||(rec[k].second>sol[i].second+rec[i].second-1))return true;
        }
    }
    return false;
}
void xoay(int k){
    int t;
    t=rec[k].first;
    rec[k].first=rec[k].second;
    rec[k].second=t;
    
}

void TRY(int k){
    if(!state){
        for(int x=0; x<H; x++){
            for(int y=0; y<W; y++){
                if(check(x,y,k)){
                    sol.push_back(make_pair(x,y));
                    if(k==n-1)state=true;
                    TRY(k+1);
                    sol.pop_back();
                }
                xoay(k);
                a[k]=1;
                if(check(x,y,k)){
                    sol.push_back(make_pair(x,y));
                    if(k==n-1)state=true;
                    TRY(k+1);
                    sol.pop_back();
                }
                xoay(k);
                a[k]=0;
            }
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    input();
    TRY(0);
    cout<<state;
    return 0;
}