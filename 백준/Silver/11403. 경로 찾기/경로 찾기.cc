#include <bits/stdc++.h>

using namespace std;
#define ll long long

int mat[105][105];
bool vis[105];
int n;

int dfs(int st, int ed) {
    fill(vis, vis + 105, 0);
    stack<int> s;
    s.push(st);
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        if (vis[cur]) continue;
        if (cur != st) vis[cur] = 1;
        for (int nxt = 1;  nxt <= n; nxt++)
        {
            if (vis[nxt]) continue;
            if (mat[cur][nxt]) {
                if (nxt == ed) return true;
                s.push(nxt);
            }
        }
        
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) {
            cout << dfs(i, j) << ' ';
        }
        cout << '\n';
    }
}