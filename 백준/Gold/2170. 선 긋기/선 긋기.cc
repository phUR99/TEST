#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> line;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int st, ed;
        cin >> st >> ed;
        line.push_back({ st, ed });
    }
    sort(line.begin(), line.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int st = line[i].first;
        int ed = line[i].second;
        while (i + 1 < n)
        {   
            if (line[i + 1].first > ed) break;
            i++;           
            ed = max(ed, line[i].second);
        }
        ans += ed - st;
    }
    cout << ans;

}