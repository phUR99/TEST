#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;

void show(int state)
{
    string str;
    for (int i = n; i > 1; i--)
    {
        str.push_back(i + '0');
        int mod = state % 3;
        state /= 3;
        if (mod == 2)
            str.push_back(' ');
        else if (mod == 1)
            str.push_back('+');
        else
            str.push_back('-');
    }
    str.push_back(1 + '0');
    reverse(str.begin(), str.end());
    // cout << str << '\n';
    string tmp(str);
    tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
    // cout << tmp << '\n';
    tmp = '+' + tmp;
    int ret = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == '-' || tmp[i] == '+')
        {
            int j;
            for (j = i + 1; j < tmp.size(); j++)
            {
                if (j == '-' || j == '+')
                    break;
            }
            int len = j - i + 1;
            // cout << stoi(tmp.substr(i + 1, len)) << '\n';

            if (tmp[i] == '-')
                ret -= stoi(tmp.substr(i + 1, len));
            else
                ret += stoi(tmp.substr(i + 1, len));
        }
    }
    if (ret == 0)
        cout << str << '\n';
}

void solve()
{
    cin >> n;
    int full_state = 1;
    for (int i = 0; i < n - 1; i++)
    {
        full_state *= 3;
    }
    for (int state = full_state - 1; state >= 0; state--)
    {
        show(state);
    }
    cout << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}