#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

long long cache[35][65];

long long solve(int remain, int half)
{
    if (remain == 0 && half == 0)
        return 1;
    long long &ret = cache[remain][half];
    if (ret != -1)
        return ret;
    ret = 0;
    if (remain >= 1)
        ret += solve(remain - 1, half + 1);
    if (half >= 1)
        ret += solve(remain, half - 1);
    return ret;
}

int main()
{
    fastio;
    while (true)
    {
        memset(cache, -1, sizeof(cache));
        int n;
        cin >> n;
        if (n == 0)
            break;
        cout << solve(n, 0) << '\n';
    }

    return 0;
}