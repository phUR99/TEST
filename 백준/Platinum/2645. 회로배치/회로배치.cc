#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define x first
#define y second
using namespace std;
int n;
int board[55][55], dist[55][55];
pair<int, int> pre[55][55];
pair<int, int> st, ed;
int k, m;
int main()
{
    fastio;
    fill(&dist[0][0], &dist[50][50], 987654321);
    cin >> n;
    cin >> st.x >> st.y;
    cin >> ed.x >> ed.y;
    cin >> k >> m;
    for (int i = 0; i < m; i++)
    {
        int t;
        pair<int, int> cur, nxt;
        cur = {0, 0};
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            cin >> nxt.x >> nxt.y;
            if (cur.x == 0 && cur.y == 0)
                cur = nxt;
            else
            {
                for (int u = min(nxt.x, cur.x); u <= max(nxt.x, cur.x); u++)
                {
                    board[u][cur.y] = 1;
                }
                for (int v = min(cur.y, nxt.y); v <= max(nxt.y, cur.y); v++)
                {
                    board[cur.x][v] = 1;
                }
                cur = nxt;
            }
        }
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({1, st.x, st.y});
    dist[st.x][st.y] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (cur[0] > dist[cur[1]][cur[2]])
            continue;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur[1] + dx[dir];
            int ny = cur[2] + dy[dir];
            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            int nd = (board[nx][ny] == 1 ? k : 1) + cur[0];
            if (nd < dist[nx][ny])
            {
                dist[nx][ny] = nd;
                pre[nx][ny] = {cur[1], cur[2]};
                pq.push({nd, nx, ny});
            }
        }
    }
    cout << dist[ed.x][ed.y] << '\n';
    vector<pair<int, int>> answer;
    answer.push_back(ed);
    int dir = -1;
    auto now = ed;
    while (1)
    {
        if (now == st)
        {
            answer.push_back(st);
            break;
        }
        auto nxt = pre[now.x][now.y];
        if (nxt.x == now.x)
        {
            if (dir == 2)
            {
                answer.push_back(now);
            }
            dir = 1;
        }
        else
        {
            if (dir == 1)
            {
                answer.push_back(now);
            }
            dir = 2;
        }
        now = nxt;
    }

    cout << answer.size() << ' ';
    reverse(answer.begin(), answer.end());
    for (auto i : answer)
    {
        cout << i.x << ' ' << i.y << ' ';
    }

    return 0;
}