#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int psum[100050];
long long MOD[100050];
int cache[100050];

int T, N, K;
const int mod = 20091101;
int maxBuys(int k){
    vector<int> ret(N+1, 0);
    vector<int> prev(k, -1);
    // vector<vector<int>> temp(N, vector<int>(K, -1));   
    for (int i = 0; i < N + 1; i++)
    {
        if(i > 0)
            ret[i] = ret[i-1];
        else
            ret[i] = 0;
        int loc = prev[psum[i]];
        if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
        prev[psum[i]] = i;
    }
    return ret.back();

}

int main(){
    fastio;
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        long long A1;
        int A2;

        memset(psum, 0, sizeof(psum));
        memset(MOD, 0, sizeof(MOD));

        MOD[0] = 1;
        A1 = 0;
        for (int i = 1; i <= N; i++)
        {
            int tmp;
            cin >> tmp;
            psum[i] = (psum[i-1] + tmp) % K;
            MOD[psum[i]]++;
        }
        for (int i = 0; i < K; i++)
        {   
            if(MOD[i] < 2) continue;
            A1 = (A1 + (MOD[i]) * (MOD[i] -1)/2) % mod;
        }
        A2 = maxBuys(K);
        cout << A1 << ' ' << A2 << '\n';
        
    }
    

    return 0;
}