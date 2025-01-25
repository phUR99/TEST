#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

bool good(string &str)
{
    int l = str.size();
    for (int i = 1; i <= l / 2; i++)
    {
        string a = str.substr(l - 2 * i, i);
        string b = str.substr(l - i, i);
        if (a == b)
            return false;
    }
    return true;
}

bool solve(string &str, int idx)
{
    if (idx == 0)
        return true;
    for (int i = 1; i <= 3; i++)
    {
        str += i + '0';
        if (good(str) && solve(str, idx - 1))
            return true;

        str.pop_back();
    }
    return false;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    string str;
    solve(str, n);
    cout << str;
    return 0;
}