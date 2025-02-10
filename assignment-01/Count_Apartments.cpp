#include <bits/stdc++.h>
using namespace std;
char grid[1000][1000];
bool visited[1000][1000];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int number_of_apartment = 0;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int i, int j)
{
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int ci = i + d[k].first;
        int cj = j + d[k].second;
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
    }
}

int main()
{
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j);
                number_of_apartment++;
            }
    cout << number_of_apartment;
    return 0;
}