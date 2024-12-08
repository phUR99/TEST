#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int height(char c)
{
    if (c < 'a')
        return c - 'A';
    return c - 'a' + 26;
}
int n, m, t, d;
int board[26][26];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int hotel2Mountain[26][26];
int mountain2Hotel[26][26];

bool OOB(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}
int returnDist(int x, int y)
{
    if (x >= y)
        return 1;
    return (x - y) * (x - y);
}

int dijkstra(int dist[][26], pair<int, int> start)
{
    // 매개변수로 배열을 줄 때 주의하기(제대로 초기화가 안됐음)
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = 987654321;
        }
    }
    dist[start.first][start.second] = 0;
    priority_queue<array<int, 3>> pq;
    pq.push({0, start.first, start.second});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int cost = -cur[0];
        int x = cur[1];
        int y = cur[2];
        if (cost > dist[x][y])
            continue;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (OOB(nx, ny))
                continue;
            int nc = returnDist(board[x][y], board[nx][ny]);
            if (abs(board[nx][ny] - board[x][y]) > t)
                continue;
            if (nc + cost < dist[nx][ny])
            {
                dist[nx][ny] = nc + cost;
                pq.push({-dist[nx][ny], nx, ny});
            }
        }
    }
    return dist[0][0];
}
int main()
{
    fastio;
    cin >> n >> m >> t >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            board[i][j] = height(c);
        }
    }
    dijkstra(hotel2Mountain, {0, 0});
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (hotel2Mountain[i][j] + dijkstra(mountain2Hotel, {i, j}) <= d)
            {

                ret = max(board[i][j], ret);
            }
        }
    }
    cout << ret;
    return 0;
}