#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int arr[100005];

int main()
{
    fastio;
    cin >> n >> m;
    ll sum = -n;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    unsigned ll ret = 0;
    sort(arr, arr + m);
    for (int i = 0; i < m; i++)
    {
        ll v = min(1LL * arr[i], sum / (m - i));
        ret += v * v;
        sum -= v;
    }

    cout << ret;
    return 0;
}