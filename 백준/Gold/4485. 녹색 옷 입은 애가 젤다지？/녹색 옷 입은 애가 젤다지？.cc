#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int N;
int board[130][130];
int dist[130][130];
const int inf = 987654321;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
    int cnt = 1;
    fastio;
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> board[i][j];
                dist[i][j] = inf;
            }
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = board[0][0];
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int cx = cur.second.first;
            int cy = cur.second.second;

            if (cur.first > dist[cx][cy])
                continue;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                if (dist[nx][ny] > dist[cx][cy] + board[nx][ny])
                {
                    dist[nx][ny] = dist[cx][cy] + board[nx][ny];
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
        cout << "Problem " << cnt << ": " << dist[N - 1][N - 1] << '\n';
        cnt++;
    }

    return 0;
}