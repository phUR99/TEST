#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[2505];
int n;
string str;
bool isPalindrome(string &s)
{
    int l = s.size();
    for (int i = 0; i < l / 2; i++)
    {
        if (s[i] != s[l - 1 - i])
            return false;
    }
    return true;
}
int solve(int idx)
{
    // cout << idx << ' ';
    if (idx == n)
        return 0;
    int &ret = cache[idx];
    if (ret != -1)
        return ret;
    ret = 987654321;
    string tmp = string(1, str[idx]);
    ret = min(ret, solve(idx + 1) + 1);
    for (int i = idx + 1; i < n; i++)
    {
        tmp += str[i];
        if (isPalindrome(tmp))
            ret = min(ret, 1 + solve(i + 1));
    }
    return ret;
}

int main()
{
    fastio;
    cin >> str;
    memset(cache, -1, sizeof(cache));
    n = str.size();
    int ret = solve(0);
    cout << ret;
    return 0;
}