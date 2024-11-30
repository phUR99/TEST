#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int MX = 20;

int main()
{
    fastio;
    cin >> n;
    int state = 0;
    while (n--)
    {
        string str;
        int x;
        cin >> str;
        if (str == "add")
        {
            cin >> x;
            x--;
            state |= (1 << x);
        }
        else if (str == "remove")
        {
            cin >> x;
            x--;
            state &= ~(1 << x);
        }
        else if (str == "check")
        {
            cin >> x;
            x--;
            if (state & (1 << x))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (str == "toggle")
        {
            cin >> x;
            x--;
            state ^= (1 << x);
        }
        else if (str == "all")
            state = (1 << MX) - 1;
        else
            state = 0;
    }

    return 0;
}