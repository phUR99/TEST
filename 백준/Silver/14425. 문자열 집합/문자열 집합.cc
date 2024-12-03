#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
unordered_set<string> dict;

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        dict.insert(str);
    }
    int ret = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (dict.count(str))
            ret++;
    }
    cout << ret;

    return 0;
}