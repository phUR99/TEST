#include <bits/stdc++.h>
using namespace std;

int board[25][25];
int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, 1};
int fri[25*25][4];
int n, me;
int ans =0;
int score[] ={0, 1, 10, 100, 1000};

bool oob(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void findmyPos(int m){
    int myFriend = 0;
    int zeroArround =0;
    int x =9999;
    int y =9999;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j] != 0) continue;
            int tmp_myfriend =0;
            int tmp_zeroArround =0;

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (!oob(nx, ny)) continue;
                if (board[nx][ny] == 0) tmp_zeroArround++;
                else {
                    for (int k = 0; k < 4; k++)
                    {
                        if(board[nx][ny] == fri[me][k]){
                            tmp_myfriend++;
                            break;
                        }                      
                    }                    
                }                
            }
            if (tmp_myfriend > myFriend){
                x = i;
                y = j;
                myFriend = tmp_myfriend;
                zeroArround = tmp_zeroArround;
            }
            else if(tmp_myfriend == myFriend && tmp_zeroArround > zeroArround){
                x = i;
                y = j;
                zeroArround = tmp_zeroArround;
            }
            else if(tmp_myfriend == myFriend && tmp_zeroArround == zeroArround){
                if (x > i){
                    x = i;
                    y = j;
                }
                else if(x == i && j < y){
                    y = j;
                }

            }
        }
        
    }
    board[x][y] = m;
    return;
}
int findAns(){
    int ret =0;
    for (int i = 0; i < n; i++)
    {            
        for (int j =0; j < n; j++){
            int cnt =0; 
            int m = board[i][j];

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(!oob(nx, ny)) continue;
                for (int k = 0; k < 4; k++)
                {
                    if(board[nx][ny] == fri[m][k]) {
                        cnt++;
                        break;
                    }    
                }
                
            }                                    
            ret += score[cnt];
            
        }        
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        cin >> me;
        for (int j =0; j < 4; j++){
            cin >> fri[me][j];
        }
        findmyPos(me);
    }
    cout << findAns();
    

    return 0;

}