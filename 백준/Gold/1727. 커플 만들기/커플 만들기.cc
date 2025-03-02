#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int male[1005], female[1005];
int cache[1005][1005];

int solve(int i1, int i2)
{
    if (i1 == n)
        return 0;
    int &ret = cache[i1][i2];
    if (ret != -1)
        return ret;
    ret = 1e9 + 7;
    for (int i = i2 + 1; i <= m; i++)
    {
        ret = min(ret, abs(male[i1] - female[i]) + solve(i1 + 1, i));
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    if (n < m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> male[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> female[i];
        }
        sort(male, male + n);
        sort(female, female + m + 1);
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> female[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> male[i];
        }
        sort(female, female + n + 1);
        sort(male, male + m);
        swap(n, m);
    }
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}