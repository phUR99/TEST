#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int parent[100005];
int board[2005][2005];
queue<pair<int, int>> q, city;
int N, K;
int cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
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
void uni()
{
    while (!city.empty())
    {
        auto cur = city.front();
        city.pop();
        q.push(cur);
        for (auto dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;
            int cn = board[cur.first][cur.second];
            int nn = board[nx][ny];
            if (nn != -1)
            {
                nn = find(nn);
                cn = find(cn);
                if (nn != cn)
                {
                    merge(nn, cn);
                    cnt--;
                }
            }
        }
    }
}
void bfs()
{
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (auto dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;

            int nn = board[nx][ny];
            if (nn == -1)
            {
                board[nx][ny] = board[cur.first][cur.second];
                city.push({nx, ny});
            }
        }
    }
}

int main()
{
    fastio;
    memset(board, -1, sizeof(board));

    cin >> N >> K;
    cnt = K;

    for (int i = 1; i <= K; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = i;
        parent[i] = i;
        city.push({x, y});
    }
    int answer = 0;
    while (1)
    {
        uni();
        if (cnt == 1)
        {
            cout << answer;
            return 0;
        }
        bfs();
        answer++;
    }

    return 0;
}