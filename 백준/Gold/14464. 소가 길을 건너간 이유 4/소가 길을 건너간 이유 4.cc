#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    int c, n;
    cin >> c >> n;
    vector<int> arr(c);
    vector<bool> used(c, false);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pq.push({y, x});
    }
    int ret = 0;
    while (!pq.empty())
    {
        int x = pq.top()[1];
        int y = pq.top()[0];
        pq.pop();
        for (int i = 0; i < c; i++)
        {
            if (x <= arr[i] && y >= arr[i] && !used[i])
            {
                ret++;
                used[i] = true;
                break;
            }
        }
    }

    cout << ret;

    return 0;
}