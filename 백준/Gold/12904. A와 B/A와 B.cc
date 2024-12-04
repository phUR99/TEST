#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string s, t;

int main()
{
    fastio;
    cin >> s >> t;
    while (t.size() > s.size())
    {
        char c = t.back();
        t.pop_back();
        if (c == 'B')
            reverse(t.begin(), t.end());
    }
    if (s == t)
        cout << 1;
    else
        cout << 0;
    return 0;
}