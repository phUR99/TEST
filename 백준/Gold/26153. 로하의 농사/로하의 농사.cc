#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second
int ans = 0;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int w[55][55];
bool isused[55][55];
int n, m, x, y, p;

void dfs(int x, int y, int p, int d, int a) {
    if (p == 0) {      
        ans = max(ans, a);
        return;
    }

    for (int iter = 0; iter < 4; iter++)
    {
        int cx = x + dx[iter];
        int cy = y + dy[iter];
        int ca = w[cx][cy] + a;
        int cp = (d % 2 == iter % 2) ? p - 1 : p - 2;

        if (cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
        if (isused[cx][cy]) continue;
        if (cp < 0) continue;
        ans = max(ans, ca);
        isused[cx][cy] = true;
        dfs(cx, cy, cp, iter, ca);
        isused[cx][cy] = false;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            cin >> w[i][j];
        }
    }

    cin >> x >> y >> p;
    if (p == 0) {
        cout << w[x][y];
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        isused[x][y] = true;
        isused[cx][cy] = true;       
        dfs(cx, cy, p - 1, i, w[x][y] + w[cx][cy]);
        for (int j = 0; j < n; j++)
        {
            fill(isused[j], isused[j] + m, false);
        }
    }
    cout << ans;
}