 #include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int ans = 0;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 136) ans += 1000;
        else if (a == 142) ans += 5000;
        else if (a == 148) ans += 10000;
        else ans += 50000;

    }
    cout << ans;
}