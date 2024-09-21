#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int board[55][55];
int parent[300];
int n, m;
vector<vector<int>> arr;
void bfs(int x, int y)
{
    int dist[55][55];
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({x, y});
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int u = board[x][y];
    while (!q.empty())
    {
        auto cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nd = dist[x][y] + 1;
            if (board[nx][ny] == 1 || dist[nx][ny] != -1)
                continue;
            if (board[nx][ny] != 0)
            {
                int v = board[nx][ny];
                arr.push_back({nd, u, v});
            }
            dist[nx][ny] = nd;
            q.push({nx, ny});
        }
    }
}

int find(int u)
{
    if (u == parent[u])
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
int main()
{
    fastio;
    cin >> n >> m;
    int cnt = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if (c == '1' || c == '0')
            {
                board[i][j] = c - '0';
            }
            else
            {
                board[i][j] = cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1 || board[i][j] == 0)
                continue;
            bfs(i, j);
        }
    }
    for (int i = 1; i <= m + 1; i++)
    {
        parent[i] = i;
    }

    sort(arr.begin(), arr.end());
    int answer = 0;
    int cntt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int d = arr[i][0];
        int u = arr[i][1];
        int v = arr[i][2];
        if (find(u) == find(v))
            continue;
        cntt++;
        merge(u, v);
        answer += d;
    }
    if (cntt == m)
        cout << answer;
    else
        cout << -1;
    return 0;
}