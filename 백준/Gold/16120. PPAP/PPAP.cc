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
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'P')
        {
            cnt++;
            continue;
        }
        if (cnt >= 2 && str[i + 1] == 'P')
        {
            cnt--;
            i++;
        }
        else
        {
            cout << "NP";
            return 0;
        }
    }
    if (cnt == 1)
        cout << "PPAP";
    else
        cout << "NP";
    return 0;
}