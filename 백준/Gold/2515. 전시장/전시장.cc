#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int h[300005];
int w[300005];
int cache[300005];

vector<pair<int, int>> arr;
int n, s;

int solve(int cur)
{
    if (cur == n)
        return 0;
    int &ret = cache[cur];
    if (ret != -1)
        return ret;
    ret = 0;
    int nxt = lower_bound(h, h + n, h[cur] + s) - h;
    ret = max(solve(cur + 1), solve(nxt) + w[cur]);
    return ret;
}

int main()
{
    fastio;
    cin >> n >> s;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < n; i++)
    {
        h[i] = arr[i].first;
        w[i] = arr[i].second;
    }
    int answer = solve(0);
    cout << answer;

    return 0;
}