#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool visited[105];
bool pathVisit[105];
bool cycle;

void dfs(int src)
{
    visited[src] = true;
    pathVisit[src] = true;
    for (int child : adj_list[src])
    {
        if (visited[child] && pathVisit[child])
            cycle = true;
        if (!visited[child])
        {
            dfs(child);
        }
    }
    pathVisit[src] = false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(visited, false, sizeof(visited));
    memset(pathVisit, false, sizeof(pathVisit));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    if (cycle)
        cout << "Cycle Detected";
    else
        cout << "No Cycle";
    return 0;
}