#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_set<string> s;
    string str;
    cin >> str;
    int len = (int)str.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j+i <= len; j++)
        {
            if (s.find(str.substr(i, j)) != s.end()) continue;
            s.insert(str.substr(i, j));
        }
    }

    cout << (int)s.size();

}