#include <bits/stdc++.h>
using namespace std;
int R, C;
char board[1505][1505];
pair<int, int> st, ed;
const int WALL = 987654321;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1 ,1};
int dist[1505][1505];
bool visited[1505][1505];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    st.first = -1;
    queue<pair<int, int>> q;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {            
            cin >> board[i][j];
            if (board[i][j] == '.'){
                dist[i][j] = 0;
                q.push({i, j});
            }
            else if (board[i][j] == 'L' && st.first == -1){
                dist[i][j] = 0;
                st.first= i;
                st.second = j;
                q.push({i, j});
            }
            else if (board[i][j] == 'L' && st.first != -1){
                dist[i][j] = 0;
                ed.first= i;
                ed.second = j;
                q.push({i, j});
            }
            else{
                dist[i][j] = WALL;
            }
        }
        
    }

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();        
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= R || ny <0 || ny >= C) continue;
            if(dist[nx][ny] <= dist[cur.first][cur.second] + 1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;            
            q.push({nx, ny});

        }        
    }    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    visited[st.first][st.second] = true;
    pq.push({0, {st.first, st.second}});
    int ans = 0;

    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        ans = max(ans, cur.first);
        if(cur.second.first == ed.first && cur.second.second == ed.second){
            cout << ans;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.second.first + dx[i];
            int ny = cur.second.second + dy[i];
            if(nx < 0 || nx >= R || ny <0 || ny >= C) continue;
            if(visited[nx][ny]) continue;                        
            pq.push({dist[nx][ny], {nx, ny}});
            visited[nx][ny] = true;
                        
        }
        
    }
    

    return 0;
}