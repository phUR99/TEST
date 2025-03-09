#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
string str;
vector<string> arr;
vector<array<int, 26>> cnt;
int cache[55];

bool check(const array<int, 26> &a, const array<int, 26> &b)
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
int score(const string &a, const string &b)
{
    int ret = 0;
    int l = a.size();
    for (int i = 0; i < l; i++)
    {
        if (a[i] != b[i])
            ret++;
    }
    return ret;
}

int solve(int idx)
{
    if (idx == n)
        return 0;
    int &ret = cache[idx];
    if (ret != -1)
        return ret;
    ret = 987654321;
    string tmp;
    array<int, 26> temp;
    temp.fill(0);
    for (int i = idx; i < n; i++)
    {
        tmp += str[i];
        temp[str[i] - 'a']++;
        for (int j = 0; j < k; j++)
        {
            if (check(temp, cnt[j]))
            {
                ret = min(ret, score(tmp, arr[j]) + solve(i + 1));
            }
        }
    }
    return ret;
}
int main()
{
    fastio;
    cin >> str;
    n = str.size();
    cin >> k;
    memset(cache, -1, sizeof(cache));
    arr.resize(k);
    cnt.resize(k);
    for (int i = 0; i < k; i++)
    {
        cnt[i].fill(0);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        for (auto c : arr[i])
        {
            cnt[i][c - 'a']++;
        }
    }
    int ret = solve(0);
    if (ret == 987654321)
        ret = -1;
    cout << ret;
    return 0;
}