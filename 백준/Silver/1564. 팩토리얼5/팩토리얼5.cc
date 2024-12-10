#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll MOD = 1e12;

int main()
{
    fastio;
    int n;
    cin >> n;
    ll ret = 1;
    for (int i = 1; i <= n; i++)
    {
        ret *= i;
        while (ret % 10 == 0)
        {
            ret /= 10;
        }

        ret %= MOD;
    }
    string ans = to_string(ret);
    while (ans.back() == '0')
        ans.pop_back();
    for (int i = ans.size() - 5; i < ans.size(); i++)
    {
        cout << ans[i];
    }

    return 0;
}