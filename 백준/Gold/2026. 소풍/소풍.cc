#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k, f;
bool isFriend[905][905];
int cnt[905];
bool isNotFriend(vector<int> &arr, int i)
{
    for (auto e : arr)
    {
        if (!isFriend[e][i])
            return true;
    }
    return false;
}

void solve(vector<int> &arr, int idx, int remain)
{

    if (remain == 0)
    {
        for (auto e : arr)
        {
            cout << e << '\n';
        }
        exit(0);
    }

    for (int i = idx + 1; i <= n; i++)
    {
        if (cnt[i] < k - 1)
            continue;
        if (arr.empty())
        {
            arr.push_back(i);
            solve(arr, i, remain - 1);
            arr.pop_back();
        }
        else
        {
            if (isNotFriend(arr, i))
                continue;
            arr.push_back(i);
            solve(arr, i, remain - 1);
            arr.pop_back();
        }
    }
}

int main()
{
    fastio;
    cin >> k >> n >> f;
    for (int i = 0; i < f; i++)
    {
        int u, v;
        cin >> u >> v;
        isFriend[u][v] = 1;
        isFriend[v][u] = 1;
        cnt[u]++, cnt[v]++;
    }
    vector<int> arr;
    solve(arr, 0, k);
    cout << -1;
    return 0;
}