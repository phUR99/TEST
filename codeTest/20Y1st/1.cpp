#include <bits/stdc++.h>
using namespace std;

struct fish
{
    int num, dir;
    void clear(){
        num = 0;
        dir = 0;
    }
};
//↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dx[] = {-1, -1,  0,  1, 1, 1, 0, -1} ;
int dy[] = { 0, -1, -1, -1, 0, 1, 1,  1};
fish board[4][4];
bool fishNum[17];
int ans = 0;
bool oob(int x, int y){
    return 0 > x || x >=4 || y < 0 || y >= 4;
}
void fishSwap(int num, fish (&tmp_board)[4][4], int sx, int sy){
    for (int x = 0; x < 4; x++)
    {
        for (int y =0; y <4; y++){
            if(tmp_board[x][y].num != num) continue;
            for (int dir = 0; dir < 8; dir++)
            {                    
                int d = (tmp_board[x][y].dir + dir > 7) ? tmp_board[x][y].dir + dir - 8 : tmp_board[x][y].dir + dir;
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(oob(nx, ny)) continue;
                if(sx == nx && sy == ny) continue;
                tmp_board[x][y].dir = d;
                swap(tmp_board[x][y], tmp_board[nx][ny]);
                return;
            }
            
        }
    }   
}

void sharkMove(int sx, int sy, int sd, fish board[4][4]){

    fish tmp_board[4][4];
    for (int x = 0; x < 4; x++)
    {
        for (int y =0; y <4; y++){            
            tmp_board[x][y] = board[x][y];
            if(fishNum[board[x][y].num] == true){
                tmp_board[x][y].clear();
            }
        }
    }
    for (int i = 1; i <= 16; i++)
    {
        if(fishNum[i] == true) continue;   
        fishSwap(i, tmp_board, sx, sy);     
             
    }

    /*
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++){
            cout << tmp_board[i][j].num << ' ';        
        }
        cout << '\n';
    }
    cout << '\n' ;
    */
    int nx = sx;
    int ny = sy;   
    while (true)        
    {
        nx += dx[sd];
        ny += dy[sd];
        if(oob(nx, ny)){
            int sumNum = 0;
            for (int i = 1; i <= 16; i++)
            {
                if(fishNum[i] == true) sumNum += i;
            }
            ans = max(ans, sumNum);
            break;
        }
        if(tmp_board[nx][ny].num == 0) continue;
        fishNum[tmp_board[nx][ny].num] = true;        
        sharkMove(nx, ny, tmp_board[nx][ny].dir, tmp_board);
        fishNum[tmp_board[nx][ny].num] = false;
    }
    return;      
}

/*
 번호가 작은 물고기부터 순서대로 이동한다. 
 물고기는 한 칸을 이동할 수 있고, 이동할 수 있는 칸은 빈 칸과 다른 물고기가 있는 칸, 
 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸이다.
 */
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 4; i++)
    {
        for (int j =0; j < 4; j++){
            cin >> board[i][j].num >> board[i][j].dir;
            board[i][j].dir--;
        }
    }
    fishNum[board[0][0].num] = true;
    int dir = board[0][0].dir;
    sharkMove(0, 0, dir, board);
    cout << ans;
    return 0;    
}