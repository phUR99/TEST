#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
map<char, int> dx, dy;

int N, M;
char board[1005][1005];
pair<int, int> find(vector<vector<pair<int, int>>> &parent, pair<int, int> u){
    if(parent[u.first][u.second] == u) return u;
    return parent[u.first][u.second] = find(parent, parent[u.first][u.second]);
}
int uni(vector<vector<pair<int, int>>> &parent, pair<int, int> u, pair<int, int> v){
    u = find(parent, u); v = find(parent, v);
    if(u == v) return 1;
    parent[u.first][u.second] = v;
    return 0;
}
int main(){
    fastio;
    cin >> N >> M;
    dx['D'] = 1; dy['D'] = 0;
    dx['U'] = -1; dy['U'] = 0;
    dx['L'] = 0; dy['L'] = -1;
    dx['R'] = 0; dy['R'] = 1;
    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            parent[i][j].first = i; parent[i][j].second = j;
            cin >> board[i][j];
        }
        
    }
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int nx = i + dx[board[i][j]];
            int ny = j + dy[board[i][j]];
            answer += uni(parent, {i, j}, {nx, ny});
        }        
    }

    cout << answer;

    return 0;
}