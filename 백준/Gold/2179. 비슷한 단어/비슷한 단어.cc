#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<string> arr;
int solve(string &a, string &b)
{
    int l = min(a.size(), b.size());
    for (int i = 0; i < l; i++)
    {
        if (a[i] != b[i])
            return i;
    }
    return l;
}

int main()
{
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = 0;
    string s, t;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                continue;
            if (ret < solve(arr[i], arr[j]))
            {
                s = arr[i];
                t = arr[j];
                ret = solve(arr[i], arr[j]);
            }
        }
    }
    cout << s << '\n'
         << t << '\n';

    fastio;
    return 0;
}