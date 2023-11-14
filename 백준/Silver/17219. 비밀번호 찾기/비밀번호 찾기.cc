#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, string> s;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        string site, password;
        cin >> site >> password;
        s[site] = password;
    }
    while (n--)
    {
        string site;
        cin >> site;
        cout << s[site] << '\n';
    }
    
}