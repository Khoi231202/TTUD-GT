#include <iostream> 
#include <stack>
using namespace std;

const int MAX= 1e4;
int hist[MAX];
int n,tp,area=0;
stack<int> st;

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>hist[i];
    }
}

int maxArea(){
    int i=0;
    while(i<n){
        if( st.empty() || hist[i] >= hist[st.top()]){
            st.push(i++);
        }
        else{
            tp=st.top();
            st.pop();
            area=max ((st.empty()? (i*hist[tp]) : (i-st.top()-1)*hist[tp]) , area);
        }
    }
    while(!st.empty()){
        tp=st.top();
        st.pop();
        area=max ((st.empty()? (i*hist[tp]) : (i-st.top()-1)*hist[tp]) , area);
    }
    return area;

}

int main(){
    freopen("input.txt", "r", stdin);
    input();
    cout<<maxArea();
    return 0;
}