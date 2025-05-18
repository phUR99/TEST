#include <bits/stdc++.h>
#define ll long long
#define matrix vector<vector<ll>>
using namespace std;
int n, s, e, t;
matrix arr;
const ll mod = 1e6 + 3;
int SIZE;
matrix operator* (const matrix &a, const matrix &b){
	matrix ret(SIZE + 1, vector<ll>(SIZE + 1, 0));
	for (int i = 1; i <= SIZE; i++) {
		for (int j = 1; j <= SIZE; j++) {
			for (int k = 1; k <= SIZE; k++) {
				ret[i][j] += (a[i][k] * b[k][j]);
				ret[i][j] %= mod;
			}
		}
	}
    return ret;
}

matrix solve(int n){
    if (n == 1) return arr;
    if (n & 1) return arr * solve(n-1);
    matrix half = solve(n/2);
    return half * half;
}


int main(){
    cin >> n >> s >> e >> t;
    SIZE = 5 * n;
    arr.resize(SIZE + 1, vector<ll>(SIZE + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char s;
            cin >> s;
            if(s - '0')
                arr[i * 5][5 * j - (s - '0') + 1] = 1;
        }
        for (int j = 1; j < 5; j++)
        {
            arr[(i - 1) * 5 + j][(i - 1) * 5 + j + 1] = 1;
        }        
    }
    auto ret = solve(t);
    cout << ret[s * 5][e * 5];
    return 0;
    
}