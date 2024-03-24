#include <bits/stdc++.h>
using namespace std;
/*
핵심 idea : board에는 shark의 크기만 받는 배열을 만들어두고, 
shark 배열을 따로 만들어 크기를 idx로 하고dir과 velocity를 담는 배열을 만들었다. (잘한 점)
알아차리지 못한 점 :  행 기준 2*(R-1)이 지나면 반드시 다시 돌아와야 하는 점을 깨닫고 속도를 없애야 했는데
방향 처리를 고민하다가 이 부분을 잘 해결하지 못했다.
다음에 비슷한 문제(여러번 왔다갔다 할 수 있는 스타일)은 어디까지 반복을 없앨 수 있는지를 확인하고 없애야겠다.

*/


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