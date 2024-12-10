#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll cache[70][10];
int n;
ll solve(int begin, int val)
{
    if (begin == n)
        return 1;
    ll &ret = cache[begin][val];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = val; i < 10; i++)
    {
        ret += solve(begin + 1, i);
    }
    return ret;
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        cout << solve(0, 0)
             << '\n';
    }

    return 0;
}