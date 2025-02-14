#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
char board[105][105];
int group[105][105][2];
vector<int> row, col;
int n;
int rowCnt, colCnt;
vector<set<int>> adj;
vector<bool> visited;

void grouping(int x, int y, int dir)
{
    if (dir)
    {
        while (x < n && board[x][y] != 'X' && group[x][y][1] == -1)
        {
            group[x][y][dir] = colCnt;
            x++;
        }
        colCnt++;
    }
    else
    {
        while (y < n && board[x][y] != 'X' && group[x][y][0] == -1)
        {
            group[x][y][dir] = rowCnt;
            y++;
        }
        rowCnt++;
    }
}

bool dfs(int r)
{
    if (visited[r])
        return false;
    visited[r] = true;
    for (int c : adj[r])
    {
        if (col[c] == -1 || dfs(col[c]))
        {
            row[r] = c;
            col[c] = r;
            return true;
        }
    }
    return false;
}

int bipartiteMatching()
{
    row = vector<int>(rowCnt, -1);
    col = vector<int>(colCnt, -1);
    int ret = 0;
    for (int i = 0; i < rowCnt; i++)
    {
        visited = vector<bool>(rowCnt, 0);
        if (dfs(i))
            ret++;
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    memset(group, -1, sizeof(group));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 'X' && group[i][j][0] == -1)
                grouping(i, j, 0);
            if (board[i][j] != 'X' && group[i][j][1] == -1)
                grouping(i, j, 1);
        }
    }
    // cout << rowCnt << ' ' << colCnt << '\n';

    adj.resize(rowCnt);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (group[i][j][0] != -1)
            {
                adj[group[i][j][0]].insert(group[i][j][1]);
            }
        }
    }
    int ret = bipartiteMatching();
    cout << ret;

    return 0;
}