#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    int n, e;
    cin >> n >> e;
    ll ret = e;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x <= y)
            continue;
        arr.push_back({y, x});
    }
    arr.push_back({1e9 + 1, 1e9 + 1});
    sort(arr.begin(), arr.end());
    int l = -1e9 - 1;
    int r = -1e9 - 1;
    for (auto &i : arr)
    {
        int x = i.first;
        int y = i.second;
        if (x > r)
        {
            ret += (r - l) * 2;
            l = x;
        }
        r = max(r, y);
    }
    cout << ret;
    return 0;
}