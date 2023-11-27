#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second

int n, m;
int s[2050];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + m; j++) {
            int temp;
            cin >> temp;
            s[i] -= temp;
            s[j] += temp;
        }
    }
    for (int i = 0; i < n+m; i++)
    {
        cout << s[i] << ' ';
    }
}