#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int cache[5005][5005];
int arr[5005];
int solve(int l, int r)
{
    if (r == l)
        return 1;
    if (l > r)
        return 0;
    int &ret = cache[l][r];
    if (ret != -1)
        return ret;
    ret = 0;
    ret = max(solve(l + 1, r), solve(l, r - 1));
    if (arr[l] == arr[r])
        ret = max(ret, 2 + solve(l + 1, r - 1));
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = solve(0, n - 1);
    cout << n - ret;

    return 0;
}