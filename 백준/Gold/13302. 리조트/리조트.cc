#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
bool days[105];
int n, m;
int cache[105][505];
const int MX = 987654321;
int solve(int day, int coupon)
{
    if (day >= n + 1)
        return 0;
    int &ret = cache[day][coupon];
    if (ret != -1)
        return ret;
    if (days[day])
        return ret = solve(day + 1, coupon);
    ret = MX;
    if (coupon >= 3)
        ret = solve(day + 1, coupon - 3);
    ret = min(ret, 10000 + solve(day + 1, coupon));
    ret = min(ret, 25000 + solve(day + 3, coupon + 1));
    ret = min(ret, 37000 + solve(day + 5, coupon + 2));
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int idx;
        cin >> idx;
        days[idx] = true;
    }
    int ret = solve(1, 0);
    cout << ret << '\n';
    return 0;
}