#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[200005];
int prefix[200005];

int main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    map<int, ll> cnt;
    long long ret = 0;
    for (int i = n; i >= 0; i--)
    {
        cnt[prefix[i]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        cnt[prefix[i]]--;
        ret += cnt[k + prefix[i]];
    }
    cout << ret;

    return 0;
}