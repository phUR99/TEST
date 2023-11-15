#include <bits/stdc++.h>

using namespace std;
#define ll long long
unordered_map<ll, ll> m;

ll n, p, q;
ll solve(ll n) {
    if (n == 0) return 1;
    if (m.find(n) != m.end()) return m[n];

    m[n] = solve(n / p) + solve(n / q);
    return m[n];
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> p >> q;
    cout << solve(n);

	

}