#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int T, N;
int answer;
int board[102][102];
bool visited[102][102];
struct node
{
    int c;
    pair<int, int> coord;
    const bool operator< (const node &a) const{
        return a.c < c;
    }
};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void solution(){
    priority_queue<node> pq;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int cx = cur.coord.first;
        int cy = cur.coord.second;
        visited[cx][cy] = true;
        if(cx == N -1 && cy == N -1){
            answer = cur.c;
            return;
        }
        for(int dir = 0; dir < 4; dir++){
            int nx= cx + dx[dir];
            int ny= cy + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(visited[nx][ny]) continue;
            pq.push({board[nx][ny] + cur.c, {nx, ny}});
        }
    }
}
int main(){
    fastio;

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                char c;
                cin >> c;
                board[i][j] = c - '0';
                visited[i][j] = false;
            }            
        }
        solution();                
        cout << "#" << t + 1 << ' ';
        cout << answer << '\n';
    }
    

    return 0;
}