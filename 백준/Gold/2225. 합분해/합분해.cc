#include <bits/stdc++.h>
using namespace std;
int N, K;
int cache[205][205];


int calculateNumber(int n, int k){
    if(n == 0 && k == 0) return 1;
    else if (n < 0) return 0;
    else if (k == 0) return 0;

    int &ret = cache[n][k];
    if(ret != -1) return ret;
    ret = 0;
    for (int i = 0; i <= n; i++)
    {
        ret += calculateNumber(n-i, k-1);
        ret %= 1'000'000'000;
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    memset(cache, -1, sizeof(cache));

    cout << calculateNumber(N, K);

    return 0;
}