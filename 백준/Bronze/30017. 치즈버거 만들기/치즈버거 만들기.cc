 #include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int ans = 1;
    a--;
    while (true)
    {
        if (a <= 0 || b <= 0) break;
        a--;
        b--;
        ans += 2;
    }
    cout << ans;
}