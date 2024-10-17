#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int cache[1005];

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);

    for (auto &i : arr)
    {
        cin >> i.first >> i.second;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        cache[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j].second > arr[i].second)
                continue;
            cache[i] = max(cache[i], cache[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, cache[i]);
    }
    cout << n - ans;

    return 0;
}
