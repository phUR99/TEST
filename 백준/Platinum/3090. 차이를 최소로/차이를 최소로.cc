#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int n, t;
vector<int> arr;
bool solve(int mid)
{
    vector<int> cur = arr;
    long long cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (cur[i + 1] > cur[i])
        {
            int diff = cur[i + 1] - cur[i];
            if (diff <= mid)
                continue;
            cnt += diff - mid;
            cur[i + 1] = cur[i] + mid;
        }
    }
    reverse(cur.begin(), cur.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (cur[i + 1] > cur[i])
        {
            int diff = cur[i + 1] - cur[i];
            if (diff <= mid)
                continue;
            cnt += diff - mid;
            cur[i + 1] = cur[i] + mid;
        }
    }
    return cnt <= (long long)t;
}

int main()
{
    fastio;
    cin >> n >> t;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0;
    int r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (solve(mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    vector<int> ans = arr;
    int diff = l;
    for (int i = 0; i < n - 1; i++)
    {
        if (ans[i + 1] > ans[i])
        {
            int d = ans[i + 1] - ans[i];
            if (d <= diff)
                continue;
            ans[i + 1] = ans[i] + diff;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (ans[i + 1] > ans[i])
        {
            int d = ans[i + 1] - ans[i];
            if (d <= diff)
                continue;
            ans[i + 1] = ans[i] + diff;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}
