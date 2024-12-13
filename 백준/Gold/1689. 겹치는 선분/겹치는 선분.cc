#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;

int main()
{
    fastio;
    cin >> n;
    vector<pair<int, int>> arr;
    while (n--)
    {
        int start, end;
        cin >> start >> end;
        arr.push_back({start, 1});
        arr.push_back({end, -1});
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int ret = 0;
    for (auto &i : arr)
    {
        cnt += i.second;
        ret = max(cnt, ret);
    }
    cout << ret;
    return 0;
}