#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, c, m;
int capacity[2005];
vector<array<int, 3>> arr;

bool cmp(array<int, 3> &a, array<int, 3> &b)
{
    if (a[1] == b[1])
        return b[0] < a[0];
    return a[1] < b[1];
}
int main()
{
    fastio;
    cin >> n >> c >> m;
    fill(capacity, capacity + n + 1, c);
    arr.resize(m);
    for (auto &a : arr)
    {
        cin >> a[0] >> a[1] >> a[2];
    }
    sort(arr.begin(), arr.end(), cmp);
    int ret = 0;
    for (auto &a : arr)
    {
        int u = a[0];
        int v = a[1];

        int possible = a[2];
        for (int i = u; i < v; i++)
        {
            possible = min(possible, capacity[i]);
        }
        for (int i = u; i < v; i++)
        {
            capacity[i] -= possible;
        }
        // cout << u << ' ' << v << ' ' << possible << '\n';
        ret += possible;
    }
    cout << ret;
    return 0;
}