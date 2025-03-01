#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool isPrime[2000005];
vector<int> primes;
void precalc()
{
    fill(isPrime, isPrime + 2000001, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <= 2000000; i++)
    {
        if (isPrime[i])
            for (ll j = 1LL * i * i; j <= 2000000; j += i)
                isPrime[j] = 0;
    }
    for (int i = 2; i <= 2000000; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}
string solve(ll num)
{
    if (num <= 1LL)
        return "NO";
    for (ll i : primes)
    {

        if (num % i == 0 && num != i)
            return "NO";
    }
    return "YES";
}

int main()
{
    fastio;
    precalc();
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll sum = a + b;
        if (sum % 2)
        {
            ll right = sum - 2;
            cout << solve(right) << '\n';
        }
        else
        {
            if (sum == 2)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }

    return 0;
}