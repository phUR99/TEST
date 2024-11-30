#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int cache[1005][1005];
string str1, str2;

int solve(int idx1, int idx2)
{

    if (idx1 == str1.size() || idx2 == str2.size())
        return 0;
    int &ret = cache[idx1][idx2];
    if (ret != -1)
        return ret;
    ret = 0;
    if (str1[idx1] == str2[idx2])
        ret = max(ret, solve(idx1 + 1, idx2 + 1) + 1);
    ret = max(ret, solve(idx1 + 1, idx2));
    ret = max(ret, solve(idx1, idx2 + 1));
    return ret;
}
string backTracking(int idx1, int idx2)
{
    if (idx1 == str1.size() || idx2 == str2.size())
        return "";
    if (str1[idx1] == str2[idx2])
        return str1[idx1] + backTracking(idx1 + 1, idx2 + 1);
    if (cache[idx1 + 1][idx2] >= cache[idx1][idx2])
        return backTracking(idx1 + 1, idx2);
    else
        return backTracking(idx1, idx2 + 1);
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> str1 >> str2;
    int ret = solve(0, 0);
    cout << ret << '\n';
    cout << backTracking(0, 0);
    return 0;
}