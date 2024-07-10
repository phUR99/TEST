#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int dir[] ={1, 2, 4, 8};
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int board[55][55];
int visited[55][55];
vector<int> area;

int main(){
    fastio;
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }        
    }
    memset(visited, -1, sizeof(visited));
    int cnt = 0;
    queue<pair<int, int>> q;

    int maxRoom = 0;
    int maxRoom2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(visited[i][j] != -1) continue;
            q.push({i, j});
            visited[i][j] = cnt;
            int maxTemp = 1;
            while (!q.empty())
            {
                auto cur = q.front(); q.pop();
                for (int d = 0; d < 4; d++)
                {
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];
                    if(nx < 0 || nx >= N ||ny < 0 || ny >= M) continue;
                    if(visited[nx][ny] != -1 || (board[cur.first][cur.second] & dir[d]) == dir[d]) continue;
                    visited[nx][ny] = cnt;
                    q.push({nx, ny});
                    maxTemp++;
                }                
            }
            maxRoom = max(maxRoom, maxTemp);
            area.push_back(maxTemp);
            cnt++;
        }        
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 2; k <= 3; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(visited[i][j] == visited[nx][ny]) continue;
                if(nx < 0 || nx >= N ||ny < 0 || ny >= M) continue;
                maxRoom2 = max(maxRoom2, area[visited[i][j]] + area[visited[nx][ny]]);
            }
            
        }        
    }
    cout << cnt << '\n' << maxRoom << '\n' << maxRoom2;
    return 0;
}