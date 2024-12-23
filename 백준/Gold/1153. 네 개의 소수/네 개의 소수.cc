#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
const int MX = 1e6;
bool isPrime[MX + 5];
int cache[MX + 5][5];
void precalc()
{
    fill(isPrime, isPrime + MX + 5, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= MX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    fastio;
    precalc();
    int n;
    cin >> n;
    int a = ((n % 2) & 1) ? (n + 1) / 2 : n / 2;
    int b = ((n % 2) & 1) ? (n) / 2 : n / 2;
    int x, y, z, w;
    z = w = -1;
    if (n & 1)
    {
        x = 2;
        y = 3;
        for (int i = 2; i <= n - 5; i++)
        {
            if (isPrime[i] && isPrime[n - 5 - i])
            {
                z = i;
                w = n - 5 - i;
                break;
            }
        }
    }
    else
    {
        x = y = 2;
        for (int i = 2; i <= n - 5; i++)
        {
            if (isPrime[i] && isPrime[n - 4 - i])
            {
                z = i;
                w = n - 4 - i;
                break;
            }
        }
    }

    if (z == -1 || n < 8)
        cout << -1;
    else
        cout << x << ' ' << y << ' ' << z << ' ' << w;

    return 0;
}