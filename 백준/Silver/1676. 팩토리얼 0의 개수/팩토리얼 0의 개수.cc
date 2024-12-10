#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
const ll mod = 1e14;
int main()
{
    fastio;
    int n;
    cin >> n;
    ll ret = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        ret *= i;
        while (ret % 10 == 0)
        {
            cnt++;
            ret /= 10;
        }
        ret %= mod;
    }
    cout << cnt;

    return 0;
}