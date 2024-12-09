#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, w, l;
int arr[1005];

int main()
{
    fastio;
    cin >> n >> w >> l;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++)
    {
        ret++;
        while (sum + arr[i] > l)
        {
            int endTime = dq.front().first;
            int weight = dq.front().second;
            dq.pop_front();
            sum -= weight;
            ret = max(ret, endTime);
        }
        sum += arr[i];
        dq.push_back({ret + w, arr[i]});
        // cout << ret << ' ' << ret + w << '\n';
    }
    cout << dq.back().first;

    return 0;
}