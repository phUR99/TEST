#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int T, H, W;
char board[105][105];
bool unlocked[26];
bool visited[105][105];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    fastio;
    cin >> T;
    while (T--)
    {
        cin >> H >> W;
        vector<pair<int, int>> door[26];
        memset(unlocked, false, sizeof(unlocked));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> board[i][j];
                if(isalpha(board[i][j]) && isupper(board[i][j])){
                    door[board[i][j]-'A'].push_back({i, j});
                }
            }
            
        }
        string str;
        cin >> str;
        if(str != "0") {
            for (char i : str)
            {
                unlocked[i-'a'] = true;
            }            
        }
        queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if((i != 0 && i != H-1) && (j != 0 && j != W-1)) continue;
                if(board[i][j] == '*') continue;

                if(isalpha(board[i][j])){
                    if(isupper(board[i][j])){
                        if(!unlocked[board[i][j] - 'A']) continue;
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                    else {
                        q.push({i, j});
                        visited[i][j] = true;
                        unlocked[board[i][j]-'a'] = true;
                        for (auto node : door[board[i][j] - 'a'])
                        {
                            if(visited[node.first][node.second]) continue;
                            bool flag = false;
                            for (int d = 0; d < 4; d++)
                            {
                                int nx = node.first + dx[d];
                                int ny = node.second + dy[d];
                                if(nx < 0 || nx >= H || ny < 0 || ny >= W) {
                                    flag = true;
                                    break;
                                }
                                else if (visited[nx][ny]) flag = true;
                            }                                                                                
                            if(!flag) continue;
                            q.push({node.first, node.second});
                            visited[node.first][node.second] = true;
                        }   
                    }    
                }
                else{
                    if(board[i][j] == '$') ans++;
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }                            
        }
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();            

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(board[nx][ny] == '*' || visited[nx][ny]) continue;
                
                if(isalpha(board[nx][ny])){
                    if(isupper(board[nx][ny])){
                        if(!unlocked[board[nx][ny]-'A']) continue;
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                    else{
                        unlocked[board[nx][ny] - 'a'] = true;
                        q.push({nx, ny});
                        visited[nx][ny] = true;

                        for (auto node : door[board[nx][ny] - 'a'])
                        {
                            if(visited[node.first][node.second]) continue;
                            bool flag = false;
                            for (int d = 0; d < 4; d++)
                            {
                                int nnx = node.first + dx[d];
                                int nny = node.second + dy[d];
                                if(nnx < 0 || nnx >= H || nny < 0 || nny >= W) {
                                    flag = true;
                                    break;
                                }
                                else if (visited[nnx][nny]) flag = true;
                            }                                                                                
                            if(!flag) continue;
                            q.push({node.first, node.second});
                            visited[node.first][node.second] = true;
                        }                        
                    }
                }
                else{
                    if(board[nx][ny] == '$') ans++;
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }                        
        }
        cout << ans << '\n';                          
    }
    
    

    return 0;
}