#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int board[55][55];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void printBoard(){
    for (int i =0; i < N; i++)
    {
        for (int j =0; j < N; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool canMove(){    
    
    for (int i =0; i < N; i++)
    {
        for (int j =0; j < N; j++){

            for (int idx = 0; idx < 2; idx++)
            {
                int nx = i + dx[idx];
                int ny = j + dy[idx];
                if(nx <0 || nx >= N || ny <0 || ny >= N ) continue;
                if(abs(board[i][j] - board[nx][ny]) <= R && abs(board[i][j] - board[nx][ny]) >= L){
                    return true;
                }
            }
            
        }
    }    
    return false;
}

void mov(int day){
    if(canMove() == false) { 
        cout << day;
        return;
    }
    bool visit[55][55];
    int tmp_board[55][55];

    memset(tmp_board, 0, sizeof(tmp_board));
    memset(visit, 0, sizeof(visit));

    for (int i = 0; i < N; i++)
    {
        for (int j =0; j < N; j++){
            if(visit[i][j]) continue;
            vector<pair<int, int>> curE;

            int cnt =0;
            int sum =0;
            queue<pair<int, int>> q;
            q.push({i, j});            
            visit[i][j] = true;            
            sum += board[i][j];                
            cnt++;
            curE.push_back({i, j});

            while (!q.empty())
            {
                auto cur = q.front(); q.pop();
                
                for (int dir =0; dir <4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if(nx < 0 || ny >= N || ny < 0 || nx >=N) continue;
                    if(visit[nx][ny]) continue;
                    if(abs(board[cur.first][cur.second] - board[nx][ny]) <= R && abs(board[cur.first][cur.second] - board[nx][ny]) >= L){
                        q.push({nx, ny});
                        visit[nx][ny] = true;
                        sum += board[nx][ny];
                        cnt++;
                        curE.push_back({nx, ny});
                    }

                }
            }
            sum /= cnt;
            for (auto node: curE){
                tmp_board[node.first][node.second] = sum;
            }
            
        }

    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
                board[i][j] = tmp_board[i][j];
        }
    } 

    //printBoard();            
    mov(day + 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }    
    mov(0);

    return 0;
}