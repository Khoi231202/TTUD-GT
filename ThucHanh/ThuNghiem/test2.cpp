
using namespace std;


const int MAX=1e5;
const int MIN=-1e5;
int arr[MAX];
int n,m;
int i,j;

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


int main(){
    freopen("input.txt", "r", stdin);
    cin>>n;
    for( int i=0; i<n; i++){
        cin>>arr[i];
    }
    int* st = makeST();
    cin>>m;

    for( int i=0; i<m; i++){
        cin>>i>>j;
        cout<<getMax(0,0,n-1,st)<<endl;
    }
    for (int i = 0; i < 25; i++)
    {
        cout << *(st + i) << ' ';
    }
    return 0;
}