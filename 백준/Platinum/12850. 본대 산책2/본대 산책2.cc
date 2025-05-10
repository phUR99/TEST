#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
const vector<vector<ll>> v = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}
};
vector<vector<ll>> operator*(const vector<vector<ll>>& M1, const vector<vector<ll>>& M2) {
    vector<vector<ll>> ret(8, vector<ll>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ll elem = 0;
            for (int k = 0; k < 8; k++) {
                elem = (elem + M1[i][k] * M2[k][j]) % MOD;
            }
            ret[i][j] = elem;
        }
    }
    return ret;
}
vector<vector<ll>> solve(int n){
    if (n == 1) return v;
    if (n & 1)
        return v * solve(n-1);
    else{
        auto ret = solve(n >> 1);
        return ret * ret;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    auto ret = solve(n);
    cout << ret[0][0];
    return 0;
}