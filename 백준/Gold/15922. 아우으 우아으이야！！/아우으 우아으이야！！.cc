#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
vector<pair<int, int>> arr;
int main()
{
    fastio;
    cin >> n;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i.first >> i.second;
    }
    arr.push_back({1e9 + 1, 1e9 + 1});
    int l = arr.front().first;
    int r = arr.front().second;
    int ret = 0;
    for (auto &i : arr)
    {
        int x = i.first;
        int y = i.second;
        if (x > r)
        {
            // cout << ret << ' ';
            ret += r - l;
            l = x;
        }
        r = max(r, y);
    }
    cout << ret;
    return 0;
}