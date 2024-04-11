#include <bits/stdc++.h>
using namespace std;

bool isPuyo;
bool vis[12][6];
string board[12];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int ans;

void puyo(int x, int y){
    bool Erase = false;
    vis[x][y] = true;
    char color = board[x][y];
    queue<pair<int, int>> q;
    vector<pair<int, int>> tmp;
    q.push({x ,y});
    tmp.push_back({x, y});
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int i =0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx <0 || nx >= 12 || ny <0 || ny >=6) continue;
            if (vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
            tmp.push_back({nx, ny});
        }
    }
    if (tmp.size() >= 4){
        isPuyo = true;
        for (auto cur : tmp)
        {
            board[cur.first][cur.second] = '.';
        }
        
    }
    

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i =0; i < 12; i++){
        cin >> board[i];
    }
    do
    {
        isPuyo = false;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 10; j >= 0; j--)
            {
                int tmp = j;
                while (tmp < 11 && board[tmp +1][i] == '.')
                {
                    swap(board[tmp][i], board[tmp+1][i]);
                    tmp++;
                }
                
            }
            
        }
        for(int i = 0; i < 12; ++i)
            for(int j = 0; j < 6; ++j)
              if(!vis[i][j]&&board[i][j]!='.')
                 puyo(i, j);
        if(isPuyo) ++ans; // 연쇄 수 추가
        memset(vis, false, sizeof(vis));
        
    } while (isPuyo);
    cout << ans;


    return 0;
}