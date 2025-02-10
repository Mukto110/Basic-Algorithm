#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int children : adj_list[par])
        {
            if (!visited[children])
            {
                q.push(children);
                visited[children] = true;
                level[children] = level[par] + 1;
                parent[children] = par; // just tracking the parent      
            }
        }
    }
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
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    int src, dist;
    cin >> src >> dist;
    bfs(src);

    int node = dist;

    while (node != -1)
    {
        cout << node << " ";
        node = parent[node];
    }
    return 0;
}