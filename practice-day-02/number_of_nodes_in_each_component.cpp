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
    vector<int> component_size;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            node_count = 0;
            dfs(i);
            component_size.push_back(node_count);
        }
    }

    sort(component_size.begin(), component_size.end());
    for (int size : component_size)
    {
        cout << size << " ";
    }
    cout << endl;
    return 0;
}