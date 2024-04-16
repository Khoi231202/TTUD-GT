//not complete
#include<iostream>
#include <cmath>
using namespace std;


const int MAX=1e7;
const int MIN=-1e7;
int arr[MAX];
int n,m;
int i,j;
string str;

int makeNode(int si, int L, int R, int* st){
    if(L==R){
        st[si]=arr[L];
        return st[si];
    }
    int mid=L+(R-L)/2;
    *(st+si) = max( makeNode(si*2+1,L,mid,st), makeNode(si*2+2,mid+1,R,st) );

    return st[si];
}

int* makeST(){
    // Height of segment tree
    int x = (int)(ceil(log2(n)));
 
    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;
 
    // Allocate memory
    int* st = new int[max_size];
    makeNode(0, 0, n-1, st);
    return st;
}

int getMax(int si, int L, int R, int* st){
    if (i > R || j < L)  return MIN;
    if(L>=i && R<=j){
        return st[si];
    }
    int mid=L+(R-L)/2;
    return max( getMax(si*2+1,L,mid,st), getMax(si*2+2,mid+1,R,st));
}

void update(int si, int L, int R, int* st,int i, int v){
    if(L>R)return;
    if(i<L || i>R)return;
    if(L==R && L==i){
        st[si] = max( v, st[si]);
        return;
    }
    int mid=L+(R-L)/2;
    update(si*2+1,L,mid,st,i,v);
    update(si*2+2,mid+1,R,st,i,v);
    st[si]=max(st[si*2+1],st[si*2+2]);
    return;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin>>n;
    for( int i=0; i<n; i++){
        cin>>arr[i];
    }
    int* st = makeST();
    cin>>m;

    for( int k=0; k<m; k++){
        cin>>str;
        if(str=="get-max"){
        cin>>i>>j;
        i--;
        j--;
        cout<<getMax(0,0,n-1,st)<<endl;
        }
        else{
            cin>>i>>j;
            i--;
            update(0,0,n-1,st,i,j);
        }
    }

    return 0;
}