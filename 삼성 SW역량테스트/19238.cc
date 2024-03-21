#include <bits/stdc++.h>
using namespace std;
int n, m, init;
/*
point 1 : dist[nx][ny] != -1 조건을 갈 때도, 올 때도 잡아줘야 한다.
*/  

struct info
{
    int px, py;
    int gx, gy;
};
info node[405];
int board[25][25][3];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y){
    return x <= 0 || x > n || y <=0 || y > n;
}

void move(int cur, int st, int ed){
    if(cur == m){
        cout << init;
        return;
    }
    int dist[25][25];
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push({st, ed});
    dist[st][ed] = 0;
    while (!q.empty())
    {
        auto tmp = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = tmp.first + dx[dir];
            int ny = tmp.second + dy[dir];

            if(oob(nx, ny)) continue;
            if(dist[nx][ny] != -1 || board[nx][ny][0] == 1) continue;
            dist[nx][ny] = dist[tmp.first][tmp.second] +1;
            q.push({nx, ny});
        }        
    }
    int nxt_dist =987654321;
    bool ischange = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j =1; j <=n; j++){
            if (dist[i][j] == -1 || board[i][j][1] != 2) continue;
            ischange = true;
            if (dist[i][j] < nxt_dist){
                nxt_dist = dist[i][j];
                st = i;
                ed = j;
            }
            else if(dist[i][j] == nxt_dist){
                if(i < st){
                    st = i;
                    ed = j;
                }
                else if(i == st && j < ed){
                    ed = j;
                }
            }
        }
    }
    if(ischange == false) {
        cout << -1;
        exit(0);
    }
    int idx = 0;
    for (int i = 0; i < m; i++)
    {
        if(node[i].px == st && node[i].py == ed) {
            idx = i;
            break;
        }
    }
    int gx = node[idx].gx;
    int gy = node[idx].gy;
    if(nxt_dist > init) {
        cout << -1;
        exit(0);
    }
    init -= nxt_dist;
    board[st][ed][1] =0;
    memset(dist, -1, sizeof(dist));
    q.push({st, ed});
    dist[st][ed] =0;
    while (!q.empty())
    {
        auto tmp = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = tmp.first + dx[dir];
            int ny = tmp.second + dy[dir];

            if(oob(nx, ny)) continue;
            if(dist[nx][ny] != -1 || board[nx][ny][0] == 1) continue;
            dist[nx][ny] = dist[tmp.first][tmp.second] +1;
            q.push({nx, ny});
        }   
    }
    if(dist[gx][gy] > init || dist[gx][gy] == -1) {
        cout << -1;
        exit(0);
    }
    init += dist[gx][gy];
    st = gx;
    ed = gy;
    board[st][ed][2] = 0;
    move(cur +1, st, ed);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int st, ed;
    cin >> n >> m >> init;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j][0];
        }
        
    }
    cin >> st >> ed;
    for (int i = 0; i < m; i++)
    {
        cin >> node[i].px >> node[i].py >> node[i].gx >> node[i].gy;
        board[node[i].px][node[i].py][1] =2;
        board[node[i].gx][node[i].gy][2] =3;
           
    }
    move(0, st, ed);

    return 0;    
}
