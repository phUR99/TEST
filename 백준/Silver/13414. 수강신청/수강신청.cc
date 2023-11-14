#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, l;
    cin >> k >> l;
    unordered_map<string, int> s;
    for (int i = 0; i < l; i++)
    {
        string num;
        cin >> num;

        if (s.find(num) != s.end()) {
            s.erase(num);
            s[num] = i;
        }
        else
        {
            s[num] = i;
        }
    }
    vector<pair<string, int>> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), [](auto& a, auto& b) {return a.second < b.second; });
    int ed = min(k, (int)ans.size());
    for (int i = 0; i < ed; i++)
    {
        cout << ans[i].first << '\n';
    }
    
}