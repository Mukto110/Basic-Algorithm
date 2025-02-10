#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000000];
bool visited[1000000];

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

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (adj_list[x].empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            sort(adj_list[x].begin(), adj_list[x].end(), greater<int>());
            for (int child : adj_list[x])
            {
                cout << child << " ";
            }
            cout << endl;
        }
    }
    return 0;
}