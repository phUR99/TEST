#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int board[205][205];
int N, K;

vector<pair<int, int>> number[2005];
int dist[205][205];

int main(){
    fastio;
    cin >> N >> K;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if(board[i][j]) number[board[i][j]].push_back({i, j});
        }
        
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= K; i++)
    {
        for(auto cur : number[i]) {
            dist[cur.first][cur.second] = 0;
            q.push(cur);
        }
    }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int x, y, s;
    cin >> s >> x >> y;

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx <0 || nx >= N || ny <0 || ny >= N) continue;
            if(dist[nx][ny] != -1) continue;
            int nd = dist[cur.first][cur.second] + 1;
            if (nd > s) continue;
            dist[nx][ny] = nd;
            board[nx][ny] = board[cur.first][cur.second];
            q.push({nx, ny});
        }
        
    }
    cout << board[x-1][y-1];

    return 0;
}