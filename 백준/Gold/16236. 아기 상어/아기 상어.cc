#include <bits/stdc++.h>
using namespace std;

int n;
int board[25][25];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
struct node
{
    int x, y, size, curEat, t;
};
node shark;
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}


bool findNxt(){
    queue<pair<int, int>> q;
    int dist[25][25];
    int curDist= 987654321;
    memset(dist, -1, sizeof(dist));
    q.push({shark.x, shark.y});
    dist[shark.x][shark.y] = 0;
    vector<pair<int, int>> pos;

    while (!q.empty())
    {
        auto tmp = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = tmp.first + dx[dir];
            int ny = tmp.second + dy[dir];

            if(nx <0 || nx >= n || ny <0 || ny >= n) continue;
            if(dist[nx][ny] != -1 || shark.size < board[nx][ny]) continue;
            dist[nx][ny] = dist[tmp.first][tmp.second] +1;
            q.push({nx, ny});
            if(board[nx][ny] != 0 && shark.size > board[nx][ny] && curDist >= dist[nx][ny]){
                pos.push_back({nx, ny});
                curDist = dist[nx][ny];         
            }
        }
        
    }
    if(pos.empty()) return false;
    sort(pos.begin(), pos.end(), cmp);
    board[shark.x][shark.y] = 0;
    shark.x = pos[0].first;
    shark.y = pos[0].second;
    board[shark.x][shark.y] = 9;
    shark.curEat++;
    shark.t += curDist;
    if(shark.curEat == shark.size){
        shark.size++;
        shark.curEat= 0;
    }
    return true;

}

void moveNxt(){    
    if(findNxt() == false) return;    
    moveNxt();
    return;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                shark.x = i;
                shark.y = j;
                shark.size = 2;
                shark.curEat = 0;
                shark.t=0;
            }
        }
        
    }
    moveNxt();
    cout << shark.t;


    return 0;
}