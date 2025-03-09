#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
string str;
set<string> s;
int cache[105];
int solve(int idx)
{
    if (idx == n)
        return 1;
    int &ret = cache[idx];
    if (ret != -1)
        return ret;
    ret = 0;
    string tmp;
    for (int i = idx; i < n; i++)
    {
        tmp += str[i];
        if (s.find(tmp) != s.end())
        {
            ret |= solve(i + 1);
        }
    }
    return ret;
}

int main()
{
    fastio;
    cin >> str;
    n = str.size();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    memset(cache, -1, sizeof(cache));
    cout << solve(0);
    return 0;
}