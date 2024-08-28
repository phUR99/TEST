#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int n, m;
int tmp_board[105][105], board[105][105];
vector<vector<int>> arr;
int cnt = 1;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool oob(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}
void bfs(int x, int y, int k)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    board[x][y] = k;
    while (!q.empty())
    {
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (oob(nx, ny))
                continue;
            if (tmp_board[nx][ny] == 0 || board[nx][ny] != 0)
                continue;
            board[nx][ny] = k;
            q.push({nx, ny});
        }
    }
}
int parent[10];
int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    parent[u] = v;
}
void find_dist(int x, int y)
{
    for (int dir = 0; dir < 4; dir++)
    {
        int cn = board[x][y];
        int nx = x;
        int ny = y;
        int dist = 0;
        while (1)
        {
            nx += dx[dir];
            ny += dy[dir];
            dist += 1;
            if (oob(nx, ny))
                break;
            if (board[nx][ny] == cn)
                break;

            if (board[nx][ny] != 0)
            {
                if (dist - 1 > 1)
                {
                    arr.push_back({dist - 1, cn, board[nx][ny]});
                }
                break;
            }
        }
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
            cin >> tmp_board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp_board[i][j] && board[i][j] == 0)
                bfs(i, j, cnt++);
        }
    }
    for (int i = 1; i < cnt; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j])
                find_dist(i, j);
        }
    }

    sort(arr.begin(), arr.end());
    int answer = 0;
    int edgeCnt = 0;

    for (auto a : arr)
    {

        int c = a[0];
        int u = a[1];
        int v = a[2];
        if (find(u) != find(v))
        {
            merge(u, v);
            edgeCnt++;
            answer += c;
        }
    }
    if (edgeCnt == cnt - 2)
        cout << answer;
    else
        cout << -1;

    return 0;
}