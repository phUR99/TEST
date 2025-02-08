#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int arr[100005];
int prefix[100005];
int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r;
        prefix[l] += k;
        prefix[r] -= k;
    }
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + prefix[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << prefix[i] + arr[i] << ' ';
    }
    return 0;
}