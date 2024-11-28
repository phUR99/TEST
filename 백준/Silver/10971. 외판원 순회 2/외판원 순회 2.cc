#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int cache[1 << 10][10][10];
int cost[10][10];

int solve(int state, int start, int current)
{
    if (state == (1 << n) - 1)
        return cost[current][start];
    int &ret = cache[state][start][current];
    if (ret != -1)
        return ret;
    ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i))
            continue;
        if (cost[current][i] == 987654321)
            continue;
        int nxtState = state | (1 << i);
        ret = min(ret, cost[current][i] + solve(nxtState, start, i));
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 987654321;
        }
    }
    int ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        ret = min(ret, solve(1 << i, i, i));
    }
    cout << ret;
    return 0;
}