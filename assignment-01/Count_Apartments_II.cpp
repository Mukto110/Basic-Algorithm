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

void dfs(int i, int j, int &count)
{
    visited[i][j] = true;
    count++;
    for (int k = 0; k < 4; k++)
    {
        int ci = i + d[k].first;
        int cj = j + d[k].second;
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj, count);
    }
}

int main()
{
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<int> room_count;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.' && !visited[i][j])
            {
                int count = 0;
                dfs(i, j, count);
                room_count.push_back(count);
            }

    sort(room_count.begin(), room_count.end());
    if (room_count.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        for (int room : room_count)
            cout << room << " ";
    }
    return 0;
}