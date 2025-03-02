#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
unordered_map<int, int> arr;
vector<vector<ll>> adj;
int parent[100005];
bool visited[100005];
int main()
{
    fastio;
    cin >> n >> k;
    adj.resize(n + 1);
    int start;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        int a = (int)bitset<32>(str).to_ulong();
        arr[a] = i;
        if (i == 1)
            start = a;
    }
    for (auto element : arr)
    {
        ll here = element.first;
        for (int i = 0; i < k; i++)
        {
            ll there = here ^ (1 << i);
            if (arr.count(there))
            {
                adj[arr[here]].push_back(there);
                adj[arr[there]].push_back(here);
            }
        }
    }

    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(start);
    visited[arr[start]] = 1;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (ll there : adj[arr[here]])
        {
            if (!visited[arr[there]])
            {
                q.push(there);
                visited[arr[there]] = 1;
                parent[arr[there]] = arr[here];
            }
        }
    }

    int m;
    cin >> m;
    while (m--)
    {
        int ed;
        cin >> ed;
        if (parent[ed] == -1)
        {
            cout << -1 << '\n';
        }
        else
        {
            vector<int> ans;
            for (int here = ed; here != -1; here = parent[here])
            {
                ans.push_back(here);
            }
            reverse(ans.begin(), ans.end());
            for (int a : ans)
            {
                cout << a << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}