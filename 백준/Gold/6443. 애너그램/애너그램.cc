#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

void solve()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    vector<string> ret;
    do
    {
        ret.push_back(str);
    } while (next_permutation(str.begin(), str.end()));
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    for (auto &i : ret)
    {
        cout << i << '\n';
    }
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