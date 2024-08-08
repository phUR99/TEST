#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

char board[55][55];
pair<int, int> st, ed;
int dist[55][55][(1<<5)];
int full_bit;
int h, w;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};



int main(){
    fastio;
    cin >> w >> h;
    int cnt = 0;
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'S'){
                st.first = i;
                st.second = j;
                board[i][j] = '.';                
            }
            else if(board[i][j] == 'E'){
                ed.first = i;
                ed.second = j;
                board[i][j] = '.';                
            }
            else if(board[i][j] == 'X'){
                board[i][j] = cnt + '0';
                cnt++;
            }
        }        
    }
    full_bit = (1 << cnt) -1 ;
    queue<pair<pair<int, int>, int>> q;
    q.push({st, 0});
    dist[st.first][st.second][0] = 0;
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first.first + dx[dir];
            int ny = cur.first.second + dy[dir];
            int ns = cur.second;
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(dist[nx][ny][ns] != -1 || board[nx][ny] == '#') continue;
            if(isdigit(board[nx][ny])){
                int n = board[nx][ny] - '0';
                n = (1 << n);
                ns |= n;
            }
            dist[nx][ny][ns] = dist[cur.first.first][cur.first.second][cur.second] + 1;
            q.push({{nx, ny}, ns});
        }
        
    }
    cout << dist[ed.first][ed.second][full_bit];
    return 0;
}