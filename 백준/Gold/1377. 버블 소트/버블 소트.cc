#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<pair<int, int>> arr;
int n;

int main()
{
    fastio;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret = max(ret, arr[i].second - i);
    }
    cout << ret + 1;
    return 0;
}