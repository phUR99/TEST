#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        multiset<int> s;
        while (n--)
        {
            char c;
            int l;
            cin >> c;
            if (c == 'I')
            {
                cin >> l;
                s.insert(l);
            }
            else
            {
                cin >> l;
                if (s.empty()) continue;
                if (l == 1) s.erase(prev(s.end()));
                else s.erase(s.begin());
            }

        }
        if (s.empty()) cout << "EMPTY" << '\n';
        else cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
    }
}