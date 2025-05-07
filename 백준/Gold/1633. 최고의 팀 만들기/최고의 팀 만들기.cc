#include <bits/stdc++.h>
using namespace  std;
int cache[1005][16][16];
vector<array<int, 2>> arr;
int n;
int solve(int idx, int w, int b){
    if (idx == n)
        return (w == 15 && b == 15 ? 0 : -987654321);
    int &ret = cache[idx][w][b];
    if(ret != -1) return ret;
    ret = 0;
    ret = solve(idx + 1, w, b);
    if (w < 15)
        ret = max(ret, solve(idx + 1, w + 1, b) + arr[idx][0]);
    if (b < 15)
        ret = max(ret, solve(idx + 1, w, b + 1) + arr[idx][1]);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1 ,sizeof(cache));
    
    int a, b;
    while (cin >> a >> b)
    {
        arr.push_back({a, b});
    }
    n = arr.size();
    cout << solve(0, 0, 0);
    

    return 0;
}
