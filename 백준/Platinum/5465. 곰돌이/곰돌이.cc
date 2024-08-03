#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
char board[805][805];
int dist[805][805], beeDist[805][805];

pair<int, int> bear, home;
int N, S;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool outBound(int x, int y){
    return x <0 || x >= N || y < 0 || y >= N;
}
bool notMatch(int x){
    if(x >= beeDist[bear.first][bear.second]) return true;
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push(bear);
    dist[bear.first][bear.second] = 0;    

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(outBound(nx, ny)) continue;
            if(dist[nx][ny] != -1) continue;
            if(!(board[nx][ny] == 'G' || board[nx][ny] == 'D')) continue;
            int spendTime = (dist[cur.first][cur.second] + 1)/S;
            if(spendTime + x >= beeDist[nx][ny]) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }        
    }
    return dist[home.first][home.second] == -1;
}




int main(){
    fastio;
    cin >> N >> S;
    memset(beeDist, -1, sizeof(beeDist));
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'M') {
                bear = {i ,j};
                board[i][j] = 'G';
            }
            if(board[i][j] == 'D') home = {i, j};
            if(board[i][j] == 'H'){
                q.push({i, j});
                beeDist[i][j] = 0;
            }
        }
        
    }

    beeDist[home.first][home.second] = 1987654321;
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(outBound(nx, ny)) continue;
            if(board[nx][ny] != 'G' || beeDist[nx][ny] != -1) continue;
            beeDist[nx][ny] = beeDist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }        
    }

    int st = 0;
    int ed = 1'000'000'000;    
    int ans = -1;

    while (st <= ed)
    {
        int mid = (st + ed) / 2;
        if(notMatch(mid)){
            ed = mid - 1;
        }
        else{
            st = mid + 1;
            ans = mid;
        }
    }
    cout << ans;
    

    return 0;
}