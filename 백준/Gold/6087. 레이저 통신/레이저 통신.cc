#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
char board[105][105];
vector<pair<int, int>> arr;
int dist[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
struct node
{
    int cnt, dir, x, y;
    const bool operator<(const node &a) const
    {
        return a.cnt < cnt;
    }
};

int main()
{
    fastio;
    int N, M;

    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'C')
            {
                arr.push_back({i, j});
                board[i][j] = '.';
            }
        }
    }

    int answer = 987654321;
    for (int dir = 0; dir < 4; dir++)
    {
        priority_queue<node> pq;
        pq.push({0, dir, arr[0].first, arr[0].second});
        fill(&dist[0][0], &dist[100][100], 987654321);
        dist[arr[0].first][arr[0].second] = 0;
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (cur.cnt > dist[cur.x][cur.y])
                continue;
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;
                if (board[nx][ny] == '*' || abs(cur.dir - i) == 2)
                    continue;
                if (dist[nx][ny] > cur.cnt + (cur.dir != i))
                {
                    dist[nx][ny] = cur.cnt + (cur.dir != i);
                    pq.push({dist[nx][ny], i, nx, ny});
                }
            }
        }
        answer = min(answer, dist[arr[1].first][arr[1].second]);
    }

    /*
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dist[i][j] == 987654321)
                cout << "X ";
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    cout << answer;
    return 0;
}