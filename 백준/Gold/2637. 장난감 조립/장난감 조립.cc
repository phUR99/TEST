#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<pair<int, int>> adj[105];
int cnt[105], idx[105];
bool base[105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    fill(base, base + n, 1);
    while (m--)
    {
        //x는 상위 또는 중간 부품이므로 base를 체크하여 결과값 출력할 때는 출력하지 않게 한다
        // x-> (y, k)의 형태로 그래프를 만든다.
        int x, y, k;
        cin >> x >> y >> k;
        base[x] = 0;
        adj[x].push_back({ y, k });
        idx[y]++;
    }
    queue<int> q;
    q.push(n);
    cnt[n] = 1;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto [nxt, c] : adj[cur])
        {
            // idx =0인 그래프를 탐색하면서 k의 가중치와 cnt를 곱해준다.
            cnt[nxt] += c * cnt[cur];
            idx[nxt]--;
            if (idx[nxt] == 0) q.push(nxt);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (base[i])  cout << i << ' ' << cnt[i] << '\n';
    }

}
