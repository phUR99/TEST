#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[2505];
bool isPal[2505][2505];
int n;
string str;
void preprocess()
{
    for (int i = 0; i < n; i++)
        isPal[i][i] = true;
    for (int i = 0; i < n - 1; i++)
        isPal[i][i + 1] = (str[i] == str[i + 1]);
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            isPal[i][j] = (str[i] == str[j] && isPal[i + 1][j - 1]);
        }
    }
}
int solve(int idx)
{
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
        if (isPal[idx][i])
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
    preprocess();
    int ret = solve(0);
    cout << ret;
    return 0;
}