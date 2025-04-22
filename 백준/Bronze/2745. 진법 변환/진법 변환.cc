#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    int b;
    cin >> b;
    int p = 1;
    int ret = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int val = isalpha(str[i]) ? str[i] - 'A'+ 10 : str[i] - '0';
        ret += val * p;
        p *= b;
    }
    cout << ret;
    return 0;
}