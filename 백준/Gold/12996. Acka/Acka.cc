#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, a, b, c;
int cache[55][55][55][55];
const int MOD = 1e9 + 7;
int solve(int idx, int aa, int bb, int cc)
{
    if (idx == n)
        return a == aa && b == bb && c == cc;
    int &ret = cache[idx][aa][bb][cc];
    if (ret != -1)
        return ret;
    ret = 0;
    if (aa < a)
        ret += solve(idx + 1, aa + 1, bb, cc);
    ret %= MOD;
    if (bb < b)
        ret += solve(idx + 1, aa, bb + 1, cc);
    ret %= MOD;
    if (cc < c)
        ret += solve(idx + 1, aa, bb, cc + 1);
    ret %= MOD;
    if (aa < a && bb < b)
        ret += solve(idx + 1, aa + 1, bb + 1, cc);
    ret %= MOD;
    if (bb < b && cc < c)
        ret += solve(idx + 1, aa, bb + 1, cc + 1);
    ret %= MOD;
    if (aa < a && cc < c)
        ret += solve(idx + 1, aa + 1, bb, cc + 1);
    ret %= MOD;
    if (aa < a && bb < b && cc < c)
        ret += solve(idx + 1, aa + 1, bb + 1, cc + 1);
    ret %= MOD;
    return ret;
}

int main()
{
    fastio;
    cin >> n >> a >> b >> c;
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, 0, 0, 0);
    cout << ret;
    return 0;
}