#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
const long long mod = 1000000007;
void solve()
{
    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    long long ret = 1;
    while (pq.size() > 1)
    {
        long long l = pq.top();
        pq.pop();
        long long r = pq.top();
        pq.pop();
        long long m = (l % mod) * (r % mod);
        ret *= (m % mod);
        ret %= mod;
        pq.push(m);
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