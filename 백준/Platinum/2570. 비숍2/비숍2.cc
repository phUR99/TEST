#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int board[105][105];
vector<int> diag1, diag2;
int diag1Cnt, diag2Cnt;
vector<bool> visited;
vector<set<int>> adj;
int group[105][105][2];
bool oob(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}
void grouping(int x, int y, int dir)
{
    if (!dir)
    {
        while (!oob(x, y) && group[x][y][0] == -1 && !board[x][y])
            group[x++][y++][0] = diag1Cnt;
        diag1Cnt++;
    }
    else
    {
        while (!oob(x, y) && group[x][y][1] == -1 && !board[x][y])
            group[x++][y--][1] = diag2Cnt;
        diag2Cnt++;
    }
}
bool dfs(int d1)
{
    if (visited[d1])
        return false;
    visited[d1] = true;
    for (auto d2 : adj[d1])
    {
        if (diag2[d2] == -1 || dfs(diag2[d2]))
        {
            diag1[d1] = d2;
            diag2[d2] = d1;
            return true;
        }
    }
    return false;
}

int bipartiteMatching()
{
    diag1 = vector<int>(diag1Cnt, -1);
    diag2 = vector<int>(diag2Cnt, -1);
    int ret = 0;
    for (int i = 0; i < diag1Cnt; i++)
    {
        visited = vector<bool>(diag1Cnt, 0);
        if (dfs(i))
            ret++;
    }
    return ret;
}
int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        board[x][y] = 1;
    }
    memset(group, -1, sizeof(group));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (group[i][j][0] == -1 && !board[i][j])
                grouping(i, j, 0);
            if (group[i][j][1] == -1 && !board[i][j])
                grouping(i, j, 1);
        }
    }
    adj.resize(diag1Cnt);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!board[i][j])
                adj[group[i][j][0]].insert(group[i][j][1]);
        }
    }
    int ret = bipartiteMatching();
    cout << ret;

    return 0;
}