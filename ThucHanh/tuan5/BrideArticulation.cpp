#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e6;
vector<int> adj[MAX];
bool visited[MAX];
int disc[MAX], low[MAX], parent[MAX];
int timer = 0;
bool isAP[MAX];
int bridgeCount = 0, aCount = 0;
int N, M;

void DFS(int u)
{
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;
    for (auto v : adj[u])
    {
        if (parent[u] == v)
            continue;
        if (visited[v])
        {
            low[u] = min(low[u], disc[v]);
        }
        else
        {
            children++;
            parent[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1)
                isAP[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])
                isAP[u] = true;
            if (low[v] > disc[u])
                bridgeCount++;
        }
    }
}

void solve(int N)
{
    fill(parent, parent + N, -1);
    fill(visited, visited + N, false);
    fill(isAP, isAP + N, false);
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
            DFS(i);
    }
    for (int i = 1; i <= N; i++)
    {
        if (isAP[i]==true)aCount++;
    }
}

void input()
{
    cin >> N >> M;
    int x, y;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    input();
    solve(N);

    cout << aCount << ' ' << bridgeCount;
}