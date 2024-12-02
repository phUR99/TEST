#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int cache[505][505];
char board[505][505];
string dir = "DULR";
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool OOB(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}
int returnDir(char c)
{
    return dir.find(c);
}

int solve(int x, int y)
{
    if (OOB(x, y))
        return 1;
    int &ret = cache[x][y];
    if (ret != -1)
        return ret;
    ret = 0;
    int dir = returnDir(board[x][y]);
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    return ret = solve(nx, ny);
}
int main()
{
    fastio;
    cin >> n >> m;
    memset(cache, -1, sizeof(cache));
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
            ret += solve(i, j);
        }
    }
    cout << ret;
    return 0;
}