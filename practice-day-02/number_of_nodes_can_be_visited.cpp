#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int node_count = 0;

void dfs(int src)
{
    node_count++;
    visited[src] = true;
    for (int child : adj_list[src])
        if (!visited[child])
            dfs(child);
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
        adj_list[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    int src;
    cin >> src;
    dfs(src);
    cout << node_count << endl;
    return 0;
}