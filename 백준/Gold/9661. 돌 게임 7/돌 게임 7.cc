#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll n;

int main()
{
    fastio;
    cin >> n;
    n %= 5;
    bool ret = (n == 0 || n == 2);
    if (!ret)
        cout << "SK";
    else
        cout << "CY";
    return 0;
}