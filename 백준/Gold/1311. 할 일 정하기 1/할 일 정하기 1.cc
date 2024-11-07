#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
#define MX 20
const int MAX = 987654321;
int cache[(1 << MX)];
int n;
int matrix[20][20];

int minCost(int idx, int state)
{

    if (state == (1 << n) - 1)
        return 0;
    int &ret = cache[state];
    if (ret != -1)
        return ret;
    ret = MAX;
    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i))
            continue;
        int nxtState = (state | (1 << i));
        ret = min(ret, matrix[idx][i] + minCost(idx + 1, nxtState));
    }
    return ret;
}

void solve()
{
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int ret = minCost(0, 0);
    cout << ret << '\n';
}

int main()
{
    fastio;
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}