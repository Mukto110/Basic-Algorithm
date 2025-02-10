#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int children : adj_list[parent])
        {
            if (!visited[children])
            {
                q.push(children);
                visited[children] = true;
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

    int src, dst;
    cin >> src >> dst;
    bfs(src);

    if (visited[dst])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> ";
    //     for (int x : adj_list[i])
    //         cout << x << " ";
    //     cout << endl;
    // }
    return 0;
}