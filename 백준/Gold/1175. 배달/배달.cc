#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dist[55][55][5][4];
char board[55][55];
int n, m;
int bfs(pair<int, int> st)
{
    queue<array<int, 4>> q;
    memset(dist, -1, sizeof(dist));
    q.push({st.first, st.second, 4, 0});
    dist[st.first][st.second][4][0] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur[0];
        int y = cur[1];
        int prev = cur[2];
        int state = cur[3];
        for (int dir = 0; dir < 4; dir++)
        {

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nd = dir;
            if (prev == nd)
                continue;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            int ns = isdigit(board[nx][ny]) ? (state | (1 << (board[nx][ny] - '0'))) : state;
            if (dist[nx][ny][nd][ns] != -1 || board[nx][ny] == '#')
                continue;
            dist[nx][ny][nd][ns] = dist[x][y][prev][state] + 1;
            q.push({nx, ny, nd, ns});
        }
    }
    int ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (dist[i][j][k][3] != -1)
                    ret = min(ret, dist[i][j][k][3]);
            }
        }
    }
    if (ret == 987654321)
        ret = -1;
    return ret;
}

int main()
{
    fastio;
    cin >> n >> m;
    pair<int, int> st;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
            {
                st = {i, j};
            }
            else if (board[i][j] == 'C')
            {
                board[i][j] = cnt + '0';
                cnt++;
            }
        }
    }
    int ret = bfs(st);
    cout << ret;

    return 0;
}