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

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> str1 >> str2;
    int ret = solve(0, 0);
    cout << ret << '\n';
    return 0;
}