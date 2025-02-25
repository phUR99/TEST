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
    vector<pair<double, int>> arr;
    for (int i = 1; i <= n; i++)
    {
        double t, s;
        cin >> t >> s;
        arr.push_back({double(t / s), i});
    }
    sort(arr.begin(), arr.end());
    for (auto it : arr)
    {
        cout << it.second << ' ';
    }

    return 0;
}