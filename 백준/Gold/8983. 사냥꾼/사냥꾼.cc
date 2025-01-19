#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int m, n, l;
int prefix[100005];
vector<int> sections;
int main()
{
    fastio;
    cin >> m >> n >> l;
    sections.resize(m);
    for (auto &i : sections)
    {
        cin >> i;
    }
    sort(sections.begin(), sections.end());
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int diff = l - y;
        int cnt = upper_bound(sections.begin(), sections.end(), x + diff) - lower_bound(sections.begin(), sections.end(), x - diff);
        // cout << x + diff << ' ' << x - diff << ' ' << cnt << '\n';
        if (cnt > 0)
            ret++;
    }
    cout << ret;

    return 0;
}