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
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    int gcd = arr[1] - arr[0];
    for (int i = 1; i < n; i++)
    {
        gcd = __gcd(gcd, arr[i] - arr[i - 1]);
    }
    set<int> ans;
    for (int i = 1; i * i <= gcd; i++)
    {
        if (gcd % i == 0)
        {
            ans.insert(i);
            ans.insert(gcd / i);
        }
    }

    for (auto i : ans)
    {
        if (i == 1)
            continue;
        cout << i << ' ';
    }

    return 0;
}