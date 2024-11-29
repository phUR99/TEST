#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int discovered[1005];
bool finished[1005];
int t, n;
int counter;
vector<vector<int>> adj;
void init()
{
    cin >> n;
    adj.clear();
    adj.resize(n + 1);
    memset(discovered, -1, sizeof(discovered));
    memset(finished, false, sizeof(finished));
    counter = 0;
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        adj[i].push_back(b);
    }
}
void dfs(int here, int &ret);

void solve()
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (discovered[i] == -1)
            dfs(i, ret);
    }
    cout << ret << '\n';
}

void dfs(int here, int &ret)
{
    discovered[here] = counter++;

    for (int there : adj[here])
    {
        if (discovered[there] == -1)
            dfs(there, ret);
        else if (!finished[there])
            ret++;
    }
    finished[here] = true;
}

int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        init();
        solve();
    }

    return 0;
}