#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
ll cache[1 << 20];

ll func(int idx, int state)
{
    if (state == (1 << n) - 1)
        return 1;
    ll &ret = cache[state];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (idx == i || (1 << i) & state)
            continue;
        ret += func(idx + 1, state | (1 << i));
    }
    return ret;
}

void solve()
{

    cin >> n;
    memset(cache, -1, sizeof(cache));
    ll ret = func(0, 0);
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