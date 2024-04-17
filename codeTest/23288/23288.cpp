#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int board[25][25];
bool visited[25][25];
int ans;

struct die{
    int up = 1,
    down = 6,
    left = 4,
    right = 3,  
    front = 2,
    back = 5;
};
const int dx[] ={0, 1, 0, -1};
const int dy[] ={1, 0, -1, 0};
bool inrange(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
void rot(int dir, die& dice){
    if(dir == 0){
        int temp = dice.up;
        dice.up = dice.left;
        dice.left = dice.down;
        dice.down = dice.right;
        dice.right = temp;
    }
    else if (dir == 2){
        int temp = dice.up;
        dice.up = dice.right;
        dice.right = dice.down;
        dice.down = dice.left;
        dice.left = temp;
    }
    else if (dir == 3){
        int temp = dice.up;
        dice.up = dice.back;
        dice.back = dice.down;
        dice.down = dice.front;
        dice.front = temp;
    }
    else{
        int temp = dice.up;
        dice.up = dice.front;
        dice.front = dice.down;
        dice.down = dice.back;
        dice.back = temp;
    }


    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }        
    }
    queue<pair<int, int>> q;    
    die dice;
    int x = 0;
    int y = 0;    
    int dir = 0;
    while (k--)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(!inrange(nx, ny)){
            dir = (dir + 2) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        rot(dir, dice);        
        x = nx;
        y = ny;

        int cur = board[x][y];
        if(dice.down < cur) dir = (dir - 1 + 4) % 4;
        else if (dice.down  > cur) dir = (dir + 1) % 4;
        memset(visited, false, sizeof(visited));
        int cnt = 1;
        q.push({x, y});
        visited[x][y] = true;
        while (!q.empty())
        {
            auto tmp = q.front(); q.pop();
            for (int i =0; i < 4; i++){
                int nx = tmp.first + dx[i];
                int ny = tmp.second + dy[i];
                if(!inrange(nx, ny) || visited[nx][ny] || cur != board[nx][ny]) continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
        ans += cnt * cur;
        /*            
        cout << "-----------------------------------\n";
        cout << "up : " << dice.up << '\n';
        cout << "left : " << dice.left << '\n';
        cout << "down : " << dice.down << '\n';
        cout << "right : " << dice.right << '\n';
        cout << "front : " << dice.front << '\n';
        cout << "back : " << dice.back << '\n';    
        cout << x << ' ' << y << '\n';
        cout << "-----------------------------------\n";
        */
    }
    cout << ans;

    return 0;
}