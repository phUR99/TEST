#include <bits/stdc++.h>
using namespace std;
int n, k;
// n =12
bool outRange(int x, int y){
    return x < 1 || x > n || y < 1 || y > n; 
}
struct Info
{
    int x, y, dir;
};

int board[14][14];
deque<int> state[14][14];
int change(int d){
    if(d == 0){
        return 1;
    }
    else if (d == 1){
        return 0;
    }
    else if (d == 2){
        return 3;
    }
    else{
        return 2;
    }

}
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
Info info[12];

deque<int> tmp;

void play(int trial){
    if(trial == 1001){
        cout << -1;
        exit(0);        
    }
    for (int i = 1; i <= k; i++)
    {
        int x = info[i].x;
        int y = info[i].y;         
        int d = info[i].dir;
        int moveX = x + dx[d];
        int moveY = y + dy[d];
        if(outRange(moveX, moveY) || board[moveX][moveY] == 2){
            info[i].dir = change(d);                
            moveX = x - dx[d];
            moveY = y - dy[d];            
            if(board[moveX][moveY] == 2 || outRange(moveX, moveY)){
                continue;                
            }
            else
            {                                
                if(board[moveX][moveY] == 0){
                    int idx = 0;
                    int cnt = 0;
                    while (!state[x][y].empty())
                    {
                        int cur = state[x][y].front(); state[x][y].pop_front();
                        tmp.push_back(cur);
                        if(cur == i) idx = cnt;
                        cnt++;
                    }
                    while (idx--)
                    {
                        int cur = tmp.front(); tmp.pop_front();
                        state[x][y].push_back(cur);
                    }
                    while (!tmp.empty())
                    {
                        int cur = tmp.front(); tmp.pop_front();
                        state[moveX][moveY].push_back(cur);
                        info[cur].x = moveX;
                        info[cur].y = moveY;                    
                    }                       
                    if(state[moveX][moveY].size() >= 4){
                        cout << trial;
                        exit(0);
                    }                 
                }
                else if (board[moveX][moveY] == 1){
                    int idx = 0;
                    int cnt = 0;
                    int size = state[x][y].size();
                    while (!state[x][y].empty())
                    {
                        int cur = state[x][y].front(); state[x][y].pop_front();
                        tmp.push_back(cur);
                        if(cur == i) idx = cnt;
                        cnt++;
                    }                    
                    while (idx--)
                    {
                        int cur = tmp.front(); tmp.pop_front();
                        state[x][y].push_back(cur);
                    }
                    while (!tmp.empty())
                    {
                        int cur = tmp.back(); tmp.pop_back();
                        state[moveX][moveY].push_back(cur);
                        info[cur].x = moveX;
                        info[cur].y = moveY;
                    }
                    if(state[moveX][moveY].size() >= 4){
                        cout << trial;
                        exit(0);
                    }           
                     
                }
                else{
                    cout << "something is wrong\n";
                }
            }
        
        }
        else if(board[moveX][moveY] == 0){
            int idx = 0;
            int cnt = 0;
            while (!state[x][y].empty())
            {
                int cur = state[x][y].front(); state[x][y].pop_front();
                tmp.push_back(cur);
                if(cur == i) idx = cnt;
                cnt++;
            }
            while (idx--)
            {
                int cur = tmp.front(); tmp.pop_front();
                state[x][y].push_back(cur);
            }
            
            while (!tmp.empty())
            {
                int cur = tmp.front(); tmp.pop_front();
                state[moveX][moveY].push_back(cur);
                info[cur].x = moveX;
                info[cur].y = moveY;                    
            }                       
            if(state[moveX][moveY].size() >= 4){
                cout << trial;
                exit(0);
            }      
        }
        else if(board[moveX][moveY] == 1){
            int idx = 0;
            int cnt = 0;            
            while (!state[x][y].empty())
            {
                int cur = state[x][y].front(); state[x][y].pop_front();
                tmp.push_back(cur);
                if(cur == i) idx = cnt;
                cnt++;
            }            
            while (idx--)
            {
                int cur = tmp.front(); tmp.pop_front();
                state[x][y].push_back(cur);
            }
            while (!tmp.empty())
            {
                int cur = tmp.back(); tmp.pop_back();
                state[moveX][moveY].push_back(cur);
                info[cur].x = moveX;
                info[cur].y = moveY;
            }
            if(state[moveX][moveY].size() >= 4){
                cout << trial;
                exit(0);
            }           

        }
        //cout << i << ' ' << x << ' ' << y <<' '<< moveX << ' ' << moveY << ' ' << state[moveX][moveY].size() << '\n';
            
    }
    play(trial +1);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j =1; j <=n; j++){
            cin >> board[i][j];
        }
    }
    for(int i =1; i <= k; i++){
        int row, col, dir;
        cin >> row >> col >> dir;        
        info[i].x = row;
        info[i].y = col;
        info[i].dir = dir-1; 
        state[row][col].push_back(i);
    }
    play(1);


    return 0;    
}