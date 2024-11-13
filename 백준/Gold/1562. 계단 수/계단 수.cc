#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int n;
const int d = 1e9;
int cache[105][10][1 << 10];
int solve(int idx, int now, int state)
{
    if (idx == n)
        return state == ((1 << 10) - 1);
    int &ret = cache[idx][now][state];
    if (ret != -1)
        return ret;
    ret = 0;
    int upper = (now + 1) % 10;
    int lower = (now - 1 + 10) % 10;
    if (now != 9)
        ret += solve(idx + 1, upper, state | (1 << upper));
    ret %= d;
    if (now != 0)
        ret += solve(idx + 1, lower, state | (1 << lower));
    ret %= d;
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    int ret = 0;
    memset(cache, -1, sizeof(cache));
    for (int i = 1; i < 10; i++)
    {
        ret += solve(1, i, 1 << i);
        ret %= d;
    }
    cout << ret << '\n';

    return 0;
}