#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int solve(int val, int mod)
{
    int cnt = 0;
    for (ll i = mod; val / i >= 1; i *= mod)
    {
        cnt += val / i;
    }

    return cnt;
}

int main()
{
    fastio;
    cin >> n >> m;
    int two = solve(n, 2) - solve(m, 2) - solve(n - m, 2);
    int five = solve(n, 5) - solve(m, 5) - solve(n - m, 5);
    cout << min(two, five);
    return 0;
}