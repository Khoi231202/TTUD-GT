#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,a,b;
int ans=1;
struct segment{
    int a;
    int b;
    segment(int _a, int _b):a(_a), b(_b) {};
};
vector<segment> vseg;

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        vseg.push_back(segment(a,b));
    }
}
bool compareSegment(const segment &s1, const segment &s2){
    return s1.b<s2.b;
}
void solve(){
    sort(vseg.begin(),vseg.end(),compareSegment);
    int last=vseg[0].b;
    for(int i=1; i<vseg.size(); i++){
        if(vseg[i].a>last){
            ans++;
            last=vseg[i].b;
        }
    }
}
int main(){
    input();
    solve();
    cout<<ans;
    return 0;
}
