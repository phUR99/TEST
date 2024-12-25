#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int board[1005][1005];
int discovered = 0;
int visited[1005][1005];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<int> group;

bool oob(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}
int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    group.push_back(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] || board[i][j])
                continue;
            int cnt = 1;
            visited[i][j] = ++discovered;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty())
            {
                auto here = q.front();
                q.pop();
                int x = here.first;
                int y = here.second;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = dx[dir] + x;
                    int ny = dy[dir] + y;
                    if (oob(nx, ny))
                        continue;
                    if (visited[nx][ny] || board[nx][ny])
                        continue;
                    cnt++;
                    visited[nx][ny] = discovered;
                    q.push({nx, ny});
                }
            }
            group.push_back(cnt);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                cout << 0;
            else
            {
                set<int> used;
                int cnt = 1;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = dx[dir] + i;
                    int ny = dy[dir] + j;
                    if (oob(nx, ny))
                        continue;
                    if (used.count(visited[nx][ny]) || board[nx][ny])
                        continue;
                    used.insert(visited[nx][ny]);
                    cnt += group[visited[nx][ny]];
                }
                cout << cnt % 10;
            }
        }
        cout << '\n';
    }
    return 0;
}