#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int k = 1000;
int cnt[1000005];

bool cmp(array<int, 3> &a, array<int, 3> &b)
{
    return make_pair(a[0] / k, a[1]) < make_pair(b[0] / k, b[1]);
}

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    int m;
    cin >> m;
    vector<array<int, 3>> query(m);
    for (int i = 0; i < m; i++)
    {
        cin >> query[i][0] >> query[i][1];
        query[i][2] = i;
    }
    sort(query.begin(), query.end(), cmp);
    int ans = 0;
    cnt[arr.front()]++;
    int l = 0, r = 0;
    ans++;
    vector<int> ret(m);
    for (auto &c : query)
    {
        c[0]--;
        c[1]--;
        while (r < c[1])
        {
            if (cnt[arr[++r]] == 0)
                ans++;
            cnt[arr[r]]++;
        }
        while (l > c[0])
        {
            if (cnt[arr[--l]] == 0)
                ans++;
            cnt[arr[l]]++;
        }
        while (r > c[1])
        {
            cnt[arr[r]]--;
            if (cnt[arr[r]] == 0)
                ans--;
            r--;
        }
        while (l < c[0])
        {
            cnt[arr[l]]--;
            if (cnt[arr[l]] == 0)
                ans--;
            l++;
        }
        ret[c[2]] = ans;
    }
    for (auto &i : ret)
    {
        cout << i << '\n';
    }

    return 0;
}
