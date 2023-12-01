#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second

int l[1005], u[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> u[i];
        if (l[i] > u[i]) swap(l[i], u[i]);
    }
    swap(l[0], u[0]);
    if (m > 2 * n) m = 2 * n + m % n;
    while (m--)
    {
        u[n] = u[0];
        for (int i = 1; i <= n; i++)
        {
            u[i - 1] = u[i];
            if (l[i - 1] > u[i - 1]) swap(l[i - 1], u[i - 1]);
        }
        swap(l[0], u[0]);
    }

    swap(l[0], u[0]);
    for (int i = 0; i < n; i++)
    {
        cout << l[i] << ' ' << u[i] << '\n';
    }


}