#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int board[5][5];
bool visited[5][5];
int n, m;
int dx[] = {0, 1};
int dy[] = {1, 0};

int calc(int s, int x, int y)
{
    int ret = 0;
    int dir = (s & 1 << (x * m + y)) ? 1 : 0;
    while (x < n && y < m)
    {
        if (visited[x][y])
            break;
        int nxtDir = (s & 1 << (x * m + y)) ? 1 : 0;
        if (dir != nxtDir)
            break;
        ret *= 10;
        ret += board[x][y];
        visited[x][y] = 1;
        x += dx[dir];
        y += dy[dir];
    }
    return ret;
}

int solve(int state)
{
    int ret = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                continue;
            ret += calc(state, i, j);
        }
    }
    return ret;
}

int main()
{
    fastio;

    cin >> n >> m;
    int full_bit = (1 << (n * m)) - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    int ret = 0;
    for (int state = full_bit; state >= 0; state--)
    {
        ret = max(ret, solve(state));
    }
    cout << ret;
    return 0;
}