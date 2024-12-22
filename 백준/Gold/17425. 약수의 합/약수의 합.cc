#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int MX = 1e6;
ll prefix[1000005];
void solve()
{
    int n;
    cin >> n;
    cout << prefix[n] << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    for (int i = 1; i <= MX; i++)
    {
        for (int j = i; j <= MX; j += i)
        {
            prefix[j] += i;
        }
    }
    for (int i = 1; i <= MX; i++)
    {
        prefix[i] = prefix[i - 1] + prefix[i];
    }

    while (t--)
    {
        solve();
    }

    return 0;
}