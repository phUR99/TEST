#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string str = "NSWE";
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int change(char c) { return str.find(c); }
char board[1005][1005];
bool visited[1005][1005];
bool finished[1005][1005];
int n, m;
bool dfs(int x, int y)
{
    bool ret = true;
    visited[x][y] = true;
    int nx = dx[change(board[x][y])] + x;
    int ny = dy[change(board[x][y])] + y;
    if (!visited[nx][ny])
        ret = dfs(nx, ny);
    else if (finished[nx][ny])
        ret = false;
    finished[x][y] = true;
    return ret;
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
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
                ret += dfs(i, j);
        }
    }
    cout << ret;
    return 0;
}