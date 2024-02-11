#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> sw[105][105];
bool canVis[105][105];
bool vis[105][105];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n, m;
// 들어갈 수 있는지 체크하는 함수 conn
bool conn(pair<int, int> nxt) { 
    for (int dir = 0; dir < 4; dir++) {
        int nx = nxt.first + dx[dir];
        int ny = nxt.second + dy[dir];
        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
        if (vis[nx][ny]) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, y, x;
        cin >> x >> y >> a >> b;
        sw[x][y].push_back({ a, b });
    }
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    vis[1][1] = true;
    canVis[1][1] = true;
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        // 방 진입에서 스위치를 켠다
        for (auto e : sw[cur.first][cur.second])
        {
            if (vis[e.first][e.second] == true) continue;
            if (conn(e) == true) {
                vis[e.first][e.second] = true;
                q.push({e.first, e.second});
            }
            canVis[e.first][e.second] = true;
        }
        // 이후 탐색하면서 방문 처리 
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            if (vis[nx][ny] == true || canVis[nx][ny] == false) continue;
            q.push({ nx, ny });
            vis[nx][ny] = true;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) ans += canVis[i][j];
    cout << ans;
}
