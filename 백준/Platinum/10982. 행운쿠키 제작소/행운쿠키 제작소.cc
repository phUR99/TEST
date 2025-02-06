#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int left_arr[1005];
int right_arr[1005];
int cache[100006];
int n;

void solve()
{
    memset(cache, 0, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> left_arr[i] >> right_arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += left_arr[i];
        for (int j = sum; j >= 0; j--)
        {
            if (j - left_arr[i] >= 0)
            {
                cache[j] = min(cache[j] + right_arr[i], cache[j - left_arr[i]]);
            }
            else
                cache[j] += right_arr[i];
        }
    }
    int ret = 987654321;
    for (int i = sum; i >= 0; i--)
    {
        ret = min(ret, max(cache[i], i));
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