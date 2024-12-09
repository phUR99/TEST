#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;

int main()
{
    fastio;
    cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    ll ret = 0;
    while (m--)
    {
        ll x1 = pq.top();
        pq.pop();
        ll x2 = pq.top();
        pq.pop();
        ll sum = x1 + x2;
        pq.push(sum);
        pq.push(sum);
    }
    while (!pq.empty())
    {
        ret += pq.top();
        pq.pop();
    }
    cout << ret;

    return 0;
}