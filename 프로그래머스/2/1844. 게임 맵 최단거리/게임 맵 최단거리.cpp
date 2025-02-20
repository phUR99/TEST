#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    while(!q.empty()){
        auto here = q.front() ; q.pop();
        int x = here.first;
        int y = here.second;
        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >=n || ny <0 || ny >=m) continue;
            if(!maps[nx][ny] || dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
            
        }
    }
    
    return dist[n-1][m-1];
}