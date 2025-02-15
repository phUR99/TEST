#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
char board[55][55];
vector<int> row, col;
vector<bool> visited;
vector<vector<bool>> adj;
int rowCnt, colCnt;
int group[55][55][2];

bool dfs(int r)
{
    if (visited[r])
        return false;
    visited[r] = true;
    for (int c = 0; c < colCnt; c++)
    {
        if (adj[r][c])
        {
            if (col[c] == -1 || dfs(col[c]))
            {
                row[r] = c;
                col[c] = r;
                return true;
            }
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
void grouping(int x, int y, int dir)
{
    if (!dir)
    {
        while (x < n && group[x][y][0] == -1 && board[x][y] == '*')
            group[x++][y][0] = rowCnt;
        rowCnt++;
    }
    else
    {
        while (y < m && group[x][y][1] == -1 && board[x][y] == '*')
            group[x][y++][1] = colCnt;
        colCnt++;
    }
}
int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    memset(group, -1, sizeof(group));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '*' && group[i][j][0] == -1)
                grouping(i, j, 0);
            if (board[i][j] == '*' && group[i][j][1] == -1)
                grouping(i, j, 1);
        }
    }
    adj.resize(rowCnt, vector<bool>(colCnt, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '.')
                continue;
            adj[group[i][j][0]][group[i][j][1]] = 1;
        }
    }
    int ret = bipartiteMatching();
    cout << ret;
    return 0;
}