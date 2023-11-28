#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second
int n, m;
//idea: 2가지 경우를 고려해야 한다. 1 -> 가벼울 경우, 2-> 무거울 경우
//따라서 2가지 경우를 둘 다 고려할 수 있게 간선을 뒤집은 그래프를 하나 만든다(이 경우는 더 무거운 케이스를 셀 것)
vector<int> adj[105], inv_adj[105];
//벡터의 배열을 레퍼런스로 주는 방법
bool bfs(int st, const vector<int> vec[]) {
    queue<int> q;
    bool chk[105];
    fill(chk + 1, chk + n + 1, 0);
    chk[st] = true;
    q.push(st);
    int val = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : vec[cur]) {
            if (chk[nxt]) continue;
            chk[nxt] = true;
            q.push(nxt);
            val++;
        }
    }
    //n의 반보다 더 큰지를 확인한다.
    return val >= (n+1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inv_adj[v].push_back(u);

    }
    int ans = 0;

    for (int i = 1; i <= n ; i++)
    {
        // n의 경우가 충분히 작으므로 완전탐색을 할 수 있다.
        if (bfs(i, adj) || bfs(i, inv_adj)) ans++;
    }
    cout << ans;
    
}
