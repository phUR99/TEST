#include <bits/stdc++.h>
using namespace std;
int R, C, M;
int board[105][105];
struct shark
{
    int dir, velocity;
};
shark mag[10005];
int dx[] ={-1, 0, 1, 0};
int dy[] ={0, -1, 0, 1};
int fixdir(int s){
    if (s == 1){
        return 0;
    }
    else if (s == 2){
        return 2;
    }
    else if (s == 3){
        return 3;
    }
    else{
        return 1;
    }
}
int ans =0;
void fish(int col, int row){
    int ret = 0;
    if(row == R+1) return;
    if(board[row][col] != 0){
        swap(ret, board[row][col]);
        ans += ret;
        return;
    }
    fish(col, row+1);
}
void changeDir(int& x, int& y, int& d, int s){
    while (s--)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx <=0 || nx > R || ny <=0 || ny > C) d = (d +2) %4;
        x +=dx[d];
        y +=dy[d];
    }       
    return;
}

void printArr(){
    for (int i = 1; i <= R; i++)
    {
        for (int j =1; j <=C; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void move(){
    int tmp_board[105][105];
    memset(tmp_board, 0, sizeof(tmp_board));

    for (int i = 1; i <= R; i++)
    {
        for (int j =1; j <=C; j++){
            if(board[i][j] != 0){
                int nx = i;
                int ny = j;
                int& d = mag[board[nx][ny]].dir;
                int s = mag[board[nx][ny]].velocity;
                changeDir(nx, ny, d, s);
                tmp_board[nx][ny] = max(tmp_board[nx][ny], board[i][j]);
            }
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j =1; j <=C; j++){
            board[i][j] = tmp_board[i][j];
        }
    }
    /*
    printArr();
    cout << '\n';
    */
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C >> M;
    while (M--)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = z;
        mag[z].dir =fixdir(d);
        if(mag[z].dir == 0 || mag[z].dir == 2){
            mag[z].velocity = s % (2 *(R -1));
        }
        else{
            mag[z].velocity = s % (2 *(C -1));
        }
        
    }
    for (int i = 1; i <= C; i++)
    {
        fish(i, 1);
        move();
    }
    cout << ans;
    
    
    return 0;
}