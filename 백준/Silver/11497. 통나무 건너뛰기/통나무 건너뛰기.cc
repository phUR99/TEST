#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    int result = arr[1] - arr[0];

    for (int i = 2; i < n; i += 2)
    {
        result = max(result, arr[i] - arr[i - 2]);
    }
    for (int i = 3; i < n; i += 2)
    {
        result = max(result, arr[i] - arr[i - 2]);
    }

    cout << result << "\n";
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}