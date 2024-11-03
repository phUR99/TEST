#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int state[10005];
int cache[10005][10];
pair<int, int> trace[10005][10];
int n;

int solve(int begin, int offset)
{
    if (begin == n)
        return 0;
    int &ret = cache[begin][offset];
    if (ret != -1)
        return ret;
    int turned_left = (-offset - state[begin] + 20) % 10;
    int turned_right = 10 - turned_left;
    int l = turned_left + solve(begin + 1, (offset + turned_left) % 10);
    int r = turned_right + solve(begin + 1, offset);
    if (l <= r)
    {
        trace[begin][offset].first = turned_left;
        trace[begin][offset].second = (offset + turned_left) % 10;
    }
    else
    {
        trace[begin][offset].first = -turned_right;
        trace[begin][offset].second = offset;
    }
    return ret = min(l, r);
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        state[i] = c - '0';
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        state[i] -= c - '0';
    }
    cout << solve(0, 0) << '\n';
    int idx = 0;
    int off = 0;
    for (int i = 0; i < n; i++)
    {
        auto cur = trace[idx][off];
        cout << i + 1 << ' ';
        cout << cur.first << '\n';
        idx++;
        off = cur.second;
    }

    return 0;
}