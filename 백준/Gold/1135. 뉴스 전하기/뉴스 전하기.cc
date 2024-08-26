#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int N;
vector<vector<int>> adj;

int solve(int cur)
{
    vector<int> tmp;
    for (auto nxt : adj[cur])
    {
        int now = solve(nxt);
        tmp.push_back(now);
    }
    sort(tmp.begin(), tmp.end(), greater<>());
    int ret = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        ret = max(ret, tmp[i] + i);
    }
    return ret + 1;
}

int main()
{
    fastio;
    cin >> N;
    adj.resize(N);
    for (int i = 0; i < N; i++)
    {
        int v;
        cin >> v;
        if (v == -1)
            continue;
        adj[v].push_back(i);
    }
    int answer = solve(0);
    cout << answer - 1;
    return 0;
}