#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool check[100001];

long long make_digit(int n)
{
    long long digit = 0;
    while (n > 0)
    {
        digit++;
        n /= 10;
    }
    digit = pow(10, digit);
    return digit;
}
int main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    long long digit = make_digit(n);

    int cnt = 1;
    int remainder = n % k;
    bool flag = true;
    while (remainder != 0)
    {
        remainder = (remainder * digit + n) % k;
        if (check[remainder])
        {
            flag = false;
            break;
        }
        check[remainder] = true;
        cnt++;
    }
    if (flag)
    {
        cout << cnt << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}