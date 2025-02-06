#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
int cache[35][35][35][450];

int solve(int idx, int a, int b, int remain)
{
    if (idx == n)
        return cache[idx][a][b][remain] = (remain == 0);
    int &ret = cache[idx][a][b][remain];
    if (ret != -1)
        return ret;
    ret = 0;
    ret |= solve(idx + 1, a + 1, b, remain);
    if (remain - a >= 0)
        ret |= solve(idx + 1, a, b + 1, remain - a);
    if (remain - a - b >= 0)
        ret |= solve(idx + 1, a, b, remain - a - b);
    return ret;
}
string trace(int idx, int a, int b, int remain)
{
    if (idx == n)
        return string();
    if (cache[idx + 1][a + 1][b][remain])
        return string(1, 'A') + trace(idx + 1, a + 1, b, remain);
    if (remain - a >= 0 && cache[idx + 1][a][b + 1][remain - a])
        return string(1, 'B') + trace(idx + 1, a, b + 1, remain - a);
    if (remain - a - b >= 0 && cache[idx + 1][a][b][remain - a - b])
        return string(1, 'C') + trace(idx + 1, a, b, remain - a - b);
}
int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    int ret = solve(0, 0, 0, k);
    if (ret)
    {
        cout << trace(0, 0, 0, k);
    }
    else
        cout << -1;
    return 0;
}