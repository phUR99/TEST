#include <bits/stdc++.h>

using namespace std;
#define ll long long
int a[5'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << a[k-1];
}