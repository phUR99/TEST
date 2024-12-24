#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
const vector<vector<ll>> matrix = {{1, 1},
                                   {1, 0}};
const ll MOD = 1e9 + 7;

vector<vector<ll>> multiply(const vector<vector<ll>> &a, const vector<vector<ll>> &b)
{
    auto ret = vector<vector<ll>>(2, vector<ll>(2));
    ret[0][0] = ((a[0][0] % MOD) * (b[0][0] % MOD) + (a[0][1] % MOD) * (b[1][0] % MOD)) % MOD;
    ret[0][1] = ((a[0][0] % MOD) * (b[0][1] % MOD) + (a[0][1] % MOD) * (b[1][1] % MOD)) % MOD;
    ret[1][0] = ((a[1][0] % MOD) * (b[0][0] % MOD) + (a[1][1] % MOD) * (b[1][0] % MOD)) % MOD;
    ret[1][1] = ((a[1][0] % MOD) * (b[0][1] % MOD) + (a[1][1] % MOD) * (b[1][1] % MOD)) % MOD;
    return ret;
}

vector<vector<ll>> solve(ll n)
{
    if (n == 0)
    {
        vector<vector<ll>> ret = {{1, 0},
                                  {0, 1}};
        return ret;
    }
    if (n & 1)
        return multiply(matrix, solve(n - 1));
    auto half = solve(n / 2);
    return multiply(half, half);
}

int main()
{
    fastio;
    ll n;
    cin >> n;
    auto arr = solve(n);
    cout << arr[1][0] % MOD;
    return 0;
}