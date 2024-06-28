#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
char board[105][105];
int dist[105][105];
const int inf = 987654321;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct node
{
    int cost;
    pair<int, int> to;
    const bool operator<(const node &a) const{
        return a.cost < cost;
    }
};

int main(){
    fastio;
    cin >> M >> N;    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }        
        fill(dist[i], dist[i]+M, inf);
    }    
    dist[0][0] = 0;
    priority_queue<node> pq;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.cost > dist[cur.to.first][cur.to.second]) continue;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.to.first + dx[dir];
            int ny = cur.to.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] > cur.cost + (board[nx][ny] - '0')){
                dist[nx][ny] = cur.cost + (board[nx][ny] - '0');
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
        
    }
    cout << dist[N-1][M-1];

    return 0;
}