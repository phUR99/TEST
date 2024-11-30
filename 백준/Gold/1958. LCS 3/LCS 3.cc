#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string str1, str2, str3;
int cache[105][105][105];

int solve(int idx1, int idx2, int idx3)
{
    if (idx1 == str1.size() || idx2 == str2.size() || idx3 == str3.size())
        return 0;
    int &ret = cache[idx1][idx2][idx3];
    if (ret != -1)
        return ret;
    ret = 0;
    if (str1[idx1] == str2[idx2] && str2[idx2] == str3[idx3])
        ret = max(ret, 1 + solve(idx1 + 1, idx2 + 1, idx3 + 1));
    ret = max(ret, solve(idx1 + 1, idx2, idx3));
    ret = max(ret, solve(idx1, idx2 + 1, idx3));
    ret = max(ret, solve(idx1, idx2, idx3 + 1));
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> str1 >> str2 >> str3;
    int ret = solve(0, 0, 0);
    cout << ret;
    return 0;
}