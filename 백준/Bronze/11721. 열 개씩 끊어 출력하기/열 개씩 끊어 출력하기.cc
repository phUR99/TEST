#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string str;

int main()
{
    fastio;
    cin >> str;
    str = ' ' + str;
    for (int i = 1; i < str.size(); i++)
    {
        cout << str[i];
        if (i % 10 == 0)
            cout << '\n';
    }

    return 0;
}