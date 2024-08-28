#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int parent[100005];
int board[2005][2005];
int dist[2005][2005];

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

int main()
{
    fastio;
    memset(board, -1, sizeof(board));
    memset(dist, -1, sizeof(dist));
    int N, K;
    int cnt;
    cin >> N >> K;
    cnt = K;
    queue<pair<int, int>> q;
    for (int i = 1; i <= K; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = i;
        parent[i] = i;
        q.push({x, y});
        dist[x][y] = 0;
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (auto dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            int nd = dist[cur.first][cur.second] + 1;
            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;
            int cn = board[cur.first][cur.second];
            int nn = board[nx][ny];
            if (nn == -1)
            {
                board[nx][ny] = cn;
                dist[nx][ny] = nd;
                q.push({nx, ny});
            }
            else
            {
                nn = find(nn);
                cn = find(cn);
                if (nn != cn)
                {
                    merge(nn, cn);
                    cnt--;
                    if (cnt == 1)
                    {
                        // cout << nd - 1;
                        /*
                        for (int i = 1; i <= N; i++)
                        {
                            for (int j = 1; j <= N; j++)
                            {
                                if (dist[i][j] == -1)
                                    cout << "x ";
                                else
                                    cout << dist[i][j] << ' ';
                            }
                            cout << '\n';
                        }
                        */
                        cout << dist[nx][ny];
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}