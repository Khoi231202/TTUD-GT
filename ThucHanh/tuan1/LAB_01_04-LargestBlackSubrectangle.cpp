#include<iostream>
#include<stack>
using namespace std;

const int MAX=1000;
int retangle[MAX][MAX];
int S[MAX][MAX];
int n,m;
int maxS=0, area = 0;

void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin >> retangle[i][j];
        }
    }
    for(int i=0;i<m;i++){
        S[0][i]=retangle[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0; j<m; j++){
            if(retangle[i][j]==0)S[i][j]=0;
            else S[i][j]=S[i-1][j]+1;
        }
    }
}

void maxAreaRow(int j){
    int i=0;
    stack<int> st;
    int tp;
    int hist[m];
    for(int i=0 ; i<m ; i++){
        hist[i]=S[j][i];
    }
    while(i<m){
        if( st.empty() || hist[i] >= hist[st.top()]){
            st.push(i++);
        }
        else{
            tp=st.top();
            st.pop();
            area= max((st.empty()? (i*hist[tp]) : (i-st.top()-1)*hist[tp]) , area);
        }
    }
    while(!st.empty()){
        tp=st.top();
        st.pop();
        area=max ((st.empty()? (i*hist[tp]) : (i-st.top()-1)*hist[tp]) , area);
    }
    return ;

}
void maxArea(){ 
    for(int i=0 ; i<n ; i++){
        maxAreaRow(i);
    } 
}

int main(){
    freopen("input.txt", "r", stdin);
    input();
    maxArea();
    cout<<area;

    return 0;
}