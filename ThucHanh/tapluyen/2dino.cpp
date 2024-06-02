#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int MAX = 1e5;
int n, p[MAX];
stack<int> st;
queue<int> qu;
string str;

void solve()
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'C')
        {
            if (!st.empty())
            {
                int temp = st.top();
                st.pop();
                qu.push(temp);
            }
        }
        else
        {
            if (!qu.empty)
            {
                int temp = qu.front();
                qu.pop();
                st.push(temp);
            }
        }
    }
}
void input()
{
    cin >> n;
    int a;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = n; i >= 1; i--)
    {
        st.push(p[i]);
    }
    cin >> str;
}
int main()
{
    input();
    solve();
    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}