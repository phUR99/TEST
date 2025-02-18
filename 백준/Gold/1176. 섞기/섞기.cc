#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll cache[1 << 16][17];
int full_bit;
int n, k;
int arr[20];
ll solve(int state, int cur)
{
    if (state == full_bit)
        return 1;
    ll &ret = cache[state][cur];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i))
            continue;
        if (cur == n || abs(arr[cur] - arr[i]) > k)
            ret += solve(state | (1 << i), i);
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    full_bit = (1 << n) - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ret = solve(0, n);
    cout << ret;
    return 0;
}