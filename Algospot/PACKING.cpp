#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int volume[105];
int wanted[105];
int cache[105][1005];
int n, w;
int maxWanted(int idx, int remain)
{
    if (idx == n)
        return 0;
    int &ret = cache[idx][remain];
    if (ret != -1)
        return ret;
    ret = 0;
    if (remain >= volume[idx])
        ret = max(ret, wanted[idx] + maxWanted(idx + 1, remain - volume[idx]));
    return ret = max(ret, maxWanted(idx + 1, remain));
}
map<int, string> name;
vector<string> item;
void findItem(int idx, int remain)
{
    if (idx == n)
        return;
    if (cache[idx][remain] == cache[idx + 1][remain - volume[idx]] + wanted[idx])
    {
        item.push_back(name[idx]);
        findItem(idx + 1, remain - volume[idx]);
    }
    else
        findItem(idx + 1, remain);
}

void solve()
{
    cin >> n >> w;
    memset(cache, -1, sizeof(cache));
    item.clear();
    name.clear();

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str >> volume[i] >> wanted[i];
        name[i] = str;
    }
    int ret = maxWanted(0, w);
    findItem(0, w);
    cout << ret << ' ' << item.size() << '\n';
    for (auto &i : item)
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