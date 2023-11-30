 #include <bits/stdc++.h>

using namespace std;
#define ll long long
int d[1005];
int idx[1005];
int n;
int arr[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    d[0] = arr[0]; idx[0] = 0;
    int last = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > d[last]) {
            d[++last] = arr[i];
            idx[i] = last;
        }
        else
        {
            int k = lower_bound(d, d + last, arr[i]) - d;
            d[k] = arr[i];
            idx[i] = k;
        }
    }
    vector<int> ans;
    for (int i = n-1; i >= 0; i--)
    {
        if (last == idx[i]) {
            ans.push_back(arr[i]);
            last--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
}