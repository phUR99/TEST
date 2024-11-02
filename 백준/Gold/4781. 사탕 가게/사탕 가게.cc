#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int cache[10005];

bool solve()
{
    int n;
    double m;
    cin >> n >> m;
    if (n == 0 && m == 0.00)
        return false;
    int int_m = (m * 100 + 0.5);
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        double b;
        cin >> a >> b;
        arr.push_back({a, (int)(100 * b + 0.5)});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].second; j <= int_m; j++)
        {
            cache[j] = max(cache[j], cache[j - arr[i].second] + arr[i].first);
        }
    }
    cout << cache[int_m] << '\n';
    return true;
}

int main()
{
    fastio;
    while (true)
    {
        memset(cache, 0, sizeof(cache));
        if (!solve())
            break;
    }

    return 0;
}