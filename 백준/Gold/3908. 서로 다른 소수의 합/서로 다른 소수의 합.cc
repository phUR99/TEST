#include <bits/stdc++.h>
using namespace std;


int isP[1150];
vector<int> P;
void precalc(){
    fill(isP, isP+1150, 1);
    isP[0] = 0;
    isP[1] = 0;
    for (int i = 0; i <= 1120; i++)
    {
        if (isP[i])
        {
            for (int j = i*i; j <= 1120; j+=i)
            {
                isP[j] = 0;
            }
            
        }
    }
    for (int i = 0; i <= 1120; i++)
    {
        if (isP[i])
            P.push_back(i);
    }
}
int cache[200][1150][20];
int solve(int idx, int w, int r){
    if (idx == P.size())
        return !w && !r;
    int &ret = cache[idx][w][r];
    if (ret != -1)
        return ret;
    
    ret = solve(idx+1, w, r);
    if (w - P[idx] >= 0 && r)
        ret += solve(idx+1, w-P[idx], r-1);
    return ret;    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    precalc();
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        memset(cache, -1, sizeof(cache));
        cout << solve(0, n, k) << '\n';
    }
    

    return 0;
}