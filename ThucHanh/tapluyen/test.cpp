#include <iostream>
#include<vector>
using namespace std;

vector<int> v;
int main() {
    v.push_back(1);
    v.push_back(2);
    v.pop_back();
    for(auto t: v){
        cout<<t;
    }
    return 0;
}