#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n,m,k;
int load[12]={0};
int loadmin=1e6;
vector<int> canteach[15];
vector<int> conflict[30];
vector<int> teach[15];
bool check(int k, int v){
    if(find(canteach[v].begin(),canteach[v].end(),k) == canteach[k].end())return false;
    for(auto c : teach[v]){
        if(find(conflict[k].begin(), conflict[k].end(), c) != conflict[k].end())return false;
    }
    return true;
}
void update(){
    int maxload=load[0];
    for(int v =1; v<n; v++){
        if(load[v]>maxload)maxload=load[v];
    }
    if(loadmin>maxload)loadmin=maxload;
}
void solve(int k){
    for(int v =0; v<n; v++){
        if(check(k,v)){
            // cout<<v<<' '<<k<<' '<<endl;
            teach[v].push_back(k);
            load[v]++;
            if(k==m)update();
            else{
                solve(k+1);
            }
            teach[v].pop_back();
            load[v]--;
        }
    }
}

void input(){
    cin>>n>>m;
    int temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        canteach[i].push_back(temp);
    }
    cin>>k;
    int a,b;
    for(int i=0; i<k; i++){
        cin>>a>>b;
        conflict[a].push_back(b);
        conflict[b].push_back(a);
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    input();
    solve(1);
    cout<<loadmin;
    return 0;
}