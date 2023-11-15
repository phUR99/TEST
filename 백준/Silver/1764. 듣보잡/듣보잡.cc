#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_set<string> s, ans;
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        string temp;
        cin >> temp;
        s.insert(temp);
    }
    while (m--)
    {
        string temp;
        cin >> temp;
        if (s.find(temp) != s.end()) ans.insert(temp);
    }
    vector<string> answ(ans.begin(), ans.end());
    sort(answ.begin(), answ.end());
    cout << (int)ans.size() << '\n';
    for (auto e : answ)
    {
        cout << e << '\n';
    }

}