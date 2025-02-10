#include <bits/stdc++.h>
using namespace std;
char grid[1000][1000];
bool visited[1000][1000];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

bool bfs(pair<int, int> roomA, pair<int, int> roomB)
{
    int si = roomA.first;
    int sj = roomA.second;
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        int par_i = q.front().first;
        int par_j = q.front().second;
        q.pop();

        if (par_i == roomB.first && par_j == roomB.second)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    pair<int, int> roomA;
    pair<int, int> roomB;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                roomA = {i, j};
            if (grid[i][j] == 'B')
                roomB = {i, j};
        }
    memset(visited, false, sizeof(visited));
    if (bfs(roomA, roomB))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}