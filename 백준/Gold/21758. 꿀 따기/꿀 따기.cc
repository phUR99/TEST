#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;

int solve(vector<int> &arr)
{
    vector<int> prefix(n);
    for (int i = 0; i < n; i++)
    {
        prefix[i] = (i == 0) ? arr[i] : prefix[i - 1] + arr[i];
    }
    int ret = 0;
    for (int i = 1; i < n - 1; i++)
    {
        ret = max(ret, prefix[n - 1] - prefix[0] + prefix[n - 1] - prefix[i] - arr[i]);
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = solve(arr);
    vector<int> prefix(n), r_prefix(n);
    for (int i = 0; i < n; i++)
    {
        prefix[i] = (i == 0) ? 0 : prefix[i - 1] + arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        r_prefix[i] = (i == n - 1) ? 0 : r_prefix[i + 1] + arr[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        ret = max(ret, prefix[i] + r_prefix[i]);
    }
    reverse(arr.begin(), arr.end());
    ret = max(ret, solve(arr));
    cout << ret;
    return 0;
}