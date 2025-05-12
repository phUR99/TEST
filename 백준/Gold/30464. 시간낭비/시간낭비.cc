#include <bits/stdc++.h>
using namespace std;
int n;
int arr[200005];
int cache[200005][3];

int solve(int idx, int trial){
    if(idx >= n || idx < 0) return -987654321;
    if(idx == n -1) return 0;
    int &ret = cache[idx][trial];
    if (ret != -1) return ret;
    int dir = (trial & 1) ? -1 : 1;
    ret = -987654321;
    ret = max(ret, 1 + solve(idx + dir * arr[idx], trial));
    if (trial)
        ret = max(ret, 1 + solve(idx + -1 * dir * arr[idx], trial - 1));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = solve(0, 2);
    if (ret < 0)
        ret = -1;
    cout << ret;
    return 0;
}