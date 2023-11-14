#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, string> one;
    unordered_map<string, vector<string>> zero;
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        string team, mem;
        int number;
        cin >> team >> number;
        while (number--)
        {
            cin >> mem;
            one[mem] = team;
            zero[team].push_back(mem);
        }
        sort(zero[team].begin(), zero[team].end());

    }
    int flag;
    while (m--)
    {
        string str;
        cin >> str;
        cin >> flag;
        
        if (flag) {
  
            cout << one[str] << '\n';
        }
        else {

            for (auto e : zero[str])
            {
                cout << e << '\n';
            }
        }
    }
}