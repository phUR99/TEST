#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
long long cache[15][2005];

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        memset(cache, 0, sizeof(cache));
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cache[0][i] = 1;
        }
        for (int k = 1; k < n; k++)
        {
            for (int i = 1; i <= m; i++)
            {
                for (int j = 2 * i; j <= m; j++)
                {
                    cache[k][j] += cache[k - 1][i];
                }
            }
        }
        long long ret = 0;
        for (int i = 1; i <= m; i++)
        {
            ret += cache[n - 1][i];
        }
        cout << ret << '\n';
    }

    return 0;
}