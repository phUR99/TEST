#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool isPrime[10005];
const int MX = 10000;
void precalc()
{
    fill(isPrime, isPrime + MX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MX; i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= MX; j += i)
            {
                isPrime[j] = false;
            }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = n / 2; i >= 2; i--)
    {
        if (isPrime[i] && isPrime[n - i])
        {
            cout << i << ' ' << n - i << '\n';
            return;
        }
    }
}
int main()
{
    fastio;
    precalc();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}