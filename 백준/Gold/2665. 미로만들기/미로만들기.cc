#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

char board[55][55];
int dist[55][55];

int N;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1 ,1};
bool black(char c){
    return c == '0';
}


int main(){
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }        
    }
    deque<pair<int, int>> dq;
    dq.push_back({0, 0});
    memset(dist, -1, sizeof(dist));
    dist[0][0] = black(board[0][0]);
    while (!dq.empty())
    {
        auto cur = dq.front(); dq.pop_front();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= N || ny <0 || ny >= N) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + black(board[nx][ny]);
            if(black(board[nx][ny])) dq.push_back({nx, ny});
            else dq.push_front({nx, ny});
        }        
    }
    cout << dist[N-1][N-1];
    
    return 0;
}