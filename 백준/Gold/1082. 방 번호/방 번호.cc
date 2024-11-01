#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int p[15];

void solve()
{
    int n, m;
    cin >> n;
    int minCost = 987654321;
    int minIdx = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (minCost >= p[i])
        {
            minCost = p[i];
            minIdx = i;
        }
    }
    int minCostA = 987654321;
    int minIdxA = -1;
    for (int i = 1; i < n; i++)
    {
        if (minCostA >= p[i])
        {
            minCostA = p[i];
            minIdxA = i;
        }
    }
    cin >> m;

    if (minCostA > m)
    {
        cout << 0 << '\n';
        return;
    }
    string ret = to_string(minIdxA);
    m -= minCostA;
    while (m >= minCost)
    {
        m -= minCost;
        ret += to_string(minIdx);
    }

    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = n - 1; j > ret[i] - '0'; j--)
        {
            if (p[j] - p[ret[i] - '0'] <= m)
            {
                m -= p[j] - p[ret[i] - '0'];
                ret[i] = j + '0';
                break;
            }
        }
    }
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