#include <bits/stdc++.h>
using namespace std;

bool board[105][105];
bool tmp_board[105][105];

bool isEmpty[105][105];
bool visited[105][105];

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int n, m;

bool checkCheese(){
    for (int i = 0; i < n; i++)
    {
        for (int j =0; j < m; j++){
            if(!board[i][j]) continue;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j =0; j < m; j++){
            cin >> board[i][j];
        }
    }


    int cnt = 0;
    int ans = 0;
    
    while (true)
    {        
        int tmp_ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++){
                if(board[i][j]) tmp_ans++;
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    
                    bool &vis = visited[i][j];
                    const bool &state = board[i][j];

                    if(vis || state) continue;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis = true;
                    isEmpty[i][j] = true;

                    while (!q.empty())
                    {
                        auto cur = q.front(); q.pop();
                        for (auto dir : d)
                        {
                            int nx = dir.first + cur.first;
                            int ny = dir.second + cur.second;
                            if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
                            if(board[nx][ny] || visited[nx][ny]) continue;
                            isEmpty[nx][ny] = true;
                            visited[nx][ny] = true;
                            q.push({nx, ny});                    
                        }
                        
                    }  
                }          
            }
        }
        if(checkCheese() == false) break;
        cnt++;
        ans = tmp_ans;

        for (int i = 0; i < n; i++)
        {
            for (int j =0; j < m; j++){

                if(!board[i][j]) continue;
                for (auto dir : d)
                {
                    int nx = i + dir.first;
                    int ny = j + dir.second;
                    if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] || !isEmpty[nx][ny]) continue;
                    tmp_board[i][j] = true;
                }            
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j =0; j < m; j++){
                if(!tmp_board[i][j]) continue;
                isEmpty[i][j] = true;
                board[i][j] = false;
            }
        }
        memset(visited, false, sizeof(visited));
    }
    cout << cnt << '\n' << ans;
    




    return 0;
}