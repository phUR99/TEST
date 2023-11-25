#include <bits/stdc++.h>

using namespace std;
#define ll long long

int a[1'000'005];
int h[1'000'005];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(h, h + n, 1e9+1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[idx] < a[i]) {
            idx++;
            h[idx] = a[i];
        }
        else
        {
            auto l = lower_bound(h, h + n, a[i]) - h;
            h[l] = a[i];
        }
    }
    cout << idx +1;
}