#include <bits/stdc++.h>

using namespace std;
#define ll long long
int a[1005], b[1005];
vector<int> as, bs;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, m, n;
    cin >> t;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        as.push_back(a[i]);
        int temp = a[i];
        for (int j = i + 1; j < m; j++) 
        {
            temp += a[j];
            as.push_back(temp);
        }
    }
    sort(as.begin(), as.end());
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        bs.push_back(b[i]);
        int temp = b[i];
        for (int j = i + 1; j < n; j++)
        {
            temp += b[j];
            bs.push_back(temp);
        }
    }
    sort(bs.begin(), bs.end());
    long long ans = 0;
    for (int i = 0; i < as.size(); i++)
    {
        if (binary_search(bs.begin(), bs.end(), t - as[i])) {
            auto l = lower_bound(bs.begin(), bs.end(), t - as[i]);
            auto u = upper_bound(bs.begin(), bs.end(), t - as[i]);
            ans += u - l;
        }
    }
    cout << ans;
}