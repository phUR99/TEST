#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;
int cache[100][100][2];
const int d = 1000000;

int n;
int solve(int l, int r, bool b)
{
    if (l == 0 && r == 0)
        return 1;
    int &ret = cache[l][r][b];
    if (ret != -1)
        return ret;
    ret = 0;
    if ((b && r == 0) || (!b && l == 0))
        return ret;

    if (b)
    {
        for (int i = 1; i <= r; i++)
        {
            ret += solve(l + i - 1, r - i, !b);
            ret %= d;
        }
    }
    else
    {
        for (int i = 1; i <= l; i++)
        {
            ret += solve(i - 1, r + l - i, !b);
            ret %= d;
        }
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));

    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            answer += solve(j - 1, n - j - 1, true);
            answer %= d;
        }
        for (int j = i + 1; j <= n; j++)
        {
            answer += solve(j - 2, n - j, false);
            answer %= d;
        }
    }
    cout << answer;

    return 0;
}
