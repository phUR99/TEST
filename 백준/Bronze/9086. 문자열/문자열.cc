#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << str.front() << str.back() << '\n';
    }

    return 0;
}