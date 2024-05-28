#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1e6;
int n, m;
bool visited[MAX] = {false};
vector<int> adj[MAX];
queue<int> q;
void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
}
void BFS(int k)
{
    q.push(k);
    visited[k] = true;

    while (!q.empty())
    {
        int a;
        a = q.front();
        q.pop();
        cout << a << ' ';
        for (auto v : adj[a])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    input();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            BFS(i);
    }
    return 0;
}
