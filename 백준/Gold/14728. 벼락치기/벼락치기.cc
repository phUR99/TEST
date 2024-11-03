#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int n, t;
int cache[105][10005];
int ttime[105];
int score[105];

int solve(int begin, int remain)
{
    if (begin == n)
        return 0;
    int &ret = cache[begin][remain];
    if (ret != -1)
        return ret;
    ret = solve(begin + 1, remain);
    if (remain >= ttime[begin])
        ret = max(ret, score[begin] + solve(begin + 1, remain - ttime[begin]));
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> ttime[i] >> score[i];
    }
    int ret = solve(0, t);
    cout << ret << '\n';

    return 0;
}