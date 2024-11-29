#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
void solve()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int ret = 0;
    int total = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int e = cur.first;
        int t = cur.second;
        total += t;
        ret = max(total + e, ret);
    }
    cout << ret << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}