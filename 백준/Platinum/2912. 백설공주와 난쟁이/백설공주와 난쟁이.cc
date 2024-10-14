#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int n, C, m;
int k = 500;

bool cmp(array<int, 3> &a, array<int, 3> &b)
{
    return make_pair(a[0] / k, a[1]) < make_pair(b[0] / k, b[1]);
}
string solve(int k, vector<int> &cnt)
{
    for (int i = 1; i <= C; i++)
    {
        if (cnt[i] > k / 2)
        {
            return "yes " + to_string(i);
        }
    }
    return "no";
}
int main()
{
    fastio;

    cin >> n >> C;
    vector<int> arr(n), cnt(C + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    vector<array<int, 3>> query(m);
    vector<string> ret(m);
    for (int i = 0; i < m; i++)
    {
        cin >> query[i][0] >> query[i][1];
        query[i][2] = i;
    }
    sort(query.begin(), query.end(), cmp);
    int l = 0, r = 0;
    cnt[arr.front()]++;
    for (auto &c : query)
    {
        c[0]--;
        c[1]--;
        while (r < c[1])
            cnt[arr[++r]]++;
        while (l > c[0])
            cnt[arr[--l]]++;
        while (r > c[1])
            cnt[arr[r--]]--;
        while (l < c[0])
            cnt[arr[l++]]--;
        ret[c[2]] = solve((r - l + 1), cnt);
    }
    for (auto i : ret)
    {
        cout << i << '\n';
    }

    return 0;
}
