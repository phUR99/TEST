#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int building[100005];
int N, K, S;

int main(){
    fastio;
    cin >> N >> K >> S;
    int left = 100005, right = -1;

    int idx, people;
    int l, r;

    for (int i = 0; i < N; i++)
    {
        cin >> idx >> people;
        building[idx] = people;
        left = min(idx, left);
        right = max(idx, right);
    }
    l = left;
    r = right; 
    int cnt = 0;
    int ans = 0;
    for (int i = left; i < S; i++)
    {
        if(building[i] == 0) continue;  
        //cout << cnt << ' ';
        if(cnt == 0){
            ans += (building[i] / K) * 2 *(S - i);
            if(building[i] % K != 0){
                cnt = building[i] % K;
                l = i;
            }
        }
        else{
            if(building[i] + cnt < K){
                cnt += building[i];
            }
            else{
                building[i] -= K - cnt;
                ans += 2 * (S-l);
                ans += (building[i] / K) * 2 *(S - i);
                cnt = 0;
                if(building[i] % K != 0){
                    cnt = building[i] % K;
                    l = i;
                }
            }
        }
    }
    if(cnt != 0) ans += 2 * (S - l);
    cnt = 0;
    for (int i = right; i > S; i--)
    {
        if(building[i] == 0) continue; 
        //cout << ans << '\n';
        if(cnt == 0){
            ans += (building[i] / K) * 2 *(i - S);
            if(building[i] % K != 0){
                cnt = building[i] % K;
                r = i;
            }
        }
        else{
            if(building[i] + cnt < K){
                cnt += building[i];
            }
            else{
                building[i] -= K - cnt;
                ans += 2 * (r-S);
                ans += (building[i] / K) * 2 * (i - S);
                cnt = 0;
                if(building[i] % K != 0){
                    cnt = building[i] % K;
                    r = i;
                }
            }
        }
    }
    if(cnt != 0) ans += 2 * (r - S);
    cout << ans;


    return 0;
}