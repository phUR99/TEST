#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll MOD = 1000000007;
ll cache[105][105][105];
int N, L, R;

int main(){
    fastio;
    cin >> N >> L >> R;
    cache[1][1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int l = 1; l <= L; l++)
        {
            for (int r = 1; r <= R; r++)
            {
                cache[i][l][r] = cache[i-1][l][r] *(i - 2) + cache[i-1][l-1][r] + cache[i-1][l][r-1];
                cache[i][l][r] %= MOD;
            }
            
        }
        
    }
    cout << cache[N][L][R];

    return 0;
}