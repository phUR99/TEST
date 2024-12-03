#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[5005][5005];
const int MOD = 1e9 + 7;
int recursion(int left, int right)
{
    if (left < 0 || right < 0)
        return 0;
    if (left == 0 && right == 0)
        return 1;
    int &ret = cache[left][right];
    if (ret != -1)
        return ret;
    ret = 0;
    ret += recursion(left - 1, right);
    ret %= MOD;
    if (left < right)
    {
        ret += recursion(left, right - 1);
        ret %= MOD;
    }
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << 0 << '\n';
        return;
    }
    int ret = recursion(n / 2, n / 2);
    cout << ret << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    memset(cache, -1, sizeof(cache));
    while (t--)
    {
        solve();
    }

    return 0;
}