#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;

int main()
{
    fastio;
    cin >> n;
    vector<array<int, 3>> arr;
    for (int i = 0; i < n; i++)
    {
        int x, y, h;
        cin >> x >> h >> y;
        arr.push_back({x, -1, -h});
        arr.push_back({y, 1, h});
    }
    sort(arr.begin(), arr.end());
    map<int, int> height;
    height[0] = 1;
    for (auto i : arr)
    {
        int x = i[0];
        int end = -i[1];
        int h = i[2] * i[1];
        if (end == 1)
        {
            if (height.lower_bound(h) == height.end() && height[h] == 0)
            {
                cout << x << ' ' << h << ' ';
            }
            height[h]++;
        }
        else
        {
            height[h]--;
            if (height[h] == 0)
                height.erase(h);
            if (height.lower_bound(h) == height.end())
            {
                cout << x << ' ' << prev(height.end())->first << ' ';
            }
        }
    }

    return 0;
}