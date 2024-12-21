#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

bool isPrime[10005];
void precalc()
{
    fill(isPrime, isPrime + 10005, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 10000; i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= 10000; j += i)
            {
                isPrime[j] = false;
            }
    }
}
bool prime(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (isPrime[i] && (x % i == 0))
            return false;
    }
    return true;
}

void solve(int cur, int idx)
{
    if (idx == 0)
    {
        cout << cur << '\n';
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        int nxt = cur * 10 + i;
        if (prime(nxt))
            solve(nxt, idx - 1);
    }
}
int main()
{
    fastio;
    int n;
    cin >> n;
    precalc();
    solve(0, n);
    return 0;
}