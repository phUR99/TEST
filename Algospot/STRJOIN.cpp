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
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
    }
    int ret = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ret += a + b;
        pq.push(a + b);
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