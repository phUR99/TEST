#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[35][35];
int n;
string str;
int solve(int l, int r)
{

    if (l > r)
        return 0;
    int &ret = cache[l][r];
    if (ret != -1)
        return ret;
    ret = solve(l + 1, r) + solve(l, r - 1) - solve(l + 1, r - 1);
    if (str[l] == str[r])
        ret += 1 + solve(l + 1, r - 1);
    return ret;
}

int main()
{
    fastio;
    cin >> str;
    n = str.size();
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, n - 1);
    cout << ret;
    return 0;
}