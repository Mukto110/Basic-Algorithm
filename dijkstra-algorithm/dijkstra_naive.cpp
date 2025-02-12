#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[105];
int dist[105];

void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dist[src] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_node = par.first;
        int par_dist = par.second;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dist = child.second;
            if (par_dist + child_dist < dist[child_node])
            {
                dist[child_node] = par_dist + child_dist;
                q.push({child_node, dist[child_node]});
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
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dijkstra(0);
    for (int i = 0; i < n; i++)
        cout << i << " -> " << dist[i] << endl;
    return 0;
}