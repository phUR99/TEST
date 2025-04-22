#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
double up, down, side;
double cache[1050][1050];
/*
현재 trial번 만큼의 시도가 남아있고, 
*/
double caching(int trial, int right){
    if(trial == 0) return right;
    double &ret = cache[trial][right];
    if(ret != -1.0) return ret;
    ret = 0;
    if(up > 0)
        ret += up * caching(trial - 1 , right + 1) - up;
    if(down > 0)
        ret += down * caching(trial - 1 , max(0, right - 1)) + down;
    if(side > 0)
        ret += side * caching(trial - 1, right);
    return ret; 
}


void solve(){
    cin >> n >> up >> down;
    side = 1.0 - up - down;
    for (int i = 0; i <= 1000; ++i)
        for (int j = 0; j <= 1000; ++j)
            cache[i][j] = -1.0;

    double res = caching(n, 0);
    cout.precision(4);
    cout << fixed;
    cout << res << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}