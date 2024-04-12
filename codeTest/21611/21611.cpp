#include <bits/stdc++.h>
using namespace std;

int init_x;
int init_y;
int n, m, ans;
int board[50][50];
vector<pair<int,int>> table;
int score[5];
const int MX = 987654321;
const int dx[] = {MX, -1, 1, 0, 0};
const int dy[] = {MX, 0, 0, -1, 1};
// 왼 아 우 위
const int dx_iter[] = {0, 1, 0, -1};
const int dy_iter[] = {-1, 0, 1, 0};
bool inrange(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void maketable(int x, int y, int iter, int cnt, int dir){    
    if(cnt == 2){
        cnt = 0;
        iter++;
    }
    for (int i = 0; i < iter; i++)
    {
        x += dx_iter[dir];
        y += dy_iter[dir];
        if(!inrange(x, y)) return;
        table.push_back({x, y});
    }
    maketable(x, y, iter, cnt +1, (dir + 1) % 4);
}
void exterminate(int dir, int s){
    int x = (n + 1)/2;
    int y = (n + 1)/2;
    for (int i = 0; i < s; i++)
    {
        x += dx[dir];
        y += dy[dir];
        board[x][y] = 0;
    }    
    return;    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
        
    }
    maketable((n+1)/2, (n+1)/2, 1, 0, 0);    
    while (m--)
    {
        int d, s;
        cin >> d >> s;
        exterminate(d, s);
        bool isboom;
        queue<pair<int, int>> q;       
        do
        {
            for (int i = table.end() - table.begin() -1; i >= 0; i--)
            {                
                int x = table[i].first;
                int y = table[i].second;
                if (board[x][y]) continue;
                for (int j = i; j < table.end() - table.begin() -1; j++){
                    x = table[j].first;
                    y = table[j].second;
                    int nx = table[j+1].first;
                    int ny = table[j+1].second;
                    swap(board[x][y], board[nx][ny]);
                }
            }            
            isboom = false;            
            vector<pair<int, int>> buffer;    
            for (int i = 0; i < table.size(); i++){
                
                int cnt = 1;
                int x = table[i].first;
                int y = table[i].second;
                int num = board[x][y];                
                if (num == 0) continue;
                buffer.clear();
                buffer.push_back({x, y});
                for (int j = i+1; j < table.size(); j++){
                    int nx = table[j].first;
                    int ny = table[j].second;
                    if(board[nx][ny] != num) break;
                    cnt++;
                    buffer.push_back({nx, ny});
                }
                if (cnt >= 4){
                    score[num] += cnt;
                    for (auto nxt : buffer)
                    {
                        board[nxt.first][nxt.second] = 0;
                        isboom = true;
                    }                    
                }
            }                    
        } while (isboom);
        vector<int> buffer;
        for (int i = 0; i < table.size(); i++){
                
                int cnt = 1;
                int x = table[i].first;
                int y = table[i].second;
                int num = board[x][y];                
                if (num == 0) continue;                
                for (int j = i + 1; j < table.size(); j++){
                    int nx = table[j].first;
                    int ny = table[j].second;
                    if(board[nx][ny] != num) {
                        i = j-1;
                        break;
                    }
                    cnt++;                    
                }
                buffer.push_back(cnt);
                buffer.push_back(num);
        }
        for (int i = 0; i < table.size(); i++)
        {
            if(i >= buffer.size()) break;
            int x = table[i].first;
            int y = table[i].second;
            board[x][y] = buffer[i];
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        ans += i * score[i];
    }
    cout << ans;
    


    return 0;
}