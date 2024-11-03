#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
double cache[2005][1005];
int n, m;

double climb(int len, int day)
{
    if (day == m)
        if (len >= n)
            return 1;
        else
            return 0;
    double &ret = cache[len][day];
    if (ret != -1.0)
        return ret;
    return ret = 0.75 * climb(len + 2, day + 1) + 0.25 * climb(len + 1, day + 1);
}

void solve()
{

    cin >> n >> m;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cache[i][j] = -1.0;
        }
    }

    double ret = climb(0, 0);
    cout << fixed << setprecision(10) << ret << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}