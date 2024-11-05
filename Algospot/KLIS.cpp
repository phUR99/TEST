#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int arr[505];
int cache1[505];
int cache2[505];
int n, k;
/*
0번째 인덱스를 의미없는 값으로 채우기
*/
int lis(int start)
{
    int &ret = cache1[start];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int nxt = 1 + start; nxt <= n; nxt++)
    {
        if (arr[start] < arr[nxt])
        {
            ret = max(ret, 1 + lis(nxt));
        }
    }
    return ret;
}
int cnt(int start)
{
    if (lis(start) == 1)
        return 1;
    int &ret = cache2[start];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int nxt = start + 1; nxt <= n; nxt++)
    {
        if (arr[start] < arr[nxt] && lis(start) == lis(nxt) + 1)
        {
            ret += cnt(nxt);
        }
    }
    return ret;
}
vector<int> ans;
void trace(int start, int skip)
{
    ans.push_back(arr[start]);
    vector<pair<int, int>> follower;
    for (int nxt = start + 1; nxt <= n; nxt++)
    {
        if (arr[start] < arr[nxt] && lis(start) == lis(nxt) + 1)
        {
            follower.push_back({arr[nxt], nxt});
        }
    }
    sort(follower.begin(), follower.end());
    for (auto node : follower)
    {
        int idx = node.second;
        int num = cnt(idx);
        if (num <= skip)
            skip -= num;
        else
        {
            trace(idx, skip);
            break;
        }
    }
}

void solve()
{
    memset(cache1, -1, sizeof(cache1));
    memset(cache2, -1, sizeof(cache2));
    arr[0] = -100005;
    ans.clear();
    cin >> n >> k;
    k--;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int l = lis(0);
    cnt(0);
    trace(0, k);
    cout << l - 1 << '\n';
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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