#include <bits/stdc++.h>
using namespace std;

int n;
int cache[1005];


int tiling(int cur){
    if(cur <= 1) return 1;

    int &ret = cache[cur];
    if(ret != -1 ) return ret;

    return ret = (tiling(cur-1) + tiling(cur-2)) %10007;
}

int main(){
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << tiling(n);
    return 0;
}