#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string arr[300005];
int n, k;
int cnt[25];

int main()
{
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ret = 0;
    for (int i = 0; i <= k; i++)
    {
        int s = arr[i].size();
        ret += cnt[s]++;
    }
    for (int i = k + 1; i < n; i++)
    {
        int l = i - k - 1;
        int ls = arr[l].size();
        int rs = arr[i].size();
        cnt[ls]--;
        ret += cnt[rs]++;
    }
    cout << ret;
    return 0;
}