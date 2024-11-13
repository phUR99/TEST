#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int n;
double matrix[25][25];
double cache[(1 << 20)];
double solve(int idx, int state)
{
    if (idx == n)
        return 1;
    double &ret = cache[state];
    if (ret != -1)
        return ret;
    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i))
            continue;
        int nxtState = (state | (1 << i));
        ret = max(ret, (matrix[idx][i]) * solve(idx + 1, nxtState));
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    fill(cache, cache + (1 << n) + 1, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            matrix[i][j] *= 0.01;
        }
    }
    double ret = solve(0, 0);
    ret *= 100;
    cout.precision(6);
    cout << fixed << ret << '\n';
    return 0;
}