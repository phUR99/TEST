#include <bits/stdc++.h>
using namespace std;
char board[12][12];


int arr[10];
const int dx[] ={-1, 1, 0, 0};
const int dy[] ={0, 0, -1, 1};
int n, m;
int rx, ry, bx ,by;
bool inrange(int x, int y){
    return x >= 0 && x < n && y < m && y >= 0;
}
int ans = 987654321;
void solution(int rx, int ry, int bx, int by){
    int idx = 0;
    for(; idx < 10; idx++){
        int distR = 0;        
        int distB = 0;
        int moveX = bx;
        int moveY = by;
        while (inrange(moveX+dx[arr[idx]], moveY+dy[arr[idx]]))
        {
            if (board[moveX+dx[arr[idx]]][moveY+dy[arr[idx]]] == '#') break;
            if (board[moveX+dx[arr[idx]]][moveY+dy[arr[idx]]] == 'O'){                
                return;
            }                        
            distB += 1; 
            moveX += dx[arr[idx]];
            moveY += dy[arr[idx]];            
        }
        bx = moveX;
        by = moveY;
        moveX = rx;
        moveY = ry;
        while (inrange(moveX+dx[arr[idx]], moveY+dy[arr[idx]]))
        {
            if (board[moveX+dx[arr[idx]]][moveY+dy[arr[idx]]] == '#') break;            
        
            if (board[moveX+dx[arr[idx]]][moveY+dy[arr[idx]]] == 'O'){        
                ans = min(ans, idx+1);        
                return;
            }         
            distR += 1; 
            moveX += dx[arr[idx]];
            moveY += dy[arr[idx]]; 
        }
        rx = moveX;
        ry = moveY;
        if(rx == bx && ry == by){
            if (distR > distB){
                rx -= dx[arr[idx]];
                ry -= dy[arr[idx]];
            }
            else if (distR < distB){
                bx -= dx[arr[idx]];
                by -= dy[arr[idx]];
            }
        }
        //cout << rx << ' ' << ry << ' ' << bx << ' ' << by << ' ' << arr[idx] << '\n';
                
    }
    return;
}


void makedir(int idx){
    if (idx == 10){
        solution(rx, ry, bx, by);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
       arr[idx] = i;
       makedir(idx + 1);
    }    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i =0; i< n; i++){
        {
            for (int j =0; j <m; j++){
                cin >> board[i][j];
                if(board[i][j] == 'R'){
                    rx = i;
                    ry = j;
                }
                else if(board[i][j] == 'B'){
                    bx = i;
                    by = j;
                }
            }
        }

    }
    makedir(0);
    cout << (ans == 987654321 ? -1 : ans);
    return 0;    
}