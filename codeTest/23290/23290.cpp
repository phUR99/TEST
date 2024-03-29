#include <bits/stdc++.h>
using namespace std;
/*
헤멘 이유  
1.idx의 처리에서 문제가 있었음
전부 0일 경우 idx가 65로 나가는 문제가 있었음
-> cnt = c 일 때 i의 min값으로 idx를 처리함
2.움직이는 물고기 역시 추가를 해줘야함
*/


int m, s;
int sx, sy;
//←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[] = { 0,  -1, -1, -1, 0, 1, 1,  1};
int dy[] = {-1,  -1,  0,  1, 1, 1, 0, -1};
vector<int> arr[64];
vector<int> board[5][5];
int trace[5][5];

int dx2[] = {-1, 0, 1, 0};
int dy2[] = {0, -1, 0, 1};

void magic(int trial){
    if(trial == s) return;    
    vector<int> tmp_board[5][5];

    for (int i =1; i <= 4; i++){
        for (int j =1; j <=4; j++){   
            if(board[i][j].empty()) continue;
            for (auto it = board[i][j].begin(); it != board[i][j].end(); it++){
                for (int dir = 0; dir < 9; dir++){
                    if(dir == 8){
                        tmp_board[i][j].push_back(*it);
                        continue;
                    }
                    int nd = ((*it) - dir < 0) ? 8 + (*it) - dir : (*it) - dir;
                    int nx = i + dx[nd];
                    int ny = j + dy[nd];
                    if (nx < 1 || nx > 4 || ny < 1 || ny > 4) continue;
                    if (nx == sx && ny == sy) continue;
                    if (trace[nx][ny] != 0) continue;
                    tmp_board[nx][ny].push_back(nd);
                    break;
                }
            }
        }
    }
    int idx = 65;
    int c = 0;
    bool visited[5][5];
    for (int i = 0; i < 64; i++)
    {
        int cnt = 0;
        int nx = sx;
        int ny = sy;
        bool flag = false;
        memset(visited, false, sizeof(visited));
        for (int j =0; j < 3; j++){
            nx += dx2[arr[i][j]];
            ny += dy2[arr[i][j]];
            if (nx < 1 || nx > 4 || ny < 1 || ny > 4) {
                flag = true;
                break;
            }            
            if(!visited[nx][ny]) cnt += tmp_board[nx][ny].size();
            visited[nx][ny] = true;
        }
        if(c < cnt && flag == false) {
            idx = i;
            c = cnt;
        }
        else if(c == cnt && flag == false){
            idx = min(i, idx);            
        }

    }
    
    for (int i =1; i <= 4; i++){
        for (int j =1; j<= 4; j++){
            if(trace[i][j] > 0) trace[i][j]--;
        }
    }
    idx = (idx == 65) ? 0 : idx;
    for (int i = 0; i < 3; i ++){
        sx += dx2[arr[idx][i]];
        sy += dy2[arr[idx][i]];
        if(tmp_board[sx][sy].empty()) continue;
        tmp_board[sx][sy].clear();
        trace[sx][sy] =2;
    }
    for (int i =1; i <= 4; i++){
        for (int j =1; j<= 4; j++){            
            for (auto node : tmp_board[i][j]){
                board[i][j].push_back(node);
            }
        }
    }
    magic(trial + 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int idx = 0;
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 4; j++) 
            for (int k = 0; k < 4; k++){
                arr[idx].push_back(i);
                arr[idx].push_back(j);
                arr[idx].push_back(k);
                idx++;
    }
    cin >> m >> s;
    while (m--)
    {
        int x, y, d;
        cin >> x >> y >> d;
        d--;
        board[x][y].push_back(d);
    }
    cin >> sx >> sy;
    magic(0);
    int ans =0;
    for (int i =1; i <= 4; i++){
        for (int j =1; j<= 4; j++){            
            ans += board[i][j].size();
        }
    }    
    cout << ans;
    return 0;
}