#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int n, d, k, c;
int sushi[33005];
int curMenu[3005];

int main(){
    fastio;
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> sushi[i];
    }
    for (int i = n; i < n + k; i++)
    {
        sushi[i] = sushi[i - n];
    }
    curMenu[c]++;
    int cur = 1;
    
    for (int i = 0; i < k; i++)
    {
        if(!curMenu[sushi[i]]) cur++;
        curMenu[sushi[i]]++;                    
    }
    int ans = cur;
    for (int ed = k; ed < n + k; ed++)
    {
        int st = ed - k;        
        if(!curMenu[sushi[ed]]) cur++;
        curMenu[sushi[ed]]++;
        curMenu[sushi[st]]--;
        if(!curMenu[sushi[st]]) cur--;
        ans = max(cur, ans);
    }
    cout << ans;
    

    return 0;
}