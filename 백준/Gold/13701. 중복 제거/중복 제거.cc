#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int dict[1200000];
const int MOD = 31;
bool returnNumber(int value)
{
    int a = value / MOD;
    int b = value % MOD;
    if (dict[a] & (1 << b))
        return false;
    dict[a] |= (1 << b);
    return true;
}

int main()
{
    fastio;
    int num;
    while (cin >> num)
    {
        if (returnNumber(num))
            cout << num << ' ';
    }

    return 0;
}