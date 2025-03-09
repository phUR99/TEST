#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[50005];
int cnt[1000005];
void solve()
{
    int d, n;
    cin >> d >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sum %= d;
        cnt[sum]++;
    }
    ll ret = 0;
    for (int i = 0; i < d; i++)
    {
        ret += 1LL * cnt[i] * (cnt[i] - 1) / 2;
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