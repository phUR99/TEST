#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int height[100005];
int idx;
unordered_map<int, int> order;
int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        order[val] = i;
    }
    height[0] = -1;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        val = order[val];
        // cout << val << ' ';
        if (val > height[idx])
        {
            height[++idx] = val;
        }
        else
        {
            int tmp = lower_bound(height, height + idx, val) - height;
            height[tmp] = val;
        }
    }

    cout << idx;
    return 0;
}