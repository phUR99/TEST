#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;

ll solve(vector<int> &arr)
{
    ll ret = 0;
    for (int i = 0; i < 32; i++)
    {
        ll cnt = 0;
        for (auto &e : arr)
        {
            if (e & (1 << i))
                cnt++;
        }
        ret += cnt * (n - cnt) * (1LL << i);
    }

    return ret;
}

int main()
{
    fastio;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    ll ret = solve(arr);
    cout << ret;
    return 0;
}