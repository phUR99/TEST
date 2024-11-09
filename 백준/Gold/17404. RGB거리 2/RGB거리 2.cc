#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
const int MX = 987654321;
int arr[1005][3];
int cache[1005][4][4];
int n;

int solve(int begin, int prev, int first)
{
    if (begin == n)
        return 0;

    int &ret = cache[begin][prev][first];
    if (ret != -1)
        return ret;

    ret = MX;
    for (int c = 0; c < 3; c++)
    {
        if (c == prev)
            continue;
        if (begin == n - 1 && first == c)
            continue;
        if (begin == 0)
        {
            ret = min(ret, solve(begin + 1, c, c) + arr[begin][c]);
        }
        else
            ret = min(ret, solve(begin + 1, c, first) + arr[begin][c]);
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
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ret = solve(0, 3, 3);
    cout << ret << '\n';

    return 0;
}