#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool isPrime[500005];
int num[10005];
vector<pair<int, int>> arr;
ll cache[500005];

void precalc()
{
    fill(isPrime, isPrime + 500005, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 500000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 500000; j += i)
            {
                isPrime[j] = 0;
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
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        num[idx]++;
        sum += idx;
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (num[i])
            arr.push_back({i, num[i]});
    }
    int zero = num[0] + 1;
    cache[0] = 1;

    for (auto cur : arr)
    {
        int v = cur.first;
        int c = cur.second;
        for (int i = sum; i >= 0; i--)
        {
            for (int j = 1; j <= c && i - j * v >= 0; j++)
            {
                cache[i] += cache[i - j * v];
            }
        }
    }
    ll ret = 0;
    for (int i = 2; i <= sum; i++)
    {
        if (isPrime[i])
            ret += cache[i];
    }
    cout << ret * (ll)zero;

    return 0;
}