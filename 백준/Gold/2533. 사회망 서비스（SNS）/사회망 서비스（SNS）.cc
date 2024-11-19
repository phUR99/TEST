#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
vector<vector<int>> adj;
bool visited[1000005];
int answer = 0;
const int need = 0;
const int unneed = 1;

int solve(int here)
{
    visited[here] = true;
    vector<int> status(2, 0);
    for (auto there : adj[here])
    {
        if (visited[there])
            continue;
        ++status[solve(there)];
    }
    if (status[need])
    {
        answer++;
        return unneed;
    }
    return need;
}
int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    cout << answer << '\n';

    return 0;
}