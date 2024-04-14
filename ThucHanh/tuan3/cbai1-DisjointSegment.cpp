#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e5 +5;
int n;
struct Segment{
    int a,b;
    Segment(int _a,int _b):a(_a), b(_b) {};
};

vector<Segment> vSeg;

void input(){
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vSeg.push_back(Segment(a,b));
    }
}

bool SegmentCmp(const Segment &s1, const Segment &s2){
    return s1.b < s2.b;
}

int solve(){
    int ans = 1;
    sort(vSeg.begin(), vSeg.end(), SegmentCmp);
    int last=vSeg[0].b;
    for(int i=1;i<vSeg.size();i++){
        if(vSeg[i].a < last) continue;
        ans++;
        last=vSeg[i].b;
    }
    return ans;
}

int main(){
    // freopen("data.inp","r",stdin);
    input();
    cout<<solve()<<endl;
}