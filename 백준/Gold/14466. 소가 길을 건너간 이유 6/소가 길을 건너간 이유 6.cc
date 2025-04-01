#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k, r;
int board[105][105];
set<array<pair<int,int>,2>> ans, roads;
int dist[105][105];
vector<pair<int,int>> cows;
set<pair<int,int>> cows_dict;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0 ,-1, 1};
bool oob(int x, int y){
    return x < 1 || x >  n || y < 1 || y > n;
}
void dijkstra(const pair<int, int> &st){
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, st.first, st.second});
    memset(dist,0x3f, sizeof(dist));
    dist[st.first][st.second] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int distance = cur[0];
        int x = cur[1];
        int y = cur[2];
        if(dist[x][y] < distance) continue;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(oob(nx, ny)) continue;
            array<pair<int,int>, 2> tmp = {make_pair(nx, ny), make_pair(x, y)};
            sort(tmp.begin(), tmp.end());
            if(dist[nx][ny] > dist[x][y] + roads.count(tmp)){
                dist[nx][ny] = dist[x][y] + roads.count(tmp);
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(cows_dict.count({i, j}) && dist[i][j]){
                array<pair<int,int>,2> tmp = {make_pair(i, j), st};
                sort(tmp.begin(), tmp.end());
                ans.insert(tmp);
            }
        }
        
    }
    
    
}

int main()
{
    fastio;
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++)
    {
        pair<int, int> d1, d2;
        cin >> d1.first >> d1.second >> d2.first >> d2.second;
        array<pair<int, int>, 2> tmp = {d1, d2};
        sort(tmp.begin(), tmp.end());
        roads.insert(tmp);
    }
    cows.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> cows[i].first >> cows[i].second;
        cows_dict.insert(cows[i]);
    }
    for (int i = 0; i < k; i++)
    {
        dijkstra(cows[i]);
    }
    cout << ans.size();
    
    
    return 0;
}