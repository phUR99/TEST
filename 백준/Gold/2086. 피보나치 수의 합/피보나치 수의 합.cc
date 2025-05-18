#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> arr = {
    {1, 1},
    {1, 0}
};
const ll mod = 1e9;

vector<vector<ll>> operator*(const vector<vector<ll>> &a, const vector<vector<ll>> &b){
    vector<vector<ll>> ret(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ll tmp = 0;
            for (int k = 0; k < 2; k++)
            {
                tmp = (tmp + a[i][k] * b[k][j]) % mod;
            }
            ret[i][j] = tmp;
        }
        
    }
    return ret;   
}
vector<vector<ll>> solve(ll n){
    if (n == 1) return arr;
    if (n & 1)
        return arr * solve(n-1);
    auto half = solve(n/2);
    return half * half; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a, b;
    cin >> a >> b;
    auto retb = solve(b);
    auto reta = solve(a);
    cout << (retb[0][0] + retb[0][1] - reta[1][0] - reta[1][1] + mod) % mod;

    return 0;
}