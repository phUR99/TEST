#include <bits/stdc++.h>

using namespace std;
#define ll long long
int arr[1005];
int d[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> v;
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int st, ed;
        cin >> st >> ed;
        v.push_back({ st, ed });
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (v[i].second > cnt)
        {
            if (cnt >= v[i].first) {
                ans++;
                cnt += l;
            }
            else cnt++;
        }
    }
    cout << ans;
}