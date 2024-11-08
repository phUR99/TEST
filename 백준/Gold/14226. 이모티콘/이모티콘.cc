#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int cache[1005][1005];
int s;
const int MX = 987654321;
int solve(int clipBoard, int monitor)
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    cache[1][1] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int clipBoard = cur.first;
        int monitor = cur.second;
        if (clipBoard + monitor <= s && cache[clipBoard][clipBoard + monitor] == -1)
        {
            cache[clipBoard][clipBoard + monitor] = cache[clipBoard][monitor] + 1;
            q.push({clipBoard, clipBoard + monitor});
        }
        if (cache[monitor][monitor] == -1)
        {
            cache[monitor][monitor] = cache[clipBoard][monitor] + 1;
            q.push({monitor, monitor});
        }
        if (monitor - 1 > 0 && cache[clipBoard][monitor - 1] == -1)
        {
            cache[clipBoard][monitor - 1] = cache[clipBoard][monitor] + 1;
            q.push({clipBoard, monitor - 1});
        }
    }
    int ret = MX;
    for (int i = 0; i <= 1000; i++)
    {
        if (cache[i][s] == -1)
            continue;
        ret = min(ret, cache[i][s]);
    }
    return ret;
}

int main()
{
    fastio;
    cin >> s;
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, 1);
    cout << ret << '\n';
    return 0;
}