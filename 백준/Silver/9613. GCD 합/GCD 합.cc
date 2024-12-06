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
    vector<int> arr(n);
    ll ret = 0;
    for (auto &i : arr)
    {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ret += __gcd(arr[i], arr[j]);
        }
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