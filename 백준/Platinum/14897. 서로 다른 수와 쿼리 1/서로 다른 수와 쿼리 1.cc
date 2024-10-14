#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
int n, q;
int k = 1000;

bool cmp(array<int, 3> &a, array<int, 3> &b)
{
    return make_pair(a[0] / k, a[1]) < make_pair(b[0] / k, b[1]);
}
int cnt[1000005];
vector<int> dict;

int main()
{
    fastio;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dict.push_back(arr[i]);
    }
    sort(dict.begin(), dict.end());
    dict.erase(unique(dict.begin(), dict.end()), dict.end());
    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(dict.begin(), dict.end(), arr[i]) - dict.begin();
    }

    cin >> q;
    vector<array<int, 3>> query(q);
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        cin >> query[i][0] >> query[i][1];
        query[i][2] = i;
    }
    sort(query.begin(), query.end(), cmp);
    int l = 0, r = 0;
    cnt[arr.front()]++;
    int ret = 1;

    for (auto &c : query)
    {
        c[0]--;
        c[1]--;
        while (r < c[1])
        {
            r++;
            if (cnt[arr[r]] == 0)
                ret++;
            cnt[arr[r]]++;
        }
        while (l > c[0])
        {
            l--;
            if (cnt[arr[l]] == 0)
                ret++;
            cnt[arr[l]]++;
        }
        while (r > c[1])
        {
            if (cnt[arr[r]] == 1)
                ret--;
            cnt[arr[r]]--;
            r--;
        }
        while (l < c[0])
        {
            if (cnt[arr[l]] == 1)
                ret--;
            cnt[arr[l]]--;
            l++;
        }
        ans[c[2]] = ret;
    }
    for (auto i : ans)
    {
        cout << i << '\n';
    }

    return 0;
}
