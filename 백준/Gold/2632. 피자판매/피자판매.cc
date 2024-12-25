#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
multiset<int> a, b;
int arr1[1005], arr2[1005];

multiset<int> make(int n, int arr[])
{
    multiset<int> ret;
    int sum = accumulate(arr, arr + n, 0);
    ret.insert(sum);
    ret.insert(0);
    for (int i = 1; i < n; i++)
    {
        int tmp = 0;
        for (int j = i; j < n; j++)
        {
            tmp += arr[j];
            ret.insert(tmp);
            ret.insert(sum - tmp);
        }
    }
    return ret;
}
int main()
{
    fastio;
    int v, n, m;
    cin >> v >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    a = make(n, arr1);
    b = make(m, arr2);
    int ret = 0;
    set<int> used;
    for (auto &i : a)
    {
        if (used.count(i))
            continue;
        ret += b.count(v - i) * a.count(i);
        used.insert(i);
    }
    cout << ret;
    return 0;
}