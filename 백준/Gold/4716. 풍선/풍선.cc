#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

bool cmp(array<int, 3> &a, array<int, 3> &b)
{
    return abs(a[1] - a[2]) > abs(b[1] - b[2]);
}

void solve(int n, int a, int b)
{
    vector<array<int, 3>> arr(n);
    for (auto &i : arr)
    {
        cin >> i[0] >> i[1] >> i[2];
    }
    sort(arr.begin(), arr.end(), cmp);
    int ret = 0;
    for (auto &i : arr)
    {
        int amount = i[0];
        int aCost = i[1];
        int bCost = i[2];
        if (aCost < bCost)
        {
            if (amount > a)
            {
                amount -= a;
                ret += a * aCost;
                ret += amount * bCost;
                a = 0;
            }
            else
            {
                a -= amount;
                ret += amount * aCost;
            }
        }
        else
        {
            if (amount > b)
            {
                amount -= b;
                ret += b * bCost;
                ret += amount * aCost;
                b = 0;
            }
            else
            {
                b -= amount;
                ret += amount * bCost;
            }
        }
    }
    cout << ret << '\n';
}

int main()
{
    fastio;
    while (1)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if (n == 0 && a == 0 && b == 0)
            break;
        solve(n, a, b);
    }

    return 0;
}