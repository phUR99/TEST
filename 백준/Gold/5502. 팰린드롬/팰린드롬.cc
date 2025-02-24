#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[5005][5005];
int n;
string str;
int solve(int l, int r)
{
    if (r - l == 0)
        return 1;
    if (l > r)
        return 0;
    int &ret = cache[l][r];
    if (ret != -1)
        return ret;
    ret = max(solve(l + 1, r), solve(l, r - 1));
    if (str[l] == str[r])
        ret = max(ret, 2 + solve(l + 1, r - 1));
    return ret;
}
int main()
{
    fastio;
    cin >> n;
    cin >> str;
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, n - 1);
    cout << n - ret;

    return 0;
}