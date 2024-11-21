#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
vector<int> arr;

void solve()
{
    int n, k;
    arr.clear();
    cin >> n >> k;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    int l = 0;
    int r = n - 1;
    int diff = 987654321;
    int cnt = 0;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (abs(sum - k) < diff)
        {
            diff = abs(sum - k);
            cnt = 1;
        }
        else if (abs(sum - k) == diff)
            cnt++;
        if (sum > k)
            r--;
        else
            l++;
    }
    cout << cnt << '\n';
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