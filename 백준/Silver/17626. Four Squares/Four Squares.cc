#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[50005];

int solve(int x)
{
    if (x == 0)
        return 0;
    int &ret = cache[x];
    assert(x <= 50000 && x >= 0);
    if (ret != -1)
        return ret;
    ret = 987654321;
    for (int i = 1; i * i <= x; i++)
    {
        ret = min(ret, solve(x - i * i) + 1);
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    int ret = solve(n);
    cout << ret;
    return 0;
}