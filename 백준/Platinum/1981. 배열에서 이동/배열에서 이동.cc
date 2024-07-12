#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define X first
#define Y second

int board[105][105];
bool visited[105][105];
vector<int> value;
int dx[] = {-1, 1, 0 ,0};
int dy[] = {0, 0, -1, 1};

int N;

bool bfs(int left, int right){
    if(board[0][0] < left || board[0][0] > right) return false;
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(board[nx][ny] < left || board[nx][ny] > right) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return visited[N -1][N-1];
    
}

int main(){
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            value.push_back(board[i][j]);
        }        
    }
    sort(value.begin(), value.end());
    value.erase(unique(value.begin(), value.end()), value.end());
    int st =0, ed = 0;
    int ans = 201;
    

    while (st <= ed && ed < value.size())    
    {
        if(bfs(value[st], value[ed])){
            ans = min(ans, value[ed] -value[st]);
            st++;
        }
        else ed++;
    }
    
    cout << ans;
    return 0;
}

