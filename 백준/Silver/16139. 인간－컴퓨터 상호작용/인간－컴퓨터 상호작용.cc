#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int prefix[26][200005];
string str;
int main()
{
    fastio;
    cin >> str;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        int val = str[i] - 'a';
        for (int j = 0; j < 26; j++)
        {
            prefix[j][i] = (i == 0) ? (val == j) : prefix[j][i - 1] + (val == j);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        cout << prefix[c - 'a'][r] - (l == 0 ? 0 : prefix[c - 'a'][l - 1]) << '\n';
    }

    return 0;
}