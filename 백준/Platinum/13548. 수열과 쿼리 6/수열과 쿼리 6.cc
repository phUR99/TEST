#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int cnt1[100005];
int cnt2[100005];
int k = 500;
int v = 0;

bool cmp(array<int, 3> &a, array<int, 3> &b)
{
    return make_pair(a[0] / k, a[1]) < make_pair(b[0] / k, b[1]);
}

void add(int x, vector<int> &arr)
{
    x = arr[x];
    if (cnt1[x] == v)
        v++;
    cnt2[cnt1[x]]--;
    cnt1[x]++;
    cnt2[cnt1[x]]++;
}
void del(int x, vector<int> &arr)
{
    x = arr[x];
    if (cnt1[x] == v && cnt2[cnt1[x]] == 1)
        v--;
    cnt2[cnt1[x]]--;
    cnt1[x]--;
    cnt2[cnt1[x]]++;
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
    vector<int> ret(m);
    for (int i = 0; i < m; i++)
    {
        cin >> query[i][0] >> query[i][1];
        query[i][2] = i;
    }
    sort(query.begin(), query.end(), cmp);
    int l = 0, r = 0;
    add(0, arr);
    for (auto &c : query)
    {
        c[0]--;
        c[1]--;
        while (r < c[1])
        {
            add(++r, arr);
        }
        while (l > c[0])
        {
            add(--l, arr);
        }
        while (r > c[1])
        {
            del(r--, arr);
        }
        while (l < c[0])
        {
            del(l++, arr);
        }
        ret[c[2]] = v;
    }
    for (auto &i : ret)
    {
        cout << i << '\n';
    }

    return 0;
}
